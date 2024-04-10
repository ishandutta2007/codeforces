#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=200005;

int n,m,k;
ll ta,tb,a[MAXN],b[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>m>>ta>>tb>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    if(k>=n || k>=m)return 0*printf("-1\n");
    int cur=1;
    ll ans=0;
    for(int i=0;i<=k;i++)
    {
    	while(cur<=m && b[cur]<a[i+1]+ta)++cur;
    	if(cur+k-i>m)return 0*printf("-1\n");
    	ans=max(ans,b[cur+k-i]+tb);
    }
    cout<<ans<<endl;
    return 0;
}