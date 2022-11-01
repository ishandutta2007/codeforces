#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)

ll n,a,b,k,f;
map <pair<string,string>,ll> mp;
vector <ll> v;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>a>>b>>k>>f;
	string lst="...";
	for(int i=0;i<n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		ll cost=a;
		if(s1==lst)cost=b;
		lst=s2;
		if(s1>s2)swap(s1,s2);
		mp[{s1,s2}]+=cost;
	}
	for(auto u:mp)v.push_back(u.second);
	sort(v.begin(),v.end());
	for(int i=(ll)v.size()-1;i>=0 && k>0;i--,k--)
	{
		if(v[i]<=f)break;
		v[i]=f;
	}
	ll ans=0;
	for(auto u:v)ans+=u;
	cout<<ans<<"\n";
	return 0;
}