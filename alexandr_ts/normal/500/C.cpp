#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < (ll)n; i++)
#define frab(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e4 + 10;
const ll INF = 2e9;
const ll ALPH = 300;

struct tmp {
    ll x, num;
};

ll b[N];
tmp a[N];
bool used[N];

int main() {
        //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    ll n, m;
    cin >> n >> m;
    fr(i, n) {
        cin >> a[i].x;
        a[i].num = i + 1;
    }
    vector <tmp> c;
    fr(j, m)
        cin >> b[j];
    fr(j, m)
        if (!used[a[b[j] - 1].num])
            c.pb(a[b[j] - 1]), used[a[b[j] - 1].num] = true;
    fr(i, n)
        if (!used[a[i].num])
            c.pb(a[i]);
    ll ans = 0;
    fr(i, m) {
        ll pos = 0;
        fr(j, n)
            if (c[j].num == b[i])
                pos = j;
        ll tmp1 = 0;
        fr(j, pos)
            tmp1 += c[j].x;
        rotate(c.begin(), c.begin() + pos, c.begin() + pos + 1);
        //fr(i, n)
            //cout << c[i].x << " ";cout << endl;
        ans += tmp1;
    }
    cout << ans;

}