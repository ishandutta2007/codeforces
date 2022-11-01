#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll INF = 4e13 + 10;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 2e5 + 10;

ll a[N];
ll pref[N];

void solve() {
    int n;
    scanf("%d", &n);
    fr(i, n)
        a[i] = INF;
    int tmp;
    fr(i, n / 2) {
        scanf("%d", &tmp);
        a[i * 2 + 1] = tmp;
    }

    ll p = 0;
    for (int i = 0; i < n; i += 2) {
        for (int j = 1; j * j <= a[i + 1]; j++)
            if (a[i + 1] % j == 0) {
                ll b = a[i + 1] / j;
                if (b % 2 != j % 2)
                    continue;
                ll t = (b - j) / 2;
                if (t * t > p)
                    a[i] = min(a[i], t * t - p);
            }
        if (a[i] == INF) {
            cout << "No";
            return;
        }
        p = p + a[i] + a[i + 1];
        //cout << p << endl;
    }
    cout << "Yes\n";
    fr(i, n)
        cout << a[i] << " ";
}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    solve();

    return 0;
}