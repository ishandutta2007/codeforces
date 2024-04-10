#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-15;
const ld PI = acos(-1);

const int M = 1e3 + 10;
const int N = 1e6 + 10;

ll a[N], pr[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i];
        pr[i + 1] = pr[i] + a[i];
    }
    ll sum = accumulate(a, a + n, 0ll);
    if (sum % 2) {
        cout << "NO";
        return 0;
    }

    sum /= 2;

    map <ll, int> m;
    map <ll, int> m2;
    fr(i, n)
        m[a[i]]++;

    fr(i, n + 1) {
        if (i) {
            m2[a[i - 1]]++;
            m[a[i - 1]]--;
            if (m[a[i - 1]] == 0)
                m.erase(a[i - 1]);
        }
        ll need = sum - pr[i];
        if (m.count(need) && m[need] >= 1) {
            cout << "YES";
            return 0;
        }
        if (m2.count(-need) && m2[-need] >= 1) {
            cout << "YES";
            return 0;
        }

    }
    cout << "NO";
}