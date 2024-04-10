#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const int MAXN=5005,MAXM=20005;

int n,m,glo;
vector<int> v[MAXN];
int res[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d",&x,&y);
    	v[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
    	if(!v[i].size())continue;
    	int ans=n;
    	for(int j=0;j<v[i].size();j++)
    		ans=min(ans,(v[i][j]+n-i)%n);
    	for(int j=1;j<=n;j++)
    		res[j]=max(res[j],(int)((v[i].size()-1)*n+(i+n-j)%n+ans));
    }
    for(int i=1;i<=n;i++)cout<<res[i]<<" ";
    return 0;
}