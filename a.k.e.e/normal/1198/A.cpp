#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=400005;

int n,I,a[MAXN],cnt[MAXN],m;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>I;I*=8;
    int k=I/n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    a[0]=-1;
    for(int i=1;i<=n;i++)
    	if(a[i]>a[i-1])cnt[++m]=1;
    	else ++cnt[m];
    if(k>30 || (1<<k)>=m)k=m;
    else k=1<<k;
    for(int i=1;i<=m;i++)cnt[i]+=cnt[i-1];
    int ans=1<<30;
    for(int i=k;i<=m;i++)ans=min(ans,n-(cnt[i]-cnt[i-k]));
    cout<<ans<<endl;
    return 0;
}