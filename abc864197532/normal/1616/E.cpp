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
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    if (a.empty())
        return o << "{}";
    bool is = false;
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
const int mod = 1e9 + 7, N = 100087, logN = 17, M = N * 40;

struct BIT {
    vector <int> bit;
    int n;

    BIT (int _n) : n(_n) {
        n += 5;
        bit.assign(n, 0);
    }

    void add(int p, int v) {
        p += 3;
        for (int i = p; i < n; i += i & (-i))
            bit[i] += v;
    }
    int query(int p) {
        int ans = 0;
        p += 3;
        for (int i = p; i > 0; i -= i & (-i))
            ans += bit[i];
        return ans;
    }
};

int main () {
    owo;
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        string cur = s;
        sort(all(cur));
        if (cur >= t) {
            cout << -1 << endl;
            continue;
        }
        BIT bit(n);
        lli res = 0, ans = 1ll << 60;
        queue <int> q[26];
        for (int i = 0; i < n; ++i)
            q[s[i] - 'a'].push(i);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < t[i] - 'a'; ++j) {
                if (!q[j].empty())
                    ans = min(ans, res + q[j].front() - bit.query(q[j].front()));
            }
            if (q[t[i] - 'a'].empty()) {
                break;
            }
            int x = q[t[i] - 'a'].front(); q[t[i] - 'a'].pop();
            s[x] = ' ';
            res += x - bit.query(x);
            bit.add(x, 1);
        }
        cout << ans << endl;
    }
}