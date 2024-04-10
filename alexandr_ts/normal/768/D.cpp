#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e3 + 10;
const ld EPS = 1e-8;
const ll INF = 1e9 + 10;
ld d[N + 1];
ll ans[N];

int main() {
    //freopen("a.in", "r", stdin);
    int k, q;
    cin >> k >> q;
    d[0] = 1;
    int n = 1, curd = 1;
    while (n < 1001) {
        for (int j = k; j >= 1; j--)
            d[j] = d[j] * ((ld)j / k) + d[j - 1] * ((ld)(k - j + 1) / k);
        //cout << d[k] << endl;
        while (n - EPS < 2000 * d[k] && n <= 1000)
            ans[n++] = curd;
        curd++;
        d[0] = 0;
    }

    fr(i, q) {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }

}