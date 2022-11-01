#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (201*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

string s;
ll n,m,p,a[N],num_b;
map <ll,ll> m_b;
vector <ll> ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>p;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)
	{
		ll b;
		cin>>b;
		if(m_b[b]==0)num_b++;
		m_b[b]++;	
	}
	for(int step=0;step<p;step++)
	{
		map <ll,ll> mp;
		queue <ll> q;
		ll ok=0;
		for(int i=step;i<n;i+=p)
		{
			q.push(i);
			mp[a[i]]++;
			if(mp[a[i]]==m_b[a[i]])ok++;
			else if(mp[a[i]]==m_b[a[i]]+1)ok--;
			if(q.size()>m)
			{
				ll x=q.front();q.pop();
				if(mp[a[x]]==m_b[a[x]])ok--;
				mp[a[x]]--;
				if(mp[a[x]]==m_b[a[x]])ok++;
			}
			if(ok==num_b)ans.push_back(q.front()+1);
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}