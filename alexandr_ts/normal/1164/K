#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ld PI = acos(-1);
const int LOG = 20;
const int N = (1 << LOG);

struct Compl {
    ld x, y;
    Compl() {}
    Compl(ld x, ld y): x(x), y(y) {}
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
Compl ara[N], arb[N];

void initFFT() {
    rev[0] = 0;
    int maxbit = 0;
    int n = (1 << LOG);
    for (int i = 1; i < n; i++) {
        if (i == (1 << (maxbit + 1)))
            maxbit++;
        rev[i] = rev[i ^ (1 << maxbit)] + (1 << (LOG - maxbit - 1));
    }

    for (int i = 0; i < n; i++) {
        ld ang = 2 * PI * i / n;
        w[i] = {cos(ang), sin(ang)};
    }
}

void fft(Compl* a, int logn, bool isback = false) {
    assert(logn <= LOG);
    int n = (1 << logn);

    for (int i = 1; i < n - 1; i++) {
        int j = (rev[i] >> (LOG - logn));
        if (j > i) {
            swap(a[i], a[j]);
        }
    }

    for (int loglen = 0; loglen < logn; loglen++) {
        int len = (1 << loglen);
        for (int l = 0; l < n; l += (2 * len)) {
            for (int i = 0; i < len; i++) {
                Compl tmp = w[i * (1 << (LOG - loglen - 1))] * a[l + i + len];
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

vector<ll> mult(vector<ll>& a, vector<ll>& b) {
    int n = a.size();
    int m = b.size();
    int logn = 0;
    while ((1 << logn) < 2 * max(n, m))
        logn++;
    fill(ara, ara + (1 << logn), Compl(0, 0));
    fill(arb, arb + (1 << logn), Compl(0, 0));
    for (int i = 0; i < n; i++)
        ara[i] = Compl(a[i], 0);
    for (int i = 0; i < m; i++)
        arb[i] = Compl(b[i], 0);

    fft(ara, logn);
    fft(arb, logn);

    for (int i = 0; i < (1 << logn); i++)
        ara[i] = ara[i] * arb[i];

    fft(ara, logn, true);

    vector<ll> ans(1 << logn);
    for (int i = 0; i < (1 << logn); i++)
        ans[i] = round(ara[i].x);

//    for (int i = 0; i < (int)ans.size(); i++) {
//        if (ans[i] >= 10) {
//            if (i + 1 == ans.size())
//                ans.pb(0);
//            ans[i + 1] += (ans[i] / 10);
//            ans[i] %= 10;
//        }
//    }
//    while (ans.size() && ans.back() == 0)
//        ans.pop_back();
    return ans;
}

char ch[N];

void solve() {
    int tests;
    //cin >> tests;
    scanf("%d", &tests);
    vector<ll> a, b;
    while (tests--) {
        int n;
        //cin >> n;
        scanf("%d", &n);
        string s;
        //cin >> s;
        scanf("%s", ch);
        s = ch;
        a.resize(n);
        b.resize(n);
        fill(a.begin(), a.end(), 0);
        fill(b.begin(), b.end(), 0);
        for (int i = 0; i < n; i++)
            if (s[i] == 'V')
                a[i] = 1;
            else if (s[i] == 'K')
                b[n - 1 - i] = 1;
        //cout << "a: ";for (auto t: a) cout << t;cout << endl;
        //cout << "b: ";for (auto t: b) cout << t;cout << endl;
        auto c = mult(a, b);
        //cout << "mult: ";for (auto x: c) cout << x << " ";cout << endl;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            bool ok = true;
            for (int j = 1; i * j <= n - 1; j++) {
                if (c[n - 1 - i * j] || n - 1 + i * j < c.size() && c[n - 1 + i * j])
                    ok = false;
            }
            if (ok)
                ans.pb(i);
        }
        cout << ans.size() << "\n";
        for (auto x: ans)
            cout << x << " ";cout << "\n";
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    initFFT();
    //freopen("a.in", "r", stdin);
    solve();

}