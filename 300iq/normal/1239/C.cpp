#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const ll inf = (ll) (1e18) + 7;

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, p;
  cin >> n >> p;
  vector <ll> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  set <pair <ll, int> > q, die;
  for (int i = 0; i < n; i++) {
    q.insert({t[i], i});
  }
  set <int> zeros;
  set <int> waiting;
  ll prev_time = 0;
  vector <ll> ans(n);
  ll last = 0;
  while (true) {
    int i = (zeros.empty() ? n : *zeros.begin());
    vector <pair <ll, int> > cands;
    if (!waiting.empty() && *waiting.begin() < i) {
      cands.push_back({prev_time, *waiting.begin()});
    }
    if (!q.empty()) {
      cands.push_back({q.begin()->first, q.begin()->second});
    }
    if (!die.empty()) {
      cands.push_back({die.begin()->first, -1});
    }
    sort(cands.begin(), cands.end());
    if (cands.empty()) {
      break;
    }
    for (auto c : cands) {
      prev_time = c.first;
      last = max(last, prev_time);
      if (c.second == -1) {
        int pos = die.begin()->second;
        die.erase(die.begin());
        zeros.erase(pos);
        break;
      }
      if (waiting.count(c.second)) {
        ans[c.second] = last + p;
        last += p;
        zeros.insert(c.second);
        die.insert({ans[c.second], c.second});
        waiting.erase(c.second);
        break;
      } else {
        if (c.second < i) {
          ans[c.second] = last + p;
          last += p;
          zeros.insert(c.second);
          q.erase({c.first, c.second});
          die.insert({ans[c.second], c.second});
          break;
        } else {
          q.erase({c.first, c.second});
          waiting.insert(c.second);
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}