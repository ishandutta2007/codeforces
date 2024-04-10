#include <bits/stdc++.h>
using namespace std;

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ", "; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << ", " << P.nd << ")";
}

#define LOCAL 

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

#define MAXN 112345

pair<int,int> ans[2*MAXN];

int main(void)
{
	deque<int> q;
	int n, k, x, mx = -1;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		q.push_back(x);
		if (x > mx) mx = x;
	}

	int cycle_start = -1;
	for (int i = 0; i < 2 * MAXN; i++)
	{
		if (q.front() == mx && cycle_start == -1)
		{
			cycle_start = i;
		}

		int a, b;
		a = q.front();
		q.pop_front();
		b = q.front();
		q.pop_front();

		ans[i] = {a, b};
		if (a > b)
		{
			q.push_front(a);
			q.push_back(b);
		}
		else
		{
			q.push_front(b);
			q.push_back(a);
		}
	}

	for (int i = 0; i < k; i++)
	{
		long long m;
		scanf("%lld", &m);
		m--;

		if (m > cycle_start)
			m = cycle_start + (m - cycle_start) % (n - 1);

		printf("%d %d\n", ans[m].first, ans[m].second);
	}
}