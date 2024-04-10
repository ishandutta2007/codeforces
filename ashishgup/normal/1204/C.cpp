#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;
const int M = 1e6 + 5;

int n, m;
char a[N][N];
int dist[N][N];
int p[M];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			dist[i][j] = 1e9;
			cin >> a[i][j];
			if((a[i][j] == '1'))
				dist[i][j] = 1;
			if(i == j)
				dist[i][j] = 0;
		}
	}
	cin >> m;
	for(int i = 1; i <= m; i++)
		cin >> p[i];
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	vector<int> v;
	v.push_back(1);
	for(int i = 2; i <= m; i++)
	{
		int shouldBe = i - v.back();
		int is = dist[p[v.back()]][p[i]];
		if(is < shouldBe)
			v.push_back(i - 1);
	}
	v.push_back(m);
	cout << v.size() << endl;
	for(auto &it:v)
		cout << p[it] << " ";
	return 0;
}