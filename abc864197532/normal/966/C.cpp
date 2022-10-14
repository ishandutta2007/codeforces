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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 2e5 + 101, logN = 18;

struct Trie {  
    vector <vector <int>> ch;
    vector <int> cnt;
    Trie() {extend();}
    void extend() {
        ch.pb(vector <int>(2, 0));
        cnt.pb(0);
    }
    int next(int u, int v) {
        if (!ch[u][v]) {
            ch[u][v] = ch.size();
            extend();
        }
        return ch[u][v];
    }
    void insert(lli x) {
        int now = 0;
        for (int d = 60; ~d; --d) {
            now = next(now, x >> d & 1);
            cnt[now]++;
        }
    }
    void del(lli x) {
        int now = 0;
        for (int d = 60; ~d; --d) {
            now = next(now, x >> d & 1);
            cnt[now]--;
        }
    }
    lli query(lli x, lli bound) {
        // find min (x ^ y) and (x ^ y) > y
        lli ans = 0;
        int f = 0, now = 0;
        for (int d = 60; ~d; --d) {
            if (f) {
                if (cnt[ch[now][x >> d & 1]]) {
                    now = ch[now][x >> d & 1];
                } else {
                    now = ch[now][~x >> d & 1];
                    ans |= 1ll << d;
                }
            } else {
                if (bound >> d & 1) {
                    // must be 1 here
                    if (cnt[ch[now][~x >> d & 1]]) {
                        now = ch[now][~x >> d & 1];
                        ans |= 1ll << d;
                    } else {
                        return -1;
                    }
                } else {
                    bool ok = false;
                    if (cnt[ch[now][x >> d & 1]]) {
                        int nnow = ch[now][x >> d & 1];
                        lli res = ans;
                        for (int nd = d - 1; nd >= 0; --nd) {
                            if (cnt[ch[nnow][~x >> nd & 1]]) {
                                nnow = ch[nnow][~x >> nd & 1];
                                res |= 1ll << nd;
                            } else {
                                nnow = ch[nnow][x >> nd & 1];
                            }
                        }
                        if (res > bound) {
                            ok = true;
                        }
                    }
                    if (ok) {
                        now = ch[now][x >> d & 1];
                    } else if (cnt[ch[now][~x >> d & 1]]) {
                        now = ch[now][~x >> d & 1];
                        ans |= 1ll << d, f = 1;
                    } else {
                        return -1;
                    }
                }
            }
        }
        return ans ^ x;
    }
} tr;

int main () {
    owo;
    int n;
    cin >> n;
    lli x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        tr.insert(x);
    }
    lli pre = 0;
    vector <lli> ans;
    for (int i = 0; i < n; ++i) {
        lli x = tr.query(pre, pre);
        test(x);
        if (x == -1 || pre >= (pre ^ x)) {
            cout << "No\n";
            return 0;
        }
        pre ^= x;
        tr.del(x);
        ans.pb(x);
    }
    cout << "Yes\n";
    printv(all(ans));
}

/*
 010
 100
 011
 */