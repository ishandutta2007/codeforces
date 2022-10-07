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
const int N = 1e6 + 1000;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MOD = 1e9 + 7;
const int K = 22;

int n;
int r[N];
int c[N];
int d[N];
ll fact[N];
ll revf[N];
int deg[N];
int cur;
ll answer;
ll prec[N];
ll dpc[N][K];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &r[i], &c[i]);
    }
}

ll rev(ll a, ll m) {
    if (m == 1) return 0;
    return ((1 - rev(m % a, a) * m) / a + m) % m;
}

ll getC(int nn, int kk) {
    //db2(nn, kk);
    //assert(nn >= 0 && kk >= 0);
   //assert(kk <= nn);
    //return fact[nn] * revf[kk] % MOD * revf[nn - kk] % MOD;
    return dpc[nn][kk];
}

void upd(ll & a, ll b) {
    a = (a + b) % MOD;
    //a += b;
    //if (a >= MOD) 
        //a -= MOD;
}

void rec(int pos, ll x, int len) {
    //db3(pos, x, cc);
    if (pos == cur) {
        //db2(x, pw(cc));
        //answer = (answer + x) % MOD;        
        upd(answer, x);
        return;
    }
    //db(len);
    //db(deg[pos]);
    for (int j = 0; j < deg[pos]; j++) {
        rec(pos + 1, (x * getC(len + j - 1, j) * 2) % MOD, len);
    }
    rec(pos + 1, (x * getC(len + deg[pos] - 1, deg[pos])) % MOD, len);
}


void solve() {
    dpc[0][0] = 1;
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < K - 1; j++) {
            upd(dpc[i + 1][j], dpc[i][j]);
            upd(dpc[i + 1][j + 1], dpc[i][j]);
        }
    vector<int> pr;
    for (int i = 2; i < N; i++) {
        if (d[i] == 0) {
            d[i] = i;
            pr.pb(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] * i < N && pr[j] <= d[i]; j++) 
            d[pr[j] * i] = pr[j];
    }

    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    revf[N - 1] = rev(fact[N - 1], MOD);
    //db(revf[N - 1] * fact[N - 1] % MOD);
    for (int i = N - 2; i >= 0; i--) {
        revf[i] = (revf[i + 1] * (i + 1)) % MOD;
    }
    //for (int i = 0; i < 30; i++)
        //db2(fact[i], revf[i]);

    for (int i = 1; i <= 10; i++)
        assert(fact[i] * revf[i] % MOD == 1);

    cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    for (int i = 0; i < n; i++) {
        int x = c[i];
        cur = 0;
        for (; x > 1; ) {
            int cnt = 0; 
            int dd = d[x];
            for (; dd == d[x]; cnt++, x /= dd);
            deg[cur++] = cnt;
        }
        answer = 0;
        if (r[i] != 0)  {
            answer = 1;
            for (int j = 0; j < cur; j++) {
                //db2(c[i], deg[i]);
                //db2(c[i] + 1 + deg[j] - 1, deg[j]);
                answer = answer * (getC(r[i] + 1 + deg[j] - 1, deg[j]) * 2 - getC(r[i] + deg[j] - 1, deg[j]) + MOD) % MOD;
            }

        }
        else {
            answer = pw(cur);
        }
        printf("%d\n", (int)answer);
    }

}

void stress() {

}

int main(){
#ifdef HOME 
    //freopen("in", "r", stdin);
    freopen("test.txt", "r", stdin);
    freopen("out", "w", stdout);
#endif
    if (1) {
        read();
        solve();
        cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    }
    else {
        stress();
    }

    return 0;
}