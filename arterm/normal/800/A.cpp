#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;
const int ITER = 80;

int n, a[M], b[M], p;

void read() {
    cin >> n;
    cin >> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
}

void kill() {
    ll sa = 0;
    ll sb = 0;
    for (int i = 0; i < n; ++i) {
        sa += a[i];
        sb += b[i];
    }

    if (sa <= p) {
        cout << "-1\n";
        return ;
    }

    ld l = 0, r = 1e12;
    for (int i = 0; i < ITER; ++i) {
        ld t = (l + r) / 2;
        ld sum = 0;
        for (int i = 0; i < n; ++i)
            sum += max<ld>(0, a[i] * t - b[i]);
        if (sum <= p * t)
            l = t;
        else
            r = t;
    }
    cout.precision(10);
    cout << fixed;
    cout << l << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}