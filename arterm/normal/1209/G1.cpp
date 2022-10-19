#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;
const int inf = 1e9;

int n;
int q;
int l[M], r[M];
int s[M];
int sz[M];
int a[M];

void read() {
  cin >> n >> q;
  fill(l, l + M, inf);
  fill(r, r + M, -inf);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    l[x] = min(l[x], i);
    r[x] = max(r[x], i);
    sz[x]++;
    a[i] = x;
  }
}

void kill() {
  for (int i = 0; i < M; ++i) {
    if (l[i] <= r[i]) {
      s[l[i]]++;
      s[r[i]]--;
    }
  }

  for (int i = 1; i < n; ++i)
    s[i] += s[i - 1];

  //for (int i = 0; i < n; ++i)
    //cerr << s[i] << " ";
  //cerr << "\n";
  
  int ans = n;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && s[j] != 0)
      ++j;

    //cerr << i + 1 << " " << j + 1 << "\n";

    int cur = 0;
    for (int k = i; k <= j; ++k)
      cur = max(cur, sz[a[k]]);

    ans -= cur;
    
    i = j + 1;
  }

  cout << ans << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("g.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}