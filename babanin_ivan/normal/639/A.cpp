#include <bits/stdc++.h>

#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define prev asdfsdf
#define x first
#define y second

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;

int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

struct pt {
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}

    pt operator - (const pt &r) const {
        return pt(x - r.x, y - r.y);
    }

    bool operator < (const pt &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    bool operator == (const pt &r) const {
        return x == r.x && y == r.y;
    }
};

ll cross(const pt &l, const pt &r) {
    return l.x * r.y - l.y * r.x;
}

ll dot(const pt &l, const pt &r) {
    return l.x * r.x + l.y * r.y;
}

ll pwmod(ll a, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

ll inv(ll a, ll mod) {
    return pwmod(a, mod - 2, mod);
}

const int N = 150 * 1000;
int t[N];

struct cmp {
    bool operator()(int l, int r) const {
        return t[l] < t[r];
    }
};

void solve() {
    int n = nxt();
    int k = nxt();
    int q = nxt();
    forn(i, n) t[i] = nxt();
    set<int, cmp> s;
    forn(i, q) {
        int t = nxt();
        int id = nxt() - 1;
        if (t == 1) {
            s.insert(id);
            while (s.size() > k) {
                s.erase(s.begin());
            }
        } else {
            if (s.count(id)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;//nxt();
    forn(i, t) {
        solve();
    }

    cerr << "Time " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}