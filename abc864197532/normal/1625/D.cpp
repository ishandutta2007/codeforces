#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 150001, logN = 20, K = 48763;

struct Trie {
    int pt;
    Trie* ch[2];
    Trie () : pt(-1), ch{NULL, NULL} {}
    void insert(int x, int id, int bit = 29) {
        if (bit == -1) {
            pt = id;
            return;
        }
        if (!ch[x >> bit & 1])
            ch[x >> bit & 1] = new Trie();
        ch[x >> bit & 1]->insert(x, id, bit - 1);
    }
    pii query(int x, int bit = 29) {
        if (bit == -1)
            return mp(0, pt);
        if (ch[~x >> bit & 1]) {
            auto ans = ch[~x >> bit & 1]->query(x, bit - 1);
            ans.X |= 1 << bit;
            return ans;
        }
        return ch[x >> bit & 1]->query(x, bit - 1);
    }
    void del() {
        if (ch[0])
            ch[0]->del(), delete ch[0], ch[0] = NULL;
        if (ch[1])
            ch[1]->del(), delete ch[1], ch[1] = NULL;
    }
} tr;

int main () {
    owo;
    // 1000
    // < 1000 -> 1
    // >= 1000 -> (>> 3) not same
    // 1010
    // < 1000 -> 1
    // >= 1000 -> (>> 3) not same && (xor = 1 pair) >= that
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << n << endl;
        for (int i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << endl;
        return 0;
    }
    int lg = __lg(k);
    test(lg);
    map <int, vector <int>> m1;
    vector <int> a(n); 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m1[a[i] >> lg].pb(i);
    }
    vector <int> ans;
    map <int, bool> vis;
    for (auto A : m1) {
        if (vis[A.X])
            continue;
        if (!m1.count(A.X ^ 1)) {
            ans.pb(A.Y[0] + 1);
        } else {
            vector <int> l = A.Y, r = m1[A.X ^ 1];
            vis[A.X] = vis[A.X ^ 1] = true;
            tr.del();
            for (int i : l)
                tr.insert(a[i], i);
            int mx = 0, id1 = -1, id2 = -1;
            for (int i : r) {
                int x, id;
                tie(x, id) = tr.query(a[i]);
                if (mx < x)
                    mx = x, id1 = id, id2 = i;
            }
            if (mx >= k)
                ans.pb(id1 + 1), ans.pb(id2 + 1);
            else
                ans.pb(id1 + 1);
        }
    }
    if (ans.size() == 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    printv(all(ans));
}