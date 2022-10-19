#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int M = 100100;
const ld eps = 1e-9;

int n;
ld x[M], y[M];

ld mread() {
    double x;
    scanf("%lf", &x);
    return x;
}

void read() {
//   cin >> n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
      x[i] = mread();
//     cin >> x[i];
  }
  for (int i = 0; i < n; ++i) {
      y[i] = mread();
//     cin >> y[i];
  }
}

void solve(ld B, ld C, ld &a, ld &b) {
  ld D = B * B - 4 * C;
// #ifndef LOCAL
//   assert(D >= -eps);
// #endif

  ld r = sqrt(fabsl(D));
  a = (B - r) / 2;
  b = (B + r) / 2;
}


void kill() {
  for (int i = 1; i <= n; ++i)
    x[i] += x[i - 1];

  for (int j = n - 2; j >= 0; --j)
    y[j] += y[j + 1];

  vector<ld> aans = {0}, bans = {0};

  for (int i = 0; i < n; ++i) {
    ld X = x[i];
    ld Y = y[i + 1];
    //cerr << X << " " << Y << "\n";
    ld B = 1 - Y + X;
    ld C = X;

    ld a, b;
    solve(B, C, a, b);

    aans.push_back(a);
    bans.push_back(b);
  }

  for (int i = 0; i < n; ++i)
      printf("%.10lf ", double(aans[i+1] - aans[i]));
  printf("\n");
//     cout << aans[i + 1] - aans[i] << " ";
//   cout << endl;

  for (int i = 0; i < n; ++i)
      printf("%.10lf ", double(bans[i+1] - bans[i]));
  printf("\n");
//     cout << bans[i + 1] - bans[i] << " ";
//   cout << endl;
}

int main() {
// #ifdef LOCAL
//     freopen("d.in", "r", stdin);
//     freopen("d.out", "w", stdout);
// #endif
//   cout.precision(13);
//   cout << fixed;
//   ios_base::sync_with_stdio(false);
  read();
  kill();

#ifdef LOCAL
    cerr << "Time: " << clock()/1000 << " ms" << endl;
#endif
}