#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>


using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const ll INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

struct P {
    int x, v, i;
} a[N];

int w;

bool cmp1(P a, P b) {
    //return (ld)-a.x / (a.v - w) < (ld)-b.x / (b.v - w);
    if ((ll)abs(a.x) * abs(b.v - w) != (ll)abs(b.x) * abs(a.v - w))
        return (ll)abs(a.x) * abs(b.v - w) < (ll)abs(b.x) * abs(a.v - w);
    if ((ll)abs(a.x) * abs(b.v + w) != (ll)abs(b.x) * abs(a.v + w))
        return (ll)abs(a.x) * abs(b.v + w) > (ll)abs(b.x) * abs(a.v + w);
    return a.x < b.x;
}

bool cmp2(P a, P b) {
    if ((ll)abs(a.x) * abs(b.v + w) != (ll)abs(b.x) * abs(a.v + w))
        return (ll)abs(a.x) * abs(b.v + w) < (ll)abs(b.x) * abs(a.v + w);
    if ((ll)abs(a.x) * abs(b.v - w) != (ll)abs(b.x) * abs(a.v - w))
        return (ll)abs(a.x) * abs(b.v - w) > (ll)abs(b.x) * abs(a.v - w);
    return a.x > b.x;
}

vector <int> help;

ll cnt(vector <int> &v, int tl, int tr) {
    if (tl == tr) return 0;
    int tm = (tl + tr) / 2;
    ll ans1 = cnt(v, tl, tm);
    ll ans2 = cnt(v, tm + 1, tr);
    int cur = tm + 1;
    ll ans = ans1 + ans2;
    help.clear();
    for (int i = tl; i <= tm; i++) {
        while (cur <= tr && v[i] > v[cur]) {
            help.push_back(v[cur]);
            cur++;
            ans += tm - i + 1;
        }
        help.push_back(v[i]);
    }
    for (int i = 0; i < help.size(); i++)
        v[tl + i] = help[i];
    return ans;
}

void solve() {
    int n;
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].x, &a[i].v);
        a[i].i = i;
    }
    sort(a, a + n, cmp1);
    vector <int> v;
    for (int i = 0; i < n; i++)
        v.push_back(a[i].i);
    //for (auto t: v) cout << t << " ";cout << endl;
    vector <int> pos(n);
    for (int i = 0; i < n; i++)
        pos[v[i]] = i;
    sort(a, a + n, cmp2);
    //for (int i = 0; i < n; i++) cout << a[i].i << " ";cout << endl;
    for (int i = 0; i < n; i++)
        v[i] = pos[a[i].i];
//    for (int i = 0; i < n; i++)
//        cout << v[i] << " ";cout << endl;
    cout << cnt(v, 0, n - 1) << endl;
//    for (int i = 0; i < n; i++)
//        cout << v[i] << " ";
}

int main() {
    //freopen("a.in", "r", stdin);
    solve();

}