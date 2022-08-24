#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> x(n), y(n), z(n);
  map <int, vector <int> > st;
  map <pair <int, int>, vector <int> > orz;
  queue <pair <int, int> > q;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
    //st[x[i]].push_back(y[i]);
    orz[{x[i], y[i]}].push_back(i);
    q.push({x[i], y[i]});
    q.push({x[i], -1});
  }
  vector <bool> u(n);
  for (auto c : orz) {
    if (c.second.size() > 1) {
      sort(c.second.begin(), c.second.end(), [&] (int i, int j) {
        return z[i] < z[j];
      });
      for (int i = 0; i + 1 < c.second.size(); i += 2) {
        cout << c.second[i] + 1 << ' ' << c.second[i + 1] + 1 << '\n';
        u[c.second[i]] = u[c.second[i + 1]] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!u[i]) {
      st[x[i]].push_back(i);
    }
  }
  for (auto c : st) {
    if (c.second.size() > 1) {
      sort(c.second.begin(), c.second.end(), [&] (int i, int j) {
        return y[i] < y[j];
      });
      for (int i = 0; i + 1 < c.second.size(); i += 2) {
        cout << c.second[i] + 1 << ' ' << c.second[i + 1] + 1 << '\n';
        u[c.second[i]] = u[c.second[i + 1]] = true;
      }
    }
  }
  vector <int> ord;
  for (int i = 0; i < n; i++) {
    if (!u[i]) {
      ord.push_back(i);
    }
  }
  sort(ord.begin(), ord.end(), [&] (int i, int j) {
    return x[i] < x[j];
  });
  for (int i = 0; i < (int) ord.size(); i += 2) {
    cout << ord[i] +1  << ' ' << ord[i +1 ] + 1 << '\n';
  }
}