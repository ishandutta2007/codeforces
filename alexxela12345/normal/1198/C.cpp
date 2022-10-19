#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define endl '\n'
#endif

typedef long long ll;
typedef long double ldb;

template<typename T1, typename T2>
istream& operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &out, pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}

template<typename T>
istream& operator>>(istream& in, vector<T> &vec) {
  for (auto &el : vec) {
    in >> el;
  }
  return in;
}

template<typename T>
ostream& operator<<(ostream& out, vector<T> &vec) {
  for (auto &el : vec) {
    out << el << " ";
  }
  return out;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef LOCAL
  cout << "Running local" << endl;
#endif
  
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      edges.push_back({u, v});
    }
    vector<int> used(3 * n);
    vector<int> matching;
    for (int i = 0; i < m; i++) {
      if (!used[edges[i].first] && !used[edges[i].second]) {
        used[edges[i].first] = 1;
        used[edges[i].second] = 1;
        matching.push_back(i);
      }
      if (matching.size() == n) {
        break;
      }
    }
    if (matching.size() == n) {
      cout << "Matching" << endl;
      for (int el : matching) {
        cout << el + 1 << " ";
      }
      cout << endl;
    } else {
      cout << "IndSet" << endl;
      int cnt = 0;
      for (int i = 0; i < 3 * n && cnt < n; i++) {
        if (!used[i]) {
          cout << i + 1 << " ";
          cnt++;
        }
      }
      cout << endl;
    }
  }

  return 0;
}