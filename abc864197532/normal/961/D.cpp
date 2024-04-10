#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1 << 18, logN = 17, K = 90002;

struct Pt {
    lli x, y;
    Pt (lli _x = 0, lli _y = 0) : x(_x), y(_y) {}
    Pt operator + (const Pt &other) {
        return Pt(x + other.x, y + other.y);
    }
    Pt operator - (const Pt &other) {
        return Pt(x - other.x, y - other.y);
    }
    Pt operator * (const int &k) {
        return Pt(x * k, y * k);
    }
    lli operator * (const Pt &other) { // dot
        return x * other.x + y * other.y;
    }
    lli operator ^ (const Pt &other) { // cross
        return x * other.y - y * other.x;
    }
};

vector <Pt> p;

bool check(int i, int j) {
    int n = p.size();
    vector <Pt> v;
    fop (k,0,n) if (k != i && k != j) {
        if ((p[i] - p[j]) ^ (p[k] - p[i])) {
            v.pb(p[k]);
        }
    }
    fop (k,2,v.size()) {
        if ((v[k] - v[0]) ^ (v[0] - v[1])) return false;
    }
    return true;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n <= 3) {
        cout << "YES\n";
        return 0;
    }
    p.resize(n);
    fop (i,0,n) cin >> p[i].x >> p[i].y;
    if (check(0, 1) || check(1, 2) || check(0, 2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}