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
const int N = 2e5 + 10;

bool solve(int n, vector <int> &a, int x, int d, int b) {
    int cur = 0;
    ll sum = 0;
    for (int i = n - x; i < n; i++) {
        while (cur < a.size() && cur <= i + (ll)d * (i + 1))
            sum += a[cur++];
        if (sum < b) return false;
        sum -= b;
    }
    return true;
}

int main() {
    //freopen("a.in", "r", stdin);
    int n, d, b;
    scanf("%d %d %d", &n, &d, &b);
    vector <int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    //cout << solve(3, a, 2, d, b) << endl;
    int l = 0, r = (n + 1) / 2 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (solve((n + 1) / 2, a, m, d, b))
            l = m;
        else
            r = m;
    }

    int ans = l;
    //cout << ans << endl;
    reverse(a.begin(), a.end());
    l = 0, r = n / 2 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (solve(n / 2, a, m, d, b))
            l = m;
        else
            r = m;
    }
    cout << max((n + 1) / 2 - ans, n / 2 - l);
}