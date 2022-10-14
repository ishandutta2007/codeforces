#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 50087, logN = 17, K = 222;

template <typename T>
struct Seg {
    int l, r, m;
    T sum, addTag;
    Seg* ch[2];
    Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
        sum = addTag = 0;
        if (r - l != 1) {
            ch[0] = new Seg <T>(l, m);
            ch[1] = new Seg <T>(m, r);
            pull();
        }
    }
    int size() {return r - l;}
    void pull() {sum = ch[0]->sum + ch[1]->sum;}
    void addValue(T v) {sum += v * size();};
    void push() {
        if (addTag) {
            if (r - l != 1) {
                ch[0]->addValue(addTag);
                ch[0]->addTag += addTag;
                ch[1]->addValue(addTag);
                ch[1]->addTag += addTag;
            }
            addTag = 0;
        }
    }
    void set(int p, T v) {
        if (r - l == 1) {
            sum = v;
        } else {
            push();
            if (p < m) {
                ch[0]->set(p,v);
            } else {
                ch[1]->set(p,v);
            }
            pull();
        }
    }
    T query(int a, int b) {
        if (a <= l and r <= b) return sum;
        push();
        T ans = 0;
        if (a < m) ans += ch[0]->query(a,b);
        if (m < b) ans += ch[1]->query(a,b);
        return ans;
    }
    void add(int a, int b, T v) {
        if (a >= b) return;
        if (a <= l and r <= b) {
            addValue(v);
            addTag += v;
        } else {
            push();
            if (a < m) ch[0]->add(a,b,v);
            if (m < b) ch[1]->add(a,b,v);
            pull();
        }
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n];
    fop (i,0,n) cin >> s[i];
    int l[n][m], r[n][m], u[n][m], d[n][m];
    fop (i,0,n) fop (j,0,m) {
        if (i) {
            if (s[i][j] == '*') u[i][j] = u[i - 1][j] + 1;
            else u[i][j] = 0;
        } else {
            u[i][j] = s[i][j] == '*';
        }
        if (j) {
            if (s[i][j] == '*') l[i][j] = l[i][j - 1] + 1;
            else l[i][j] = 0;
        } else {
            l[i][j] = s[i][j] == '*';
        }
    }

    FOP (i,n,0) FOP (j,m,0) {
        if (i < n - 1) {
            if (s[i][j] == '*') d[i][j] = d[i + 1][j] + 1;
            else d[i][j] = 0;
        } else {
            d[i][j] = s[i][j] == '*';
        }
        if (j < m - 1) {
            if (s[i][j] == '*') r[i][j] = r[i][j + 1] + 1;
            else r[i][j] = 0;
        } else {
            r[i][j] = s[i][j] == '*';
        }
    }
    vector <pair <pii, int>> ans;
    vector <pii> row[n], col[m];
    fop (i,0,n) fop (j,0,m) {
        int re = min({u[i][j], d[i][j], l[i][j], r[i][j]});
        if (re <= 1) continue;
        re--;
        ans.pb(mp(mp(i, j), re));
        row[i].eb(j - re, j + re + 1);
        col[j].eb(i - re, i + re + 1);
    }
    fop (i,0,n) {
        sort(all(row[i]));
        vector <pii> v;
        for (pii A : row[i]) {
            if (v.empty() || v.back().Y < A.X) {
                v.pb(A);
            } else {
                v.back().Y = max(v.back().Y, A.Y);
            }
        }
        for (auto A : v) {
            fop (j,A.X,A.Y) s[i][j] = '.';
        }
    }
    fop (i,0,m) {
        sort(all(col[i]));
        vector <pii> v;
        for (pii A : col[i]) {
            if (v.empty() || v.back().Y < A.X) {
                v.pb(A);
            } else {
                v.back().Y = max(v.back().Y, A.Y);
            }
        }
        for (auto A : v) {
            fop (j,A.X,A.Y) s[j][i] = '.';
        }
    }
    bool is = false;
    fop (i,0,n) fop (j,0,m) is |= s[i][j] == '*';
    if (is) cout << -1 << endl;
    else {
        cout << ans.size() << endl;
        for (auto A : ans) {
            cout << A.X.X + 1 << ' ' << A.X.Y + 1 << ' ' << A.Y << endl;
        }
    }
}