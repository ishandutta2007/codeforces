#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 55;

int n;
string s;
char a[N][N];

void print()
{
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cout << a[i][j];
		cout << endl;
	}
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i == j)
					a[i][j] = 'X';
				else
					a[i][j] = '=';
			}
		}
		vector<int> pos;
		for(int i = 1; i <= n; i++)
		{
			if(s[i - 1] == '2')
				pos.push_back(i);
		}
		if(pos.size() == 1 || pos.size() == 2)
			cout << "NO" << endl;
		else if(!pos.size())
			print();
		else
		{
			for(int i = 0; i < pos.size(); i++)
			{
				int u = pos[i];
				int v = pos[(i + 1) % pos.size()];
				a[u][v] = '+';
				a[v][u] = '-';
			}
			print();
		}
	}
	return 0;
}