#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define x first
#define y second
void chkmax(int &x,int y){x<y?x=y:0;}
void chkmin(int &x,int y){x>y?x=y:0;}
const int MAXN=200005;

int n,a[MAXN],res[MAXN];
ll c[MAXN],s[MAXN];
void add(int x,int d){for(;x<=n;x+=(x&-x))c[x]+=d;}
ll query(int x){ll ans=0;for(;x;x-=(x&-x))ans+=c[x];return ans;}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)add(i,i);
    for(int i=n;i>0;i--)
    {
    	int L=1,R=n,mid,ans=0;
    	while(L<=R)
    	{
    		mid=(L+R)>>1;
    		if(query(mid-1)<=s[i])ans=mid,L=mid+1;
    		else R=mid-1;
    	}
    	res[i]=ans;
    	add(ans,-ans);
    }
    for(int i=1;i<=n;i++)
    	printf("%d ",res[i]);
    return 0;
}