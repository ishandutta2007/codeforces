#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 10;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const int MOD = 1e9 + 7;

struct pt {
    ll x, y;
};

pt a[N], b[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    fr(i, p)
        cin >> a[i].x >> a[i].y;
    fr(i, q)
        cin >> b[i].x >> b[i].y;
    fr(i, q)
        b[i].x += l - 1, b[i].y += l - 1;
    int ans = 0;
    frab(i, 0, r - l + 1) {
        fr(j, q) b[j].x++, b[j].y++;
        bool fnd = false;
        fr(i1, p) fr(i2, q)
            if (!(a[i1].x > b[i2].y || a[i1].y < b[i2].x)) {
                fnd = true;
            }
        ans += fnd;
    }
    cout << ans;
}