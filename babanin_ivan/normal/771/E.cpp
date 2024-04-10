#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;

template <class T> T inline sqr(T x) {
    return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

const int N = 300500;
const int inf = 1e9;

vi64 a[2];
vi suff[2];
int n;

vi f(const vi64& a) {
    vi ans(n);
    i64 s = 0;
    map<i64, int> last;
    int l = inf;
    last[0] = n;
    for (int i = n - 1; i >= 0; --i) {
        s += a[i];
        auto it = last.find(s);
        ans[i] = l;
        if (it != last.end()) {
            if (l > it->second)
                ans[i] = l = it->second;
            it->second = i;
        } else {
            last[s] = i;
        }
    }
    ans.pb(inf);
    return ans;
}

pii d[2][N];

bool operator < (const pii& a, const pii& b) {
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se > b.se;
}

bool uax(pii& a, pii b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

void pr(const pii& a) {
    cerr << a.fi << " " << a.se << endl;
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    scanf("%d", &n);
    forn (t, 2) {
        a[t].resize(n);
        int x;
        forn (i, n) {
            scanf("%d", &x);
            a[t][i] = x;
        }
    }

    forn (t, 2)
        suff[t] = f(a[t]);
    vi64 sum(n);
    forn (i, n) sum[i] = a[0][i] + a[1][i];
    vi ssuf = f(sum);

    forn (t, 2)
        d[t][0] = mp(0, 0);

    forn (l, n + 1) {
        forn (t, 2) {
            int val = d[t][l].fi, mpos = d[t][l].se;
            //cerr << l << " " << t << " " << val << " " << mpos << " " << suff[t ^ 1][mpos] << endl;
            while (suff[t ^ 1][mpos] <= l) {
                mpos = suff[t ^ 1][mpos];
                val++;
            }
            d[t][l] = mp(val, mpos);
            uax(d[t][l + 1], d[t][l]);
            //cerr << l << " " << t << " " << suff[t][l] << " " << val << endl;
            if (suff[t][l] != inf)
                uax(d[t][suff[t][l]], mp(val + 1, mpos));
            //continue;
            if (suff[t ^ 1][mpos] != inf)
                uax(d[t ^ 1][suff[t ^ 1][mpos]], mp(val + 1, l));
            if (ssuf[l] != inf) {
                forn (nt, 2)
                    uax(d[nt][ssuf[l]], mp(val + 1, ssuf[l]));
            }
        }
    }
    //pr(d[0][1]);pr(d[1][1]);
    int ans = 0;
    forn (l, n + 1) forn (t, 2) ans = max(ans, d[t][l].fi);
    cout << ans << "\n";
    return 0;
}