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
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 17, K = 500;

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


template <typename T>
struct Seg2 {
    int l, r, m;
    T sum, addTag;
    Seg2* ch[2];
    Seg2 (int l, int r): l(l), r(r), m(l + r >> 1) {
        sum = addTag = 0;
        if (r - l != 1) {
            ch[0] = new Seg2 <T>(l, m);
            ch[1] = new Seg2 <T>(m, r);
            pull();
        }
    }
    void pull() {sum = min(ch[0]->sum, ch[1]->sum);}
    void addValue(T v) {sum += v;};
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
    int query() {
        if (r - l == 1) return l;
        push();
        if (ch[1]->sum == 0) return ch[1]->query();
        return ch[0]->query();
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
    int n, q, l, r;
    cin >> n >> q;
    vector <int> a(n);
    fop (i,0,n) cin >> a[i], a[i] = i + 1 - a[i];
    vector <pii> Q[n];
    fop (i,0,q) {
        cin >> l >> r;
        Q[l].eb(n - r - 1, i);
    }
    int now = 0;
    Seg <lli> rt_ans(0, n);
    Seg2 <lli> root(0, n);
    fop (i,0,n) {
        if (0 <= a[i] && a[i] <= now) now++;
        rt_ans.set(i, now);
        root.set(i, now - a[i]);
        if (now - a[i] < 0) root.set(i, 1 << 30);
    }
    vector <int> ans(q);
    fop (i,0,n) {
        for (pii A : Q[i]) {
            ans[A.Y] = rt_ans.query(A.X, A.X + 1);
        }
        if (a[i] == 0) {
            rt_ans.add(i, n, -1);
            root.add(i, n, -1);
            root.set(i, 1 << 30);
            while (root.sum == 0) {
                int k = root.query();
                rt_ans.add(k, n, -1);
                root.add(k, n, -1);
                root.set(k, 1 << 30);
            }
        }
    }
    printv(ans);
}