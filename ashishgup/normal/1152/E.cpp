#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, ctr = 0;
int a[N], b[N], c[N];
int deg[N], vis[N], in[N], out[N], viscircuit[N];
map<int, int> comp, rcomp;
multiset<int> g[N];
vector<int> circuit;

void EulerTour()
{
	int first = 1;
	while(!deg[first])
		++first;

	int v1 = -1, v2 = -1;
	bool bad = false;
	for(int i = 1; i <= ctr; i++) 
	{
		if (deg[i] & 1) 
		{
			if (v1 == -1)
				v1 = i;
			else if(v2 == -1)
				v2 = i;
			else
				bad = true;
		}
	}
	if (v1 != -1)
	{
		g[v1].insert(v2);
		g[v2].insert(v1);
	}

	stack<int> st;
	st.push(first);
	while(!st.empty()) 
	{
		int v = st.top();
		if(!g[v].size()) 
		{
			circuit.push_back(v);
			st.pop();
		} 
		else 
		{
			auto i = *g[v].begin();
			g[v].erase(g[v].find(i));
			g[i].erase(g[i].find(v));
			st.push(i);
		}
	}

	if (v1 != -1) 
	{
		for (size_t i = 0; i + 1 < circuit.size(); ++i) 
		{
			if ((circuit[i] == v1 && circuit[i + 1] == v2) ||
				(circuit[i] == v2 && circuit[i + 1] == v1)) {
				vector<int> circuit2;
				for (size_t j = i + 1; j < circuit.size(); ++j)
					circuit2.push_back(circuit[j]);
				for (size_t j = 1; j <= i; ++j)
					circuit2.push_back(circuit[j]);
				circuit = circuit2;
				break;
			}
		}
	}

	for (int i = 1; i <= ctr; i++)
	{
		if(g[i].size())
		{
			cout << "-1";
			exit(0);
		}
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	multiset<pair<int, int> > need;
	for(int i = 1; i <= n - 1; i++)
	{
		cin >> b[i];
		comp[b[i]];
	}
	for(int i = 1; i <= n - 1; i++)
	{
		cin >> c[i];
		comp[c[i]];
	}
	for(auto &it:comp)
	{
		it.second = ++ctr;
		rcomp[ctr] = it.first;
	}	
	for(int i = 1; i <= n - 1; i++)
	{
		b[i] = comp[b[i]], c[i] = comp[c[i]];
		need.insert({b[i], c[i]});
	}
	for(int i = 1; i <= n - 1; i++)
	{
		g[b[i]].insert(c[i]);
		g[c[i]].insert(b[i]);
		deg[b[i]]++;
		deg[c[i]]++;
	}
	EulerTour();
	int sz = circuit.size();
	for(int i = 0; i + 1 < sz; i++)
	{
		int a = circuit[i], b = circuit[i + 1];
		pair<int, int> cur = {min(a, b), max(a, b)};
		if(need.find(cur) == need.end())
		{
			cout << "-1";
			exit(0);
		}
		need.erase(need.find(cur));
	}
	for(auto &it:circuit)
		cout << rcomp[it] << " ";
	return 0;
}