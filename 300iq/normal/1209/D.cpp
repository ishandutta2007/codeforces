#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 1e5 + 7;

int dsu[N];

int get(int v) {
  if (v == dsu[v]) {
    return v;
  } else {
    return dsu[v] = get(dsu[v]);
  }
}

void uni(int u, int v) {
  dsu[get(u)] = get(v);
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) dsu[i] = i;
  int ans =0; 
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (get(a) != get(b)) {
      uni(a, b);
    } else {
      ans++;
    }
  }
  cout << ans << endl;
}