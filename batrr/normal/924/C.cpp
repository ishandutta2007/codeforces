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

int n, a[N];
set < int > st;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);


	//~read
	scanf("%d", &n);
	int cur = 0;
	ll res = 0;
	forn(i, n)
	{
		scanf("%d", &a[i]);
		st.insert(i);
		while(cur < a[i] + 1)
		{
			int x = *st.rbegin();
			res += i - x;
			st.erase(x);
			cur++;
		}
		res += cur;
	}
	forn(i, n)
		res -= a[i] + 1;
	cout << res << endl; 


	return 0;
}