#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ld PI = acos(-1);
const ll INF = 2e9;
const int LOG = 19;
const int N = (1 << LOG);
const int M = 2e5 + 10;
const int MOD = 1009;

struct Compl {
    ld x, y;
    Compl operator * (const Compl& a) const {
        return {x * a.x - y * a.y, x * a.y + y * a.x};
    }

    Compl operator + (const Compl& a) const {
        return {x + a.x, y + a.y};
    }

    Compl operator - (const Compl& a) const {
        return {x - a.x, y - a.y};
    }

    Compl operator / (const ld k) const {
        return {x / k, y / k};
    }
} w[N];

int rev[N];

void initFFT() {
    rev[0] = 0;
    int maxbit = 0;
    for (int i = 1; i < N; i++) {
        if (i == (1 << (maxbit + 1)))
            maxbit++;
        rev[i] = rev[i ^ (1 << maxbit)] ^ (1 << (LOG - maxbit - 1));
    }
    for (int i = 0; i < N; i++) {
        ld ang = i * PI * 2 / (N);
        w[i] = {cos(ang), sin(ang)};
    }
}

Compl ara[N], arb[N];

void fft(Compl* a, int logn, bool isback = false) {
    int n = (1 << logn);
    for (int i = 0; i < n; i++) {
        int j = (rev[i] >> (LOG - logn));
        if (j < i)
            swap(a[i], a[j]);
    }

    for (int loglen = 0; loglen < logn; loglen++) {
        int len = (1 << loglen);
        for (int l = 0; l < n; l += (2 * len)) {
            for (int i = 0; i < len; i++) {
                Compl tmp = w[i * (1 << (LOG - loglen - 1))] * a[i + l + len];
                a[l + len + i] = a[l + i] - tmp;
                a[l + i] = a[l + i] + tmp;
            }
        }
    }

    if (isback) {
        reverse(a + 1, a + n);
        for (int i = 0; i < n; i++)
            a[i] = a[i] / n;
    }
}

void mult(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    int logn = 0;
    while ((1 << logn) < 2 * max(n, m))
        logn++;
    for (int i = 0; i < (1 << logn); i++) {
        if (i < n)
            ara[i] = {a[i], 0};
        else
            ara[i] = {0, 0};
        if (i < m)
            arb[i] = {b[i], 0};
        else
            arb[i] = {0, 0};
    }
    fft(ara, logn);
    fft(arb, logn);

    for (int i = 0; i < (1 << logn); i++)
        ara[i] = ara[i] * arb[i];
    fft(ara, logn, true);

    a.resize((1 << logn), 0);
    for (int i = 0; i < (1 << logn); i++)
        a[i] = ((ll)round(ara[i].x) % MOD);
}

vector<int> a[M];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt(m, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x - 1]++;
    }
    set<pair<int, int> > s;
    for (int i = 0; i < m; i++)
        if (cnt[i]) {
            s.insert({cnt[i], i});
            a[i].resize(cnt[i] + 1);
            fill(a[i].begin(), a[i].end(), 1);
        }
    while (s.size() > 1) {
        auto i1 = s.begin()->second;
        s.erase(s.begin());
        auto i2 = s.begin()->second;
        s.erase(s.begin());
        mult(a[i1], a[i2]);
        a[i2].clear();
        s.insert({a[i1].size(), i1});
    }

    int i1 = s.begin()->second;
    cout << a[i1][k] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    initFFT();
    //freopen("a.in", "r", stdin);
    solve();

}