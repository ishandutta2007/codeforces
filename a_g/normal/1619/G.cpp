#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

class dsu {
  public:
    vector<int> parents;
    vector<int> ranks;
    vector<int> times;
    dsu (int n, vector<int>& t) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      ranks.resize(n, 0);
      times = t;
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      if (ranks[a] > ranks[b]) swap(a, b);
      // b has higher rank
      parents[a] = b;
      times[b] = min(times[a], times[b]);
      if (ranks[a] == ranks[b]) ranks[b]++;
      return 1;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    unordered_map<int, vector<pair<int, int>>, custom_hash> xmines;
    unordered_map<int, vector<pair<int, int>>, custom_hash> ymines;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y >> t[i];
      xmines[x].push_back({y, i});
      ymines[y].push_back({x, i});
    }
    dsu md(n, t);
    for (auto const& p: xmines) {
      vector<pair<int, int>> line = p.second;
      sort(line.begin(), line.end());
      int s = line.size();
      for (int i = 0; i < s-1; i++) {
        if (line[i+1].first-line[i].first <= k) md.join(line[i+1].second, line[i].second);
      }
    }
    for (auto const& p: ymines) {
      vector<pair<int, int>> line = p.second;
      sort(line.begin(), line.end());
      int s = line.size();
      for (int i = 0; i < s-1; i++) {
        if (line[i+1].first-line[i].first <= k) md.join(line[i+1].second, line[i].second);
      }
    }

    vector<int> ctimes;
    for (int i = 0; i < n; i++) {
      if (md.root(i) == i) ctimes.push_back(md.times[md.root(i)]);
    }

    sort(ctimes.begin(), ctimes.end());
    int c = ctimes.size();
    int ans = c-1;
    for (int i = 0; i < c; i++) {
      ans = min(ans, max(c-i-2, ctimes[i]));
    }
    cout << ans << '\n';
  }
}