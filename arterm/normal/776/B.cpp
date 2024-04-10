#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 100100;

bool u[M];

void sito() {
  for (int i = 2; i < M; ++i)
    if (!u[i]) {
      for (int j = 2 * i; j < M; j += i)
        u[j] = true;
    }
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  sito();
  int n;
  cin >> n;
  if (n <= 2)
    cout << "1\n";
  else
    cout << "2\n";

  for (int i = 2; i <= n + 1; ++i)
    if (!u[i])
      cout << 1 << " ";
    else
      cout << 2 << " ";
  cout << endl;

}