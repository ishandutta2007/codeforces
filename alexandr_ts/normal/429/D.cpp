#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 10001;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-7;

int a[N], p[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <int> c(n, 0);
    fr(i, n)
        c[i] = i + 1;
    random_shuffle(c.begin(), c.end());
    int ans = INF;
    frab(i, 1, 1 + n) {
        cin >> a[i];
        if (i > 1)
            ans = min(ans, a[i] * a[i] + 1);
    }
    frab(i, 1, 1 + n)
        p[i] = p[i - 1] + a[i];
    for (int i1 = 0; i1 < n; ++i1) {
        int i = c[i1];
        for (int j = i + 1; j <= n && (i - j) * (i - j) < ans; ++j)
            if (abs(p[j] - p[i]) < M && (p[j] - p[i]) * (p[j] - p[i]) < ans)
                ans = min(ans, (i - j) * (i - j) + (p[j] - p[i]) * (p[j] - p[i]));
    }
    cout << ans;
}