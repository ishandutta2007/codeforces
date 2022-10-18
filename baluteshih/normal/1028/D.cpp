#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD=1e9+7;
set<ll> tmp;
priority_queue<ll> buy;
priority_queue<ll,vector<ll>,greater<ll>> sell;

int main()
{jizz
	ll n,x,ans=1;
	string s;
	cin >> n;
	while(n--)
	{
		cin >> s >> x;
		if(s[1]=='D')
		{
			if(!buy.empty() && buy.top()>x) buy.push(x);
			else if(!sell.empty() && sell.top()<x) sell.push(x);
			else tmp.insert(x);
		}
		else
		{
			if(tmp.find(x)!=tmp.end())
			{
				if(!buy.empty() && buy.top()>x) 
					return cout << "0\n",0;
				if(!sell.empty() && sell.top()<x)
					return cout << "0\n",0;
				for(auto p=tmp.begin();p!=tmp.end();++p)
					if(*p<x) buy.push(*p);
					else if(*p>x) sell.push(*p);
				tmp.clear();
				ans=ans*2%MOD;
			}
			else if(!buy.empty() && buy.top()==x)
			{
				buy.pop();
				for(auto p=tmp.begin();p!=tmp.end();++p)
					if(*p<x) buy.push(*p);
					else if(*p>x) sell.push(*p);
				tmp.clear();
			}
			else if(!sell.empty() && sell.top()==x)
			{
				sell.pop();
				for(auto p=tmp.begin();p!=tmp.end();++p)
					if(*p<x) buy.push(*p);
					else if(*p>x) sell.push(*p);
				tmp.clear();
			}
			else
				return cout << "0\n",0;
		}
		if(!buy.empty() && !sell.empty() && buy.top()>sell.top())
			return cout << "0\n",0;
	}
	cout << ans*(tmp.size()+1)%MOD << "\n";
}