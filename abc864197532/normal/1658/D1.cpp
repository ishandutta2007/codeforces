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
const int mod = 998244353, N = 200005, logN = 20, K = 111;

struct Trie {
    vector <vector <int>> ch;
    vector <int> cnt;
    Trie() {extend();}
    void extend() {
        ch.pb(vector <int>(2, 0));
        cnt.pb(0);
    }
    void insert(int x) {
        int now = 0;
        for (int d = 17; ~d; --d) {
            cnt[now]++;
            if (!ch[now][x >> d & 1]) {
                ch[now][x >> d & 1] = ch.size();
                extend();
            }
            now = ch[now][x >> d & 1];
        }
        cnt[now]++;
    }
    int query(int x, int bound) {
        int now = 0, ans = 0;
        for (int d = 17; ~d; --d) {
            if (bound >> d & 1) {
                if (ch[now][x >> d & 1])
                    ans += cnt[ch[now][x >> d & 1]];
                now = ch[now][~x >> d & 1];
            } else {
                now = ch[now][x >> d & 1];
            }
            if (!now)
                break;
        }
        return ans;
    }
    void reset() {
        ch.clear(), cnt.clear(), extend();
    }
} tr;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int l, r, n;
        cin >> l >> r, n = r - l + 1;
        vector <int> possible_x;
        for (int i = 0, y; i < n; ++i) {
            cin >> y;
            tr.insert(y);
            possible_x.pb(y ^ l);
        }
        int ans = -1;
        for (int x : possible_x) {
            if (tr.query(x, r + 1) - tr.query(x, l) == n)
                ans = x;
        }
        cout << ans << endl;
        tr.reset();
    }
}