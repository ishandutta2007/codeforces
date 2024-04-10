#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;
const int N = 13;

int n;
int a[M];
int cnt[N];
int c[M];

void read() {
  cin >> n;

  string s;
  cin >> s;
  
  fill(cnt, cnt + N, 0);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
    cnt[a[i]]++;
  }
}

void kill() {
  fill(c, c + n, 2);

  int last = 0;

  for (int i = 0; i < n; ++i) {
    while (last < 9 && cnt[last] == 0)
      ++last;
    assert(a[i] >= last);
    if (a[i] == last) {
      c[i] = 1;
      --cnt[last];
    }
  }

  vector<int> b;
  for (int i = 0; i < n; ++i)
    if (c[i] == 1)
      b.push_back(a[i]);

  for (int i = 0; i < n; ++i)
    if (c[i] == 2)
      b.push_back(a[i]);

  assert(b.size() == n);

  if (is_sorted(all(b))) {
    for (int i = 0; i < n; ++i)
      cout << c[i];
    cout << "\n";
  } else {
    cout << "-\n";
  }
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    read();
    kill();
  }

}