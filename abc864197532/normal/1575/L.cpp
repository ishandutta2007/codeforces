/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 100001, logN = 20, K = 2000, inf = 1e9;
struct seg{
    int l, r, mid, ma = -inf;
    seg *ch[2]{};
    void set(int pos, int val){
        if (l == r){
            ma = max(ma, val);
            return;
        }
        if (pos <= mid)
            ch[0]->set(pos, val);
        else
            ch[1]->set(pos, val);
        ma = max(ch[0]->ma, ch[1]->ma);
    }
    int query(int _l, int _r){
        if (_l <= l and _r >= r)
            return ma;
        if (_l > r or _r < l)
            return -inf;
        return max(ch[0]->query(_l, _r), ch[1]->query(_l, _r));
    }
    seg(int _l, int _r) : l(_l), r(_r), mid(l + r >> 1){
        if (l < r)
            ch[0] = new seg(l, mid), ch[1] = new seg(mid + 1, r);
    }
};
int main () {
    owo;
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].fi;
        a[i].se = -(i + 1);
    }
    sort(a.begin(), a.end());
    // a[j] - j >= a[i] - i
    seg *rt = new seg(0, n);
    for (auto i : a){
        int p = -i.se - i.fi;
        if (p >= n or p < 0)
            continue;
        int dp = max(1, rt->query(0, p) + 1);
        rt->set(p, dp);
        test(i.fi, p, dp);
    }
    cout << max(0, rt->query(0, n));
}