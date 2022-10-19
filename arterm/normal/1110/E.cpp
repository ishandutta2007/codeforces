#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;

int n;
int a[M], b[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i) 
    cin >> b[i];
}

void kill() {
  vector<int> A, B;
  for (int i = 0; i + 1 < n; ++i) {
    A.push_back(a[i + 1] - a[i]);
    B.push_back(b[i + 1] - b[i]);
  }
  sort(all(A));
  sort(all(B));

  bool ok = true;
  ok &= a[0] == b[0];
  ok &= a[n - 1] == b[n - 1];
  for (int i = 0; i < n - 1; ++i)
    ok &= A[i] == B[i];

  cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);


  read();
  kill();
}