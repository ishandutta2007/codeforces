#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 2e5 + 5;

int n, q;
int ct = 0, ctSame = 0;
set<pair<int, int> > edges;
set<pair<int, int> > colEdges[256];

int32_t main()
{
	IOS;
	cin >> n >> q;
	map<pair<int, int>, char> m;
	while(q--)
	{
		char type;
		cin >> type;
		if(type == '+')
		{
			int u, v;
			char c;
			cin >> u >> v >> c;
			edges.insert({u, v});
			m[{u, v}] = c;
			if(edges.find({v, u}) != edges.end())
				ct++;
			colEdges[c].insert({u, v});
			if(colEdges[c].find({v, u}) != colEdges[c].end())
				ctSame++;
		}
		else if(type == '-')
		{
			int u, v;
			cin >> u >> v;
			char c = m[{u, v}];
			if(edges.find({v, u}) != edges.end())
				ct--;
			edges.erase({u, v});
			if(colEdges[c].find({v, u}) != colEdges[c].end())
				ctSame--;
			colEdges[c].erase({u, v});
		}
		else
		{
			int k;
			cin >> k;
			if(k % 2 == 0)
			{
				if(ctSame)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
			else
			{
				if(ct)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
		}
	}
	return 0;
}