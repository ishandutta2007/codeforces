//By Don4ick
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qwer1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

const int N = (int)1e5 + 228;

using namespace std;

int n, u, a[N];

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	//~read
	scanf("%d%d", &n, &u);
	forn(i, n)
	{
		scanf("%d", &a[i]);		
	}
	//~solve
	double ans = 0.0;
	bool found = false;
	int ptr = 1;
	forn(i, n - 2)
	{
		while(ptr < n && a[ptr + 1] - a[i] <= u)		
		{
			ptr++;
		}
		if (ptr > i + 1)
		{
			found = true;
			ans = max(ans, (0.0 + a[ptr] - a[i + 1]) / (0.0 + a[ptr] - a[i]));
		}		
	}
	if (!found)
	{
		cout << -1 << endl;
		return 0;
	}
	printf("%.9f", ans);

	return 0;
}