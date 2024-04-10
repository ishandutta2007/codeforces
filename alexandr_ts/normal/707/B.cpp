#include "bits/stdc++.h"
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 3e5 + 1;
const ll INF = 2e9 + 1;
const ll MOD = 1e9 + 7;

int v[N], u[N], l[N];
bool sk[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    fr(i, m) {
        cin >> v[i] >> u[i] >> l[i];
        v[i]--, u[i]--;
    }
    int t;
    fr(i, k) {
        cin >> t;
        sk[t - 1] = true;
    }
    int ans = INF;
    fr(i, m)
        if (!sk[v[i]] && sk[u[i]])
            ans = min(ans, l[i]);
        else if (sk[v[i]] && !sk[u[i]])
            ans = min(ans, l[i]);
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}