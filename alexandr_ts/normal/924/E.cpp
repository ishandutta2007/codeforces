#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e4 + 4;
ll MD;

int a[N], v[N];
ll dp[N], dp_bad[N];
bool u[N];

inline void add(ll &a, ll b) {
    a += b;
    if (a >= MD) a -= MD;
}

bool isPrime(ll x) {
    for (int i = 2; i < 100000; i++) if (x % i == 0) return false;
    return true;
}

int l1, r1;
vector<int> aa, vv;

int solve(bool D = false) {
    MD = (ll)1e18;
    MD -= rand() % 1000000;
    while (!isPrime(MD)) MD--;
    //cerr << MD << "\n";

    int n, l, r;
    if (!D) scanf("%d%d%d", &n, &l, &r);
    else {
        n = aa.size();
        l = l1;
        r = r1;
    }
    if (!D) {
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        for (int i = 0; i < n; i++) scanf("%d", v + i);
    } else {
        for (int i = 0; i < n; i++) {
            a[i] = aa[i];
            v[i] = vv[i];
        }
    }
    vector<int> bad, gud;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) bad.push_back(a[i]);
        else gud.push_back(a[i]);
    }
    for (int i = 0; i < N; i++) {
        dp[i] = 0;
        u[i] = false;
    }
    dp[0] = 1;
    u[0] = true;

    if (gud.empty()) {
        return 0;
    }

    for (int x: bad) {
        //cerr << "x " << x << "\n";
        for (int i = N - x - 1; i >= 0; i--) {
            add(dp[i + x], dp[i]);
            u[i + x] |= u[i];
        }
    }

    for (int i = 0; i < N; i++) dp_bad[i] = dp[i];

    sort(gud.begin(), gud.end());
    vector<int> nid_len = {0};
    for (int i = 0; i < (int)gud.size(); i++) {
        nid_len.push_back(nid_len[i] + gud[i]);
        //cerr << nid_len.back() << " ";
    }
    //cerr << "\n";

    int ans = 0;
    int sum = 0;

    //for (int i = 0; i < 15; i++) cerr << (int)u[i]; cerr << "\n";

    for (int gs = (int)gud.size(); gs > 0; gs--) {
        int ps = l;
        while (ps <= r && !u[ps]) ps++;
        while (r - ps >= nid_len[gs]) {
            if (!u[ps]) {
                ps++;
                continue;
            }
            int kk = gs;
            if (ps - sum < 0 || (dp[ps] != dp_bad[ps - sum])) kk++;

            //cerr << gs << " " << kk << " " << ps << " " << sum << " dpps = " << dp[ps] << " dpb = " << dp_bad[ps - sum] << "\n";

            ans = max(ans, kk);
            ps++;
        }

        int x = gud[gs - 1];
        sum += x;
        for (int i = N - x - 1; i >= 0; i--) {
            add(dp[i + x], dp[i]);
            u[i + x] |= u[i];
        }
    }

    for (int i = l; i <= r; i++) {
        if (dp_bad[i] > 0) ans = max(ans, 1);
        if (u[i] && (i < sum || dp[i] != dp_bad[i - sum])) {
            //cerr << sum << " " << i << " " << dp[i] << " " << dp[i - sum] << "\n";
            ans = max(ans, 1);
        }
    }

    return ans;
}

void genTest(int n) {
    aa.resize(n);
    vv.resize(n);
    for (int i = 0; i < n; i++) aa[i] = rand() % 5 + 1;
    for (int i = 0; i < n; i++) vv[i] = rand() % 2;
    int sum = 0;
    for (int i = 0; i < n; i++) sum += aa[i];
    int q = rand() % (sum + 1);
    int e = rand() % (sum + 1);
    l1 = min(q, e);
    r1 = max(q, e);
}

int stress() {
    int ans = 0;
    vector<int> p;
    int n = aa.size();
    for (int i = 0; i < n; i++) p.push_back(i);
    while (true) {
        int cur = 0;
        int ps = 0;
        for (int i = 0; i < n; i++) {
            int v = p[i];
            if (vv[v] == 1 && l1 <= ps && ps <= r1) cur++;
            ps += a[v];
        }
        ans = max(ans, cur);
        if (!next_permutation(p.begin(), p.end())) break;
    }
    return ans;
}

int main() {
    srand(time(NULL));
    init();
    cout << solve();
    return 0;

	int it = 0;
	while (clock() < CLOCKS_PER_SEC * 2.1) {
        int n = 7;
        genTest(n);
        it++;
        int a1 = solve(true);
        int a2 = stress();
        if (a1 != a2) {
            cout << it << "\n";
            cout << n << " " << l1 << " " << r1 << "\n";
            for (int i = 0; i < n; i++) cout << aa[i] << " "; cout << "\n";
            for (int i = 0; i < n; i++) cout << vv[i] << " "; cout << "\n";
            cout << a1 << " " << a2 << "\n";
            return 0;
        }
	}
	cout << it << " is ok\n";
    return 0;
}