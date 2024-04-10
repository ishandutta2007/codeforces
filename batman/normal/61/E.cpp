#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =1001*1000;

ll n,num[N],fen[2][N],ans;
pair <ll,ll> a[N];

void update(ll x,ll num,ll bit){for(;x<=n;x+=x&-x)fen[bit][x]+=num;}
ll query(ll x,ll bit){ll res=0;for(;x>0;x-=x&-x)res+=fen[bit][x];return res;}

int main()
{
   	scanf("%I64d",&n);
   	for(int i=0;i<n;i++)scanf("%I64d",&a[i].first),a[i].second=i+1;
   	sort(a,a+n);
   	for(int i=n-1;i>=0;i--)
   	{
   		ll j=i;
		while(a[j].first==a[j-1].first && j>0)
			num[j]=query(a[j].second,0),ans+=query(a[j].second,1),j--;
		num[j]=query(a[j].second,0),ans+=query(a[j].second,1);
		j=i;
		while(a[j].first==a[j-1].first && j>0)
			update(a[j].second,1,0),update(a[j].second,num[j],1),j--;
		update(a[j].second,1,0),update(a[j].second,num[j],1);
		i=j;
	}
	printf("%I64d\n",ans);
	return 0;
}