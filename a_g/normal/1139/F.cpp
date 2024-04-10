#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
  public:
    vector<T> arr;
    fenwick (int n) {
      arr.resize(n+3);
    }
    void add (int index, T val) {
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] += val;
      }
    }
    T query(int index) {
      T sum = 0;
      for (; index > 0; index -= (index & (-index))) {
        sum += arr[index];
      }
      return sum;
    }
};

struct event {
  int x, y, id;
  bool query;
};

bool operator < (const event& a, const event& b) {
  return make_tuple(a.x, a.query, a.y, a.id) < make_tuple(b.x, b.query, b.y, b.id);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> p(n), s(n), b(n), inc(m), pref(m), ans(m, -n);
  for (int& x: p) cin >> x;
  for (int& x: s) cin >> x;
  for (int& x: b) cin >> x;
  for (int& x: inc) cin >> x;
  for (int& x: pref) cin >> x;

  vector<pair<int, int>> dishes(n), people(m);

  auto calc = [&] () {
    vector<int> all_coords;
    for (int i = 0; i < n; i++) {
      all_coords.emplace_back(dishes[i].second);
    }
    for (int i = 0; i < m; i++) {
      all_coords.emplace_back(people[i].second);
    }
    sort(all_coords.begin(), all_coords.end());
    all_coords.resize(unique(all_coords.begin(), all_coords.end())-all_coords.begin());
    function<int(int)> compress = [&] (int x) {
      return lower_bound(all_coords.begin(), all_coords.end(), x)-all_coords.begin()+1;
    };

    fenwick<int> fenw(all_coords.size()+3);

    vector<event> events;
    for (int i = 0; i < n; i++) {
      events.emplace_back(event{dishes[i].first, compress(dishes[i].second), i, 0});
    }
    for (int i = 0; i < m; i++) {
      events.emplace_back(event{people[i].first, compress(people[i].second), i, 1});
    }
    sort(events.begin(), events.end());
    for (auto& [x, y, id, query]: events) {
      if (!query) fenw.add(y, 1);
      else ans[id] += fenw.query(y);
    }
  };

  // step 1: add if s[i] >= inc[j]
  for (int i = 0; i < n; i++) {
    dishes[i] = make_pair(-s[i], 0);
  }
  for (int j = 0; j < m; j++) {
    people[j] = make_pair(-inc[j], 1);
  }
  calc();

  // step 2: add if inc[j]+pref[j] >= p[i]+b[i] and inc[j]-pref[j] >= p[i]-b[i]
  for (int i = 0; i < n; i++) {
    dishes[i] = make_pair(p[i]+b[i], p[i]-b[i]);
  }
  for (int j = 0; j < m; j++) {
    people[j] = make_pair(inc[j]+pref[j], inc[j]-pref[j]);
  }
  calc();
  
  // step 3: add if inc[j] > s[i] and pref[j]-inc[j] > b[i]-p[i]
  for (int i = 0; i < n; i++) {
    dishes[i] = make_pair(s[i]+1, b[i]-p[i]+1);
  }
  for (int j = 0; j < m; j++) {
    people[j] = make_pair(inc[j], pref[j]-inc[j]);
  }
  calc();

  // step 4: add if inc[j] > s[i] and inc[j]+pref[j] < p[i]+b[i]
  for (int i = 0; i < n; i++) {
    dishes[i] = make_pair(s[i]+1, -(p[i]+b[i])+1);
  }
  for (int j = 0; j < m; j++) {
    people[j] = make_pair(inc[j], -(inc[j]+pref[j]));
  }
  calc();

  /*
  // step 5: remove counts of (s[i], b[i] + (s[i]-p[i])) and (s[i], b[i] - (s[i]-p[i]))
  dishes.clear();
  for (int i = 0; i < n; i++) {
    if (s[i] != p[i]) {
      dishes.emplace_back(s[i], b[i]+(s[i]-p[i]));
      dishes.emplace_back(s[i], b[i]-(s[i]-p[i]));
    }
  }
  sort(dishes.begin(), dishes.end());
  for (int j = 0; j < m; j++) {
    people[j] = make_pair(inc[j], pref[j]);
    ans[j] -= upper_bound(dishes.begin(), dishes.end(), people[j])-lower_bound(dishes.begin(), dishes.end(), people[j]);
  }
  */

  for (int x: ans) cout << x << ' ';
  cout << '\n';
}