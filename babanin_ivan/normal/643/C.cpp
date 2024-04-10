#include <bits/stdc++.h>

#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define clr(x) memset(x, 0, sizeof(x))
#define pb push_back
#define mp make_pair
#define prev asdfsdf
#define fi first
#define se second

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;

#define x first
#define y second

int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

template <class T>
T sqr(T a) {
    return a * a;
}

typedef pair<ld, ld> pt;

bool isPop(const pt &a, const pt &b, const pt &c) {
    ld u = (b.x - a.x) * (c.y - a.y);
    ld v = (c.x - a.x) * (b.y - a.y);
    return u - v <= 0;
}


ld value(ld m, ld b, ld x) {
    return m * x + b;
}

bool check(const pt &a, const pt &b, ld x) {
    return value(a.y, a.x, x) >= value(b.y, b.x, x);
}


struct Hull {
    vector<pt> st;
    int id;
    Hull() : id(0) {}

    void add(pt a) {
        while (st.size() > 1 && isPop(st[st.size() - 2], st[st.size() - 1], a)) {
            st.pop_back();
        }
        if (!st.empty() && st.back().y == a.y) {
            st.back().x = min(st.back().x, a.x);
            return;
        }
        st.push_back(a);
    }

    ld getMin(ld x) {
        if (st.empty()) return 1e30;
        id = min(id, (int)st.size() - 1);
        while (id + 1 < (int)st.size() && check(st[id], st[id + 1], x)) {
            ++id;
        }
        return st[id].x + x * st[id].y;
    }
};

const int N = 2000 * 100 + 10;
ld t[N];
ld ti[N];
ld s[N];
ld si[N];
ld qw[N];
Hull hull[51];

void solve() {
    int n = nxt();
    int k = nxt();
    forn(i, n) {
        t[i] = nxt();
    }
    forn(i, n) {
        ti[i] = 1 / t[i];
    }
    s[0] = 0;
    forn(i, n) {
        s[i + 1] = s[i] + t[i];
    }
    si[n] = 0;
    forn(i, n) {
        si[n - 1 - i] = si[n - i] + ti[n - i - 1];
    }
    forn(i, n) {
        qw[n - 1 - i] = qw[n - i] + t[i] * (si[i]);
    }
    hull[0].add(pt(qw[0], -s[0]));
    forn(i, n) {
        ford(j, k) {
            ld ca = hull[j].getMin(-si[i + 1]) - qw[i + 1] - si[i + 1] * s[i + 1];
            hull[j + 1].add(pt(ca + qw[i + 1], -s[i + 1]));
        }
    }
    cout << setprecision(10) << fixed;
    cout << hull[k - 1].getMin(-si[n]) - qw[n] - si[n] * s[n] << "\n";
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("errput.txt", "w", stderr);
#endif
    //forn(t, 10) test(4); cerr << clock() * 1./ CLOCKS_PER_SEC << endl; return 0;
    int t = 1;
    while (t--) solve();

    return 0;
}