#include <bits/stdc++.h>

#define lyons ;
#define fulcrum(...) ;
#ifndef promising
#define dump(...)
#endif

#define E 2.718281828459045
#define PI 3.141592653589793
#define M1 167772161
#define M3 998244353
#define M7 1000000007
#define INF 0x3fffffff
#define INF64 0x3fffffff3fffffff

const int P = M3;

#define loop(i, n) for (int i = 0; i < (n); i++)
#define lback(i, n) for (int i = (n)-1; i >= 0; i--)
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rback(i, l, r) for (int i = (r)-1; i >= (l); i--)
#define all(x) (x).begin(), (x).end()
#define isz(x) ((int)(x).size())
#define iln(x) ((int)(x).length())

#define mid (l + (r - l) / 2)
#define lson (x << 1)
#define rson (x << 1 | 1)

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef pair<long long, long long> pll;
typedef complex<double> cp;
template <class T> using vector2D = vector<vector<T>>;
template <class T> using vector3D = vector<vector2D<T>>;
template <class T> using pque = priority_queue<T>;
template <class T> using heap = priority_queue<T, vector<T>, greater<T>>;

template <class T> T max(T a, T b, T c) { return max(max(a, b), c); }
template <class T> T min(T a, T b, T c) { return min(min(a, b), c); }
template <class T> bool umax(T &x, T y) {
    return (x < y) ? x = y, true : false;
}
template <class T> bool umin(T &x, T y) {
    return (x > y) ? x = y, true : false;
}

void prepare() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
}

int n;

vector<int> form(string s) {
    for (char &c : s)
        if (c == '-' || c == '+' || c == '.' || c == '/') c = ' ';
    stringstream ss(s);
    int x;
    vector<int> res;
    while (ss >> x) res.push_back(x);
    return res;
}
void print(ll mask, int len) {
    vector<int> a;
    loop(i, 4) a.push_back(mask & 255), mask >>= 8;
    reverse(all(a));
    loop(i, 4) {
        if (i) cout << ".";
        cout << a[i];
    }
    if (len < 32) cout << "/" << len;
    cout << endl;
}

int tot = 1;
int ch[7000000][2];
bool wh[7000000];
bool all_wh[7000000];
bool bl[7000000];
bool all_bl[7000000];

vector<pli> ans;

void dfs(int x, ll mask, int len) {
    if (!x) return;
    if (!wh[x]) {
        ans.push_back(pli(mask, len));
        return;
    }
    dfs(ch[x][0], mask, len + 1);
    dfs(ch[x][1], mask | (1 << (31 - len)), len + 1);
}

int main() {
    prepare();
    cin >> n;
    bool black = 0;
    loop(i, n) {
        string s;
        cin >> s;
        bool tf = s[0] == '+';
        auto a = form(s);
        int len = 32;
        if (isz(a) == 5) len = a.back(), a.pop_back();
        ll mask = 0;
        for (auto x : a) mask = mask << 8 | x;
        int cur = 1;
        wh[cur] |= tf;
        bl[cur] |= !tf;
        loop(i, len) {
            int b = mask >> (32 - i - 1) & 1;
            if (!ch[cur][b]) ch[cur][b] = ++tot;
            cur = ch[cur][b];
            wh[cur] |= tf;
            bl[cur] |= !tf;
        }
        all_wh[cur] |= tf;
        all_bl[cur] |= !tf;
    }
    bool con = 1;
    rep(i, 1, tot + 1) if (all_wh[i] && bl[i] || all_bl[i] && wh[i]) {
        con = 0;
        break;
    }
    if (!con) {
        cout << -1 << endl;
        return 0;
    }
    dfs(1, 0, 0);
    cout << isz(ans) << endl;
    for (auto [mask, len] : ans) print(mask, len);
    return 0;
}