#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const ll N = 1e5 + 1;
const ll M = 2 * 1e3 + 1;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9;

struct ap {
    int x, q;
    ap () {}
    ap(int x, int q): x(x), q(q) {}
};

ap a[N];

bool cmp(ap a, ap b) {
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int n, x, q;
    cin >> n;
    fr(i, n) {
        cin >> a[i].x >> a[i].q;
    }
    sort(a, a + n, cmp);
    vector <ap> a1, b1;
    fr(i, n)
        if (a[i].x < 0)
            b1.pb(ap(-a[i].x, a[i].q));
        else
            a1.pb(ap(a[i].x, a[i].q));
    reverse(b1.begin(), b1.end());
    x = min(a1.size(), b1.size());
    int ans = 0;
    fr(i, x)
        ans += b1[i].q + a1[i].q;
    if (x < a1.size())
        ans += a1[x].q;
    if (x < b1.size())
        ans += b1[x].q;
    cout << ans;
 }