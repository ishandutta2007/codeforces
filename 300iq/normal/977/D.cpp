#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100 + 2;

vector <int> g[N];

int main()
{
	int n;
	cin >> n;
	vector <ll> a(n);
	vector <int> in(n);
	for (int i = 0; i < n; i++)
	{
		 cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		 for (int j = 0; j < n; j++)
		 {
			  if (i != j && a[j] == a[i] * 3)
			  {
				  g[j].push_back(i);
				  in[i]++;
			  }
			  if (i != j && a[j] == a[i] * 2)
			  {
				   g[i].push_back(j);
				   in[j]++;
			  }
		 }
	}
	int x = -1;
	for (int i = 0; i < n; i++)
	{
		 if (in[i] == 0) x = i;
	}
	int pr = -1;
	while (true)
	{
		 cout << a[x] << ' ';
		 if (g[x].empty()) break;
		 x = g[x][0];
	}
}