#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 300;
const int N = 1e5 + 2;

int a[N];

int d[M + 2][N];

void prec(int n) {
    frab(k, 1, M + 1)
        for (int i = n; i >= 1; i--)
            if (i + a[i - 1] + k > n)
                d[k][i] = 1;
            else
                d[k][i] = d[k][i + a[i - 1] + k] + 1;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];

    prec(n);

    int q;
    cin >> q;
    fr(i, q) {
        int p, k;
        cin >> p >> k;
        if (k >= M) {
            int ans = 0;
            while (p <= n)
                p = p + k + a[p - 1], ans++;
            cout << ans << endl;
        }
        else {
            cout << d[k][p] << endl;
        }
    }
}