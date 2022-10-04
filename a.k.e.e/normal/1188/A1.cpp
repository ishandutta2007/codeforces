#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,deg[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
    	scanf("%d%d",&u,&v);
    	++deg[u];++deg[v];
    }
    for(int i=1;i<=n;i++)
    	if(deg[i]==2)return 0*printf("NO\n");
    printf("YES\n");
    return 0;
}