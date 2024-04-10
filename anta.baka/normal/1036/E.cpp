#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define int ll
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
//#define int ll

const int maxn = 1e6;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18L;
const ld pi = acos(-1.0);
const ld eps = 1e-6;
const int BL = 317;
const int LIM = 1e6;
int shit[LIM + 1];

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    for(int i = 1; i * (i - 1) / 2 <= LIM; i++) shit[i * (i - 1) / 2] = i;

    struct line {
        int a, b;
        ll c;
    };
    int n; cin >> n;
    ll ans = 0;
    vector<pll> v1(n), v2(n);
    vector<line> l(n);
    for(int i = 0; i < n; i++) {
        cin >> v1[i].x >> v1[i].y >> v2[i].x >> v2[i].y;
        if(v1[i].x == v2[i].x) ans += 1 + abs(v1[i].y - v2[i].y);
        else if(v1[i].y == v2[i].y) ans += 1 + abs(v1[i].x - v2[i].x);
        else ans += 1 + __gcd((ll)abs(v1[i].x - v2[i].x), (ll)abs(v1[i].y - v2[i].y));
        l[i] = {v1[i].y - v2[i].y, v2[i].x - v1[i].x, (ll)v1[i].x * v2[i].y - (ll)v2[i].x * v1[i].y};
    }
    map<pll, int> cnt;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            line l1 = l[i], l2 = l[j];
            ll d = ll(l1.a) * l2.b - ll(l2.a) * l1.b;
            if(d == 0) continue;
            ll dx = -l1.c * l2.b + l2.c * l1.b;
            if(dx % d) continue;
            ll dy = -l1.a * l2.c + l2.a * l1.c;
            if(dy % d) continue;
            dx /= d; dy /= d;
            //cout << dx << ' ' << dy << endl;
            int x1 = min(v1[i].x, v2[i].x);
            int x2 = max(v1[i].x, v2[i].x);
            int y1 = min(v1[i].y, v2[i].y);
            int y2 = max(v1[i].y, v2[i].y);
            if(!(x1 <= dx && dx <= x2 && y1 <= dy && dy <= y2)) continue;
            x1 = min(v1[j].x, v2[j].x);
            x2 = max(v1[j].x, v2[j].x);
            y1 = min(v1[j].y, v2[j].y);
            y2 = max(v1[j].y, v2[j].y);
            if(!(x1 <= dx && dx <= x2 && y1 <= dy && dy <= y2)) continue;
            cnt[{dx, dy}]++;
        }
    for(auto tmp : cnt) {
        //cout << tmp.x.x << ' ' << tmp.x.y << endl;
        //cout << shit[tmp.y] << endl;
        ans -= shit[tmp.y] - 1;
    }
    cout << ans;
}