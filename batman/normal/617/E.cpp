#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define K ((ll)3001*1000)
#define SQ ((ll)300)

ll n,m,k,a[N],b[N],cnt[2][K],ans,res[N];
pair <pair<ll,ll>,ll> qu[N];

bool cmp(pair<pair<ll,ll>,ll> x,pair<pair<ll,ll>,ll> y)
{
	if(x.first.first/SQ>y.first.first/SQ)return 1;
	if(x.first.first/SQ<y.first.first/SQ)return 0;
	return x.first.second<y.first.second;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=(a[i]^b[i-1]);
	for(int i=0;i<m;i++)
		cin>>qu[i].first.first>>qu[i].first.second,qu[i].second=i;
	sort(qu,qu+m,cmp);
	ll l2=1,r2=1;cnt[1][b[1]]++;cnt[0][b[0]]++;ans=((b[0]^b[1])==k);
	for(int i=0;i<m;i++)
	{
		ll l=qu[i].first.first,r=qu[i].first.second;
		while(r2<r)
		{
			r2++;
			cnt[0][b[r2-1]]++;
			cnt[1][b[r2]]++;
			ans+=cnt[0][(b[r2]^k)];
		}
		while(l<l2)
		{
			l2--;
			cnt[0][b[l2-1]]++;
			cnt[1][b[l2]]++;
			ans+=cnt[1][(b[l2-1]^k)];
		}
		while(r<r2)
		{
			ans-=cnt[0][(b[r2]^k)];
			cnt[0][b[r2-1]]--;
			cnt[1][b[r2]]--;
			r2--;
		}
		while(l2<l)
		{
			ans-=cnt[1][(b[l2-1]^k)];
			cnt[0][b[l2-1]]--;
			cnt[1][b[l2]]--;
			l2++;
		}
		res[qu[i].second]=ans;
	}
	for(int i=0;i<m;i++)cout<<res[i]<<"\n";
	return 0;
}