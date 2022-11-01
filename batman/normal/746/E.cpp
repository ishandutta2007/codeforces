#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,m,a[N],even,odd,ans;
vector <ll> bad,v_even,v_odd,now_even,now_odd;
set <ll> s;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	if(s.count(a[i]))bad.push_back(i),ans++;
    	else
    	{
    		s.insert(a[i]);
    		if(a[i]%2==0)even++,now_even.push_back(i);
    		else odd++,now_odd.push_back(i);
		}
	}
	for(int i=1;i<=min(m,(ll)4e5);i++)
	{
		if(s.count(i))continue;
		if(i%2==0)v_even.push_back(i);
		else v_odd.push_back(i);
	}
	for(auto u:bad)
	{
		if(even<=odd)
		{
			if(!v_even.size())return cout<<-1,0;
			a[u]=v_even.back();
			v_even.pop_back();
			even++;
		}
		else
		{
			if(!v_odd.size())return cout<<-1,0;
			a[u]=v_odd.back();
			v_odd.pop_back();
			odd++;
		}
	}
	while(even<odd)
	{
		if(!now_odd.size() || !v_even.size())return cout<<-1,0;
		a[now_odd.back()]=v_even.back();
		now_odd.pop_back();v_even.pop_back();
		odd--;even++;ans++;
	}
	while(even>odd)
	{
		if(!now_even.size() || !v_odd.size())return cout<<-1,0;
		a[now_even.back()]=v_odd.back();
		now_even.pop_back();v_odd.pop_back();
		even--;odd++;ans++;
	}
	cout<<ans<<"\n";
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}