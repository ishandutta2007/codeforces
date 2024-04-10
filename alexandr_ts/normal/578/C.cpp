#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair <ll, ll> pr;

const ll N = 3e5;
const ll MOD = 1e9 + 7;
const ll INF = 1e12;
const ll P = 11;

int n;
ld a[N], b[N], pref[N], suf[N], prefn[N], sufn[N];

ld calc(ld m) {
    fr(j, n)
        b[j] = a[j] - m;

    suf[n - 1] = max((ld)0, b[n - 1]);
    sufn[n - 1] = min((ld)0, b[n - 1]);
    pref[0] = max((ld)0, b[0]);
    prefn[0] = min((ld)0, b[0]);

    frab(j, 1, n) {
        pref[j] = max((ld)0, pref[j - 1] + b[j]);
        prefn[j] = min((ld)0, prefn[j - 1] + b[j]);
    }

    for (int j = n - 2; j >= 0; j--) {
        suf[j] = max((ld)0, suf[j + 1] + b[j]);
        sufn[j] = min((ld)0, sufn[j + 1] + b[j]);
    }

    ld curans = -INF;
    fr(j, n)
        curans = max(abs(prefn[j] + sufn[j] - min((ld)0, b[j])), max(curans, abs(pref[j] + suf[j] - max((ld)0, b[j]))));
    return curans;
}

int main() {
    ld st = clock();
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    fr(i, n)
        cin >> a[i];
    ld l = -10000, r = 10000;
    while (1) {
        ld m1 = l + (r - l) / 3.0;
        ld m2 = m1 + (r - l) / 3.0;
        if (calc(m1) > calc(m2))
            l = m1;
        else
            r = m2;
        ld tm = clock();
        if (tm - st > 1962)
            break;
    }
    cout << fixed << setprecision(12) << calc(l);
}