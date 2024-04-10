#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int N = 5e5 + 10;
const int M = 502;
const ll INF = 1e9 + 10;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const ld PI = acos(-1);

int a[N];
int b[N];
ll pref[N];

int binSearch(int n, bool side, int parity) {
    int tl = -1, tr = (n / 2) + 1;
    if (side)
        tl = -1, tr = (n / 2) + 1;
    while (tr - tl > 1) {
        int tm = (tl + tr) / 2;
        int ai = tm * 2 + parity;
        fr(i, n)
            b[i] = a[i];
        b[n] = ai;
        int curi = n;
        while (curi >= 1 && b[curi] > b[curi - 1]) {
            swap(b[curi], b[curi - 1]);
            curi--;
        }

        pref[0] = 0;
        frab(i, 1, n + 2)
            pref[i] = pref[i - 1] + b[i - 1];

        int lastk = n;
        bool ok = true;
        int badk = -1;
        for (int k = 1; k <= n + 1; k++) {
            ll sumleft = pref[k];
            ll sumright = (ll)k * (k - 1);
            while (lastk >= 0 && b[lastk] < k)
                lastk--;
            sumright += (ll)k * max(0, (lastk - k + 1));
            sumright += (pref[n + 1] - pref[max(k, lastk + 1)]);
            if (sumleft > sumright) {
                ok = false;
                badk = k;
                break;
            }
//            if (ai == 2)
//                cout << k << " " << ai << " " << sumleft << " " << sumright << " " <<
//                    lastk << endl;
        }
        if (!ok) {
            if (curi <= badk - 1) {
                tr = tm;
            } else {
                tl = tm;
            }
        } else {
            if (!side)
                tr = tm;
            else
                tl = tm;
        }
    }

    //cout << tl << " " << tr << endl;

    if (!side)
        return tr * 2 + parity;
    else
        return tl * 2 + parity;
}

void solve() {
    int n;
    scanf("%d", &n);
    fr(i, n)
        scanf("%d", &a[i]);
    int parity = accumulate(a, a + n, 0ll) % 2;
    sort(a, a + n, std::greater<int>());

    int l = binSearch(n, 0, parity);
    int r = binSearch(n, 1, parity);
    for (int i = l; i <= r; i += 2)
        cout << i << " ";
    if (l > r) {
        cout << -1;
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    solve();
}