#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class dsu {
  public:
    vector<int> parents;
    vector<int> ranks;
    vector<int> leader;
    dsu (int n) {
      parents.resize(n);
      leader.resize(n);
      iota(parents.begin(), parents.end(), 0);
      iota(leader.begin(), leader.end(), 0);
      ranks.resize(n, 0);
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
      if (ranks[a] == ranks[b]) ranks[b]++;
      leader[b] = max(leader[a], leader[b]);
      return 1;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n);
  vector<int> b(m);
  vector<pair<int, bool>> allitems(n+m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    allitems[i] = {a[i], 1};
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    allitems[i+n] = {b[i], 0};
  }
  sort(allitems.begin(), allitems.end());

  vector<pair<int, int>> events(n+m-1);
  for (int i = 0; i < n+m-1; i++) {
    events[i] = {allitems[i+1].first-allitems[i].first, i};
  }
  sort(events.begin(), events.end());

  vector<ll> pref(n+m+1);
  pref[0] = 0;
  for (int i = 0; i < n+m; i++) {
    pref[i+1] = pref[i] + allitems[i].first;
  }

  ll currans = 0;
  vector<int> groupsize(n+m);
  vector<ll> groupval(n+m);
  for (int i = 0; i < n+m; i++) {
    if (allitems[i].second) {
      groupsize[i] = 1;
      groupval[i] = allitems[i].first;
      currans += allitems[i].first;
    }
  }

  dsu d(n+m);

  vector<pair<int, int>> queries(q);
  for (int i = 0; i < q; i++) {
    cin >> queries[i].first;
    queries[i].second = i;
  }
  sort(queries.begin(), queries.end());

  int nextevent = 0;
  vector<ll> ans(q);
  for (pair<int, int> query: queries) {
    int k = query.first;
    while (nextevent < n+m-1 && events[nextevent].first <= k) {
      int i = events[nextevent].second;
      int j = d.leader[d.root(i+1)];
      d.join(i, i+1);
      int sz = groupsize[i] + groupsize[j];
      groupsize[j] = sz;
      currans -= groupval[i] + groupval[j];
      groupval[j] = pref[j+1]-pref[j+1-sz];
      currans += groupval[j];
      nextevent++;
    }

    ans[query.second] = currans;
  }
  for (ll val: ans) cout << val << '\n';
}