#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (5050)

ll n;
pair <pair<ll,ll>,ll> a[N];
vector <ll> ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].first.first>>a[i].first.second,a[i].second=i+1;
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		bool mark=1;
		for(int j=0;j<n;j++)
			if(j!=i)
			{
				ll p=j+1;
				if(p==i)p++;
				if(p==n)break;
				if(a[j].first.second>a[p].first.first)
				{
					mark=0;
					break;
				}
			}
		if(mark)ans.push_back(a[i].second);	
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
	return 0;
}