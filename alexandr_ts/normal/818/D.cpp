#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;
const int N = 1e6 + 2;

int c[N];

int cnt[N];
vector <int> g[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, A;
    cin >> n >> A;
    fr(i, n)
        cin >> c[i];
    int cntA = 0;
    fr(i, n)
        if (c[i] == A)
            cntA++;

    fr(i, n)
        cnt[c[i]]++;
    if (cntA >= 100) {
        frab(i, 1, N)
            if (cnt[i] >= cntA && i != A) {
                int c1 = 0, c2 = 0;
                bool ok = true;
                fr(j, n) {
                    if (c[j] == A) c1++;
                    if (c[j] == i) c2++;
                    if (c1 > c2) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cout << i;
                    return 0;
                }
            }
        cout << -1;
    }
    else {
        fr(i, n)
            if (cnt[c[i]] >= cntA)
                g[c[i]].pb(i);
        frab(i, 1, N) {
            if (cnt[i] >= cntA && i != A) {
                bool ok = true;
                fr(j, cntA)
                    if (g[A][j] < g[i][j]) {
                        ok = false;
                        break;
                    }
                if (ok) {
                    cout << i;
                    return 0;
                }
            }
        }
        cout << -1;
    }
}