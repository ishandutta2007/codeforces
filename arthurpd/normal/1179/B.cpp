#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ", "; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.first << ", " << P.second << ")";
}

#define LOCAL 

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<pii> v;
	vector<pii> ans;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			v.push_back({i,j});

	for (int i = 0; i <= (int) v.size() - 1 - i; i++)
	{
		ans.push_back(v[i]);
		if (i != (int) v.size() - 1 - i)
			ans.push_back(v[(int) v.size() - 1 - i]);
	}

	set<pii> diffs;
	for (int i = 0; i + 1 < ans.size(); i++)
		diffs.insert({ans[i + 1].first - ans[i].first, ans[i + 1].second - ans[i].second});

	// debug(n * m - 1);
	// debug(diffs.size());

	// debug(ans);

	for (int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
}