#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const int MOD = 1e9 + 7;

ll ans[N];
ll pref[N];

int main() {
    srand(time(NULL));
    int a, b, t, k;
    cin >> t >> k;
    ans[0] = 1;
    frab(i, 1, N - 1) {
        ans[i] = ans[i - 1];
        if (i - k >= 0)
            ans[i] += ans[i - k];
        ans[i] %= MOD;
    }
    pref[0] = 1;
    frab(i, 1, N - 1)
        pref[i] = (pref[i - 1] + ans[i]) % MOD;
    //frab(i, 1, 10)
    //cout << ans[i] << " ";cout << endl;
    fr(i, t) {
        cin >> a >> b;
        cout << ((pref[b] - pref[a - 1]) % MOD + MOD) % MOD << endl;
    }
}