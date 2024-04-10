#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  const int M = 1000;

  string t;
  cin >> t;

  vector<int> s(M);

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;

    int cur = t[i] == '1';

    for (int j = 0; j < b; ++j)
      s[j] += cur;
    
    for (int j = b; j < M; j += a) {
      cur = 1 - cur;
      for (int k = j; k < M && k < j + a; ++k)
        s[k] += cur;
    }
  }

  cout << *max_element(all(s)) << "\n";
}