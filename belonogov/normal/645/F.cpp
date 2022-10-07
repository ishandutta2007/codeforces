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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;
const int T = 1e6;

int n, k, q;
int cof[N];
long long fact[N];
long long rfact[N];
int all;
long long answer;
int lp[N];
vector < int > pr;
pair < int, int > b[N];
int cc;
int cnt[N];

void read() {
    scanf("%d%d%d", &n, &k, &q);
    all = n + q;
}

long long rev(long long a, long long m) {
    if (a == 0) return 0;
    return ((1 - rev(m % a, a) * m) / a + m) % m;
}


void genAll(int pos, int x, int cur) {
    if (pos == cur) {
        cc -= cof[x];
        return;
    }
    for (int i = 0; i <= b[pos].sc; i++) {
        genAll(pos + 1, x, cur); 
        x *= b[pos].fr;
    }
}

long long getC(int n) {
    if (n < k) return 0;
    assert(fact[n] != 0);
    //assert(rfact[k] != 0);
    //assert(rfact[n - k] != 0);
    return fact[n] * rfact[k] % MOD * rfact[n - k] % MOD;
}

void genAll2(int pos, int x, int cur) {
    if (pos == cur) {
        answer = (answer - getC(cnt[x]) * 1ll * cof[x] % MOD + MOD) % MOD;
        cnt[x]++;
        answer = (answer + getC(cnt[x]) * 1ll * cof[x] % MOD + MOD) % MOD;
        return;
    }
    for (int i = 0; i <= b[pos].sc; i++) {
        genAll2(pos + 1, x, cur);
        x *= b[pos].fr;
    }
}


int cur;
void toPrime(int x) {
    cur = 0; 
    int prev = -1;
    int cnt = 0;
    for (; x > 1; ) {
        if (lp[x] != prev) {
            if (cnt > 0)
                b[cur++] = mp(prev, cnt);
            prev = lp[x];
            cnt = 0;
        }
        cnt++;
        x = x / lp[x];
    } 
    if (cnt > 0)
        b[cur++] = mp(prev, cnt);
}

void add(int x) {
    toPrime(x);
    genAll2(0, 1, cur);
    
}

void solve() {
    fact[0] = 1;
    for (int i = 1; i <= all; i++)
        fact[i] = fact[i - 1] * i % MOD;
    rfact[all] = rev(fact[all], MOD);
    //db2(all, rfact[all]);
    for (int i = all - 1; i >= 0; i--)
        rfact[i] = (rfact[i + 1] * (i + 1)) % MOD;

    for (int i = 2; i <= T; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.pb(i);
        }  
        for (int j = 0; j < (int)pr.size() && lp[i] >= pr[j] && i * pr[j] <= T; j++)
            lp[i * pr[j]] = pr[j];
    }
    //for (int i = 0; i < 10; i++)
        //cerr << pr[i] << " ";
    //cerr << endl;
    for (int i = 1; i <= T; i++) {
    //for (int i = 1; i <= 10; i++) {
        toPrime(i);
        cc = i;
        //db(i);
        //for (int j = 0; j < cur; j++)
            //db2(b[j].fr, b[j].sc);
        //cerr << endl;
        genAll(0, 1, cur);
        cof[i] = cc;
    }
    //for (int i = 1; i <= 10; i++)
        //db2(i, cof[i]);


    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        add(x);
    }
    for (int i = 0; i < q; i++) {
        int x; 
        scanf("%d", &x);
        add(x);
        printf("%lld\n", answer);
    }

    //for (int i = 1; i <= 10; i++)
        //db2(i, cnt[i]);
    //for (int i = 1; i <= 10; i++)
        //db2(i, getC(cnt[i]));
    //for (int i = 1; i <= 10; i++)
        //db2(i, cof[i]);

    //for (int i = 1; i <= 10; i++)
        //db2(i, rfact[i]);
    


    //db2(getC(4), getC(3));


}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
        }
    }
    else {
        stress();
    }

    return 0;
}