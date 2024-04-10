#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

typedef pair<int, int> pii;


const int M = 15;
pii a[M], b[M];

int inter(const pii &a, const pii &b) {
  map<int, int> cnt;
  cnt[a.first]++;
  cnt[a.second]++;
  cnt[b.first]++;
  cnt[b.second]++;
  if (cnt.size() == 3)
    for (auto it : cnt)
      if (it.second == 2)
        return it.first;
  return -1;
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  for (int j = 0; j < m; ++j) {
    cin >> b[j].first >> b[j].second;
  }

  set<int> res;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (inter(a[i], b[j]) != -1) {
        res.insert(inter(a[i], b[j]));
      }
  assert(!res.empty());

  if (res.size() == 1u) {
    cout << *res.begin() << endl;
    return 0;
  }


  bool ok = true;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (inter(a[i], b[j]) != -1) {
        set<int> sec;
        set<int> fir;
        for (int k = 0; k < m; ++k)
          sec.insert(inter(a[i], b[k]));
        for (int k = 0; k < n; ++k)
          fir.insert(inter(a[k], b[j]));
        sec.erase(-1);
        fir.erase(-1);
        ok &= fir.size() == 1u && sec.size() == 1u;
      }

  if (ok)
    cout << "0\n";
  else
    cout << "-1\n";
}