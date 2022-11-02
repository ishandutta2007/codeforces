//By Don4ick 
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qewr1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

using namespace std;

void solve()
{
	int n;
	scanf("%d", &n);
	vector < int > c(n);
	vector < int > cnt(n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
		c[i]--;
		cnt[c[i]]++;
	}
	sort(cnt.rbegin(), cnt.rend());
	while(!cnt.empty() && cnt.back() == 0)
		cnt.pop_back();
	int lowest = cnt.back();
	int ans = n;
	for (int s = 2; s <= lowest + 1; s++)
	{
		bool sorry = false;
		int cur = 0;
		for (auto it : cnt)
		{
			if (it / (s - 1) < it % (s - 1))
				sorry = true;
			cur += (it + s - 1) / s;
		}
		if (!sorry)
			ans = min(ans, cur);
	}
	printf("%d\n", ans);
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie();
	//cout.tie();		

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	int T;
	scanf("%d", &T);
	while(T--)
		solve();

	return 0;
}