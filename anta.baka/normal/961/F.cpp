#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1e6 + 1, mod = 1e9 + 7;

struct num {
    static const int MA = 1e9 + 7, MB = 1e9 + 9;
    int a, b;
    num() {}
    num(int x) : a((x%MA+MA)%MA), b((x%MB+MB)%MB) {}
    num(int x, int y) : a((x%MA+MA)%MA), b((y%MB+MB)%MB) {}
    num operator + (const num &he) const {
        return num(a + he.a, b + he.b);
    }
    num operator - (const num &he) const {
        return num(a - he.a, b - he.b);
    }
    num operator * (const num &he) const {
        return num(ll(a) * he.a % MA, ll(b) * he.b % MB);
    }
    bool operator == (const num &he) const {
        return a == he.a && b == he.b;
    }
};

struct segTree {
    int n; vector<int> t;
    segTree(int n) : n(n), t(2 * n, -1) {}
    void upd(int v, int x) {
        t[v += n] = x;
        for(v >>= 1; v; v >>= 1) t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
    int get(int l, int r) {
        int ret = -1;
        for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if(l & 1) ret = max(ret, t[l]);
            if(!(r & 1)) ret = max(ret, t[r]);
        }
        return ret;
    }
};

int P = max(239, rand());
num h[maxn], p[maxn];

num ss(int l, int r) {
    return h[r + 1] - h[l] * p[r - l + 1];
}

int n;
string s;
int d[maxn];
vector<int> out[maxn];
int ans[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    srand(time(NULL) + 'L' + 'O' + 'L' + 'L' + 'Y' + 'P' + 'O' + 'P');
    cin >> n >> s;
    h[0] = 0, p[0] = 1;
    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i] * P;
        h[i + 1] = h[i] * P + s[i];
    }
    for(int i = 0; i < n / 2; i++) {
        int j = n - 1 - i;
        if(s[i] != s[j]) { d[i] = 0; continue; }
        int lf = 1, rg = i + 1;
        while(lf < rg) {
            int md = (lf + rg + 1) >> 1;
            if(ss(i - md + 1, i + md - 1) == ss(j - md + 1, j + md - 1)) lf = md;
            else rg = md - 1;
        }
        d[i] = lf;
    }
    segTree t(n);
    for(int i = n / 2 - 1; i >= 0; i--) {
        int dd = d[i];
        if(dd != 0) {
            out[i - dd + 1].push_back(i);
            t.upd(i, i);
        }
        int u = t.get(i, n - 1);
        if(u == -1) ans[i] = -1;
        else ans[i] = 2 * (u - i) + 1;
        for(int x : out[i]) t.upd(x, -1);
    }
    for(int i = 0; i < n / 2; i++) cout << ans[i] << ' ';
    if(n & 1) cout << -1;
}