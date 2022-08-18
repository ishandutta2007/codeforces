#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 5;

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

int lcm (int p, int q) {
  return p * q / gcd(p, q);
}

int main () {
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  if (N == 1 && M == 1) {
    cout << 0 << endl;
    return 0;
  }

  if (N == 1) {
    for (int i = 1; i <= M; i++) {
      cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
  }

  if (M == 1) {
    for (int i = 1; i <= N; i++) {
      cout << i + 1 << '\n';
    }
    return 0;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cout << lcm(i, j + N) << " ";
    }
    cout << '\n';
  }
}