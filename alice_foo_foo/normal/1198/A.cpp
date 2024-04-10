#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() { *this = hash_map_t(mod); }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 4e5 + 5;

int a[N], b[N], cnt[N], s1[N], s2[N];
int n, m, big, len = 1, lg, ans = N;

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1); big = unique(b + 1, b + n + 1) - b - 1;
    for(register int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + big + 1, a[i]) - b, ++cnt[a[i]];
    lg = m * 8 / n;
    if(lg >= 20) {
        print(0, '\n');
        return 0;
    }
    for(register int i = 1; i <= lg; i++) len = len << 1;
    if(len >= big) {
        print(0, '\n');
        return 0;
    }
    for(register int i = 1; i <= big; i++) s1[i] = s1[i - 1] + cnt[i];
    for(register int i = big; i >= 1; i--) s2[i] = s2[i + 1] + cnt[i];
    for(register int i = 1; i <= big - len + 1; i++) ans = min(ans, s1[i - 1] + s2[i + len]);
    print(ans, '\n');
    return 0;
}