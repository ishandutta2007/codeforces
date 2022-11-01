#include <iostream>

#include<vector>

using namespace std;

int d[100005];
vector<int> v;
vector<int> u;
vector< pair< int, int> > edges;
int main()
{
	int n, x = 0, y = 0, z = 0, s = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> d[i];
		if(d[i] == 1)
		{
			z ++;
			v.push_back(i);
		}
		else
		{
			x ++;
			y += d[i] - 2;
			u.push_back(i);
		}
		s += d[i];
	}
	if(s < 2 * n - 2)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES" << " ";
		if(z == 0)
		{
			cout << n - 1 << endl << n - 1 << endl;
			for(int i = 1; i < n; i ++)
			{
				cout << i << " " << i + 1 << endl;
			}
		}
		if(z == 1)
		{
			cout << n - 1 << endl << n - 1 << endl;
			for(int i = 1; i < n; i ++)
			{
				if(i != v[0] && i + 1 != v[0])
				{
					cout << i << " " << i + 1 << endl;
				}
			}
			if(v[0] == 1)
			{
				cout << 1 << " " << 2 << endl;
			}
			if(v[0] == n)
			{
				cout << n << " " << 1 << endl;
			}
			if(v[0] != 1 && v[0] != n)
			{
				cout << 1 << " " << v[0] << endl;
				cout << v[0] - 1 << " " << v[0] + 1 << endl;
			}
		}
		if(z >= 2)
		{
			cout << x + 1 << endl;
			int j = 2;
			for(int i = 0; i < u.size(); i ++)
			{
				while(d[u[i]] > 2 && j < v.size())
				{
					edges.push_back({u[i], v[j]});
					j ++;
					d[u[i]] --;
				}
			}
			edges.push_back({v[0], u[0]});
			edges.push_back({v[1], u[u.size() - 1]});
			for(int i = 1; i < u.size(); i ++)
			{
				edges.push_back({u[i - 1], u[i]});
			}
			cout << (int) edges.size() << endl;
			for(int i = 0; i < edges.size(); i ++)
			{
				cout << edges[i].first << " " << edges[i].second << endl;
			}
		}
	}
	return 0;
}