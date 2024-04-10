#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

int a[N];
int pref[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    map <int, int> cnt;
    cnt[0] = 1;
    fr(i, n) {
        scanf("%d", &a[i]);
        pref[i + 1] = pref[i] ^ a[i];
        if (pref[i + 1] > (1 << k) - 1 - pref[i + 1])
            pref[i + 1] = (1 << k) - 1 - pref[i + 1];
        cnt[pref[i + 1]]++;
    }
    ll ans = (ll)n * (n + 1) / 2;
    for (auto t: cnt) {
        ll tmp1 = t.second / 2;
        ll tmp2 = (t.second + 1) / 2;
        ans -= (tmp1 * (tmp1 - 1)) / 2;
        ans -= (tmp2 * (tmp2 - 1)) / 2;
    }
    cout << ans;


}