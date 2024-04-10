#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int M = 1e3 + 2;
const ll INF = 2e9 + 7;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll MAX = 1e15;
const ld EPS = 1e-10;

ll a[N], p[N];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];

    ll cur = 1;
    set <ll> st;
    ll ans = 0;

    while (true) {
        if (st.count(cur) || -MAX > cur || cur > MAX) break;
        st.insert(cur);
        p[0] = 0;
        map <ll, ll> m;
        m[0] = 1;
        fr(i, n) {
            p[i + 1] = p[i] + a[i];
            m[p[i + 1]]++;
            ans += m[p[i + 1] - cur];
        }
        cur *= k;
    }
    cout << ans;

}