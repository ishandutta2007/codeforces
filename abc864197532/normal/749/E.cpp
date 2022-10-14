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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1000005, logN = 17, K = 90002;

struct Seg {
    int l, r, m;
    lli sum = 0, lz = 0;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
            pull();
        }
    }
    void pull() {sum = ch[0]->sum + ch[1]->sum;}
    void push() {
        if (lz && r - l > 1) {
            ch[0]->sum += lz * (m - l);
            ch[0]->lz += lz;
            ch[1]->sum += lz * (r - m);
            ch[1]->lz += lz;
        }
        lz = 0;
    }
    void add(int a, int b, lli v) {
        if (a <= l && r <= b) sum += v * (r - l), lz += v;
        else {
            push();
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
            pull();
        }
    }
    lli query(int a, int b) {
        if (a <= l && r <= b) return sum;
        lli ans = 0;
        push();
        if (a < m) ans += ch[0]->query(a, b);
        if (m < b) ans += ch[1]->query(a, b);
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tmp;
    cin >> n;
    Seg root1(0, n);
    Seg root2(0, n);
    vector <int> p(n);
    lli ans = 0, ans2 = 0;
    fop (i,0,n) {
        cin >> tmp, tmp--;
        ans += root1.query(tmp, tmp + 1) * (n - i);
        ans2 += root2.query(tmp, n);
        root1.add(0, tmp + 1, -i - 1);
        root1.add(tmp, n, i + 1);
        root2.add(tmp, tmp + 1, 1);
    }
    cout << fixed << setprecision(15) << (long double)(ans2) + (long double)(ans) / n / (n + 1) << endl;
}