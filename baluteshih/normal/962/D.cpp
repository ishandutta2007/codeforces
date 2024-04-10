#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;

map<ll,set<ll>> mp;
set<ll> s;
vector<pair<ll,ll>> v;

int main()
{jizz
	ll n,i,x,a;
	cin >> n;
	for(i=0;i<n;++i)
	{
		cin >> x;
		mp[x].insert(i);
		if(mp[x].size()>1) s.insert(x);
	}
	while(!s.empty())
	{
		auto p=s.begin();
		auto q=mp[*p].begin();
		a=*q,mp[*p].erase(q);
		q=mp[*p].begin(),a=*q,mp[*p].erase(q);
		mp[(*p)*2].insert(a);
		if(mp[(*p)*2].size()>1) s.insert((*p)*2);
		if(mp[*p].size()<=1) s.erase(*p);
	}
	for(auto p=mp.begin();p!=mp.end();++p)
		if(p->S.size()!=0) v.pb(make_pair(*p->S.begin(),p->F));
	sort(v.begin(),v.end());
	cout << v.size() << "\n";
	for(auto x:v)
		cout << x.S << " ";
	ET;
}