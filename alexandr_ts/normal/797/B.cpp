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
const int M = 1003;
const int N = 1e6 + 2;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    int se = 0, so = 0, mo = INF, mo2 = -INF;
    fr(i, n) {
        if (a[i] % 2 && a[i] < 0)
            mo2 = max(mo2, a[i]);
        if (a[i] > 0) {
            if (a[i] % 2 == 0)
                se += a[i];
            else {
                so += a[i];
                if (a[i] < mo)
                    mo = a[i];
            }
        }
    }
    if (so % 2)
        cout << se + so;
    else
    if (mo != INF) {
        if (mo2 == -INF)
            cout << se + so - mo;
        else
            cout << max(se + so - mo, se + so + mo2);
    }
    else {
        cout << se + so + mo2;
    }
}