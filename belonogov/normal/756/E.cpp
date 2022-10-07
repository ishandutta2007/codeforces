#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 3e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int SZ = 9;
const ll BASE = 1e9;

//const int SZ = 1;
//const ll BASE = 1e1;

const int MOD = 1e9 + 7;

int n;
int a[N];
int b[N];
char s[N];
ll g[N];
ll val[N];
vector<int> cnt[N];
int step[N];
int cof[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    scanf("%s", s);
}

void solve() {
    int cur = 0;
    int len = strlen(s);
    for (; cur * SZ < len; cur++) {
        int u = min(len - cur * SZ, SZ);
        for (int i = 0; i < u; i++) {
            int pos = len - cur * SZ - u + i;
            g[cur] = g[cur] * 10 + s[pos] - '0';
        }
    }
    
    //for (int i = 0; i < n; i++)
        //cerr << a[i] << " ";
    //cerr << endl;

    int m = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        for (; i + 1 < n && a[i] == 1; i++);
        i++;
        for (; j < i; j++)
            cnt[m].pb(b[j]);
        if (i < n) {
            step[m] = a[i - 1];
            //db3(m, i, a[i]);
        }
        m++;
    }

    //db(m);
    //for (int i = 0; i < m; i++) {
        //cerr << step[i] << ": ";
        //for (auto x: cnt[i])
            //cerr << x << " ";
        //cerr << endl;
    //}
    //cerr << endl;

    ll sumCoin = 0;
    for (int i = 0; i < n; i++)
        sumCoin += b[i];


    for (int i = 0; i < m; i++) {
        //db(i);
        ll rem = 0;
        //db(g[0]);

        if (i + 1 == m) {
            for (int j = cur - 1; j >= 0; j--) {
                rem = rem * BASE + g[j];
                if (rem > sumCoin) {
                    puts("0");
                    return;
                }
            }
        }
        else {
            for (int j = cur - 1; j >= 0; j--) {
                //db(step[i]);
                rem *= BASE;
                rem += g[j];
                g[j] = rem / step[i];
                rem = rem % step[i];
            }
        }
        cof[i] = rem;
        for (; cur > 0 && g[cur - 1] == 0; cur--);
    } 
    //cerr << "cof: ";
    //for (int i = 0; i < m; i++)
        //cerr << cof[i] << " ";
    //cerr << endl;
    //db(m);

    vector<int> prev;
    prev.pb(1);
    for (int i = 0; i < m; i++) {
        vector<vector<int>> dp(cnt[i].size() + 1);
        dp[0] = prev;
        //db(i);
        for (int j = 0; j < (int)cnt[i].size(); j++) {
            int sz = dp[j].size() + cnt[i][j];
            //db(sz);
            dp[j + 1].resize(sz + 1);
            vector<int> pref(dp[j].size() + 1);
            for (int t = 0; t < (int)dp[j].size(); t++) {
                pref[t + 1] = (pref[t] + dp[j][t]) % MOD;
                //db2(t + 1, pref[t + 1]);
            }
            //db2(dp.size(), j);
            for (int t = 0; t < sz; t++) {
                int l = max(0, t - cnt[i][j]);
                int r = min((int)dp[j].size(), t + 1);
                //db3(l, r, pref.size());
                //db2(j + 1, t);
                dp[j + 1][t] = (pref[r] - pref[l] + MOD) % MOD;
                //db("af");
                //db(dp[j + 1][t]);
            }
        } 

        //db("tut");
        if ((int)dp.back().size() <= cof[i]) {
            puts("0");
            return;
        }
        if (i + 1 != m) {
            prev.clear();
            for (int t = cof[i]; t < (int)dp.back().size(); t += step[i])
                prev.pb(dp.back()[t]);
        }
        else {
            printf("%d\n", dp.back()[cof[i]]);
        }
    }

}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}