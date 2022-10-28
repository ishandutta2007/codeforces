#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define mp make_pair
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll> > vvll;
 
#define PI 3.141592653589793
#define MOD 1000000007

int main()
{
	ll n;
	cin>>n;
	vector<list<ll> > nodes(n+1);
	vector<bool> visited(n+1,false);
	for(ll i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		nodes[a].pb(i);
		nodes[i].pb(a);
	}
	ll counttree=0;
	for(ll i=1;i<=n;i++)
	{
		if(visited[i]==true)
		{
			continue;
		}
		counttree++;
		visited[i]=true;
		stack<ll> st;
		st.push(i);
		while(!st.empty())
		{
			ll temp=st.top();
			st.pop();
			list<ll>::iterator it=nodes[temp].begin();
			while(it!=nodes[temp].end())
			{
				if(visited[*it]==true)
				{
					it++;
					continue;
				}
				visited[*it]=true;
				st.push(*it);
				it++;
			}
		}
	}
	cout<<counttree;
	return 0;
}