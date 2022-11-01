#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1073741824;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

ll w1[N];

int main() {
    //ios_base::sync_with_stdio(false);
    //cout << fixed << setprecision(8);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    w1[0] = 1;
    ll w, m, pos;
    cin >> w >> m;
    frab(i, 1, 100) {
        w1[i] = w1[i - 1] * w;
        if (w1[i] > 1e9) {
            pos = i;
            break;
        }
    }

    for (ll i = pos; i >= 0; i--) {
        ll m1 = abs(m);
        ll m2 = abs(m + w1[i]);
        ll m3 = abs(m - w1[i]);
        if (m1 <= m2 && m1 <= m3)
            continue;
        else if (m2 <= m1 && m2 <= m3)
            m = m + w1[i];
        else
            m = m - w1[i];
    }
    if (!m)
        cout << "YES";
    else
        cout << "NO";

}