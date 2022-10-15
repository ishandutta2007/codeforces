#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define x first
#define t second 


using namespace std;

const int INF = (int)1e+9;

vector < pair < int, int > > a;
int n;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a.push_back(make_pair(x, 0));
		if (x != y)
			a.push_back(make_pair(y, 1));
	}
	
	int ans = INF;
	
	sort(a.begin(), a.end());
	for (int i = 0, j = 0; i < (int)a.size(); i = j)
	{
		int c = 0;
		while (j < (int)a.size() && a[i].x == a[j].x)
		{
			c += a[j].second == 0;
			j++;
		}
		
		if ((j - i) * 2 < n) continue;
		
		//cout << c << endl;
		
		ans = min(ans, max(0, (n + 1) / 2 - c));		
	}
	if (ans == INF)
		puts("-1");
	else
		printf("%d\n", ans);
		
	return 0;
}