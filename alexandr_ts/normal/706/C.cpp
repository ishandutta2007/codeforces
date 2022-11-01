/// Alexandr Tsaplin 18.08.16

#include "bits/stdc++.h"
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define TASK_NAME "salesman"

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5;
const ll INF = 2e16 + 1;
const ll MOD = 1e9 + 7;

int c[N];
string s[N], rs[N];
ll d[N][2];

bool cmp(string s, string t) {
    fr(i, s.size())
        if (s[i] < t[i])
            return true;
        else if (s[i] > t[i])
            return false;
    return s.size() <= t.size();
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    int n;
    cin >> n;
    fr(i, n)
        cin >> c[i];
    fr(i, n) {
        cin >> s[i];
        rs[i] = s[i];
        reverse(rs[i].begin(), rs[i].end());
    }
    fr(i, n)
        fr(j, 2)
            d[i][j] = INF;
    d[0][0] = 0;
    d[0][1] = c[0];
    frab(i, 1, n) {
        if (cmp(s[i - 1], s[i]))
            d[i][0] = d[i - 1][0];
        if (cmp(rs[i - 1], s[i]))
            d[i][0] = min(d[i][0], d[i - 1][1]);
        if (cmp(s[i - 1], rs[i]))
            d[i][1] = d[i - 1][0] + c[i];
        if (cmp(rs[i - 1], rs[i]))
            d[i][1] = min(d[i][1], d[i - 1][1] + c[i]);
    }
    ll ans = min(d[n - 1][0], d[n - 1][1]);
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}