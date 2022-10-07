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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e18 + 19;
const int T = 3;

long long data[N * 4][T][T];

int n, q;
pair < long long , int > w[N];
pair < long long , int > h[N];
int p[N];
int fact[N];
int perm[N];
long long dp[N];
pair < int, int > query[N];

void read() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%lld", &w[i].fr);
    for (int i = 0; i < n; i++)
        scanf("%lld", &h[i].fr);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &query[i].fr, &query[i].sc);
        query[i].fr--;
        query[i].sc--;
    }
}

void upd(long long & a, long long b) {
    a = max(a, b);
}

long long stupidSolve(int l, int r) {
    //db2(l, r);
    assert(l <= r);
    assert(0 <= l && r <= n);
    int len = r - l;
    for (int i = 0; i <= len; i++)
        dp[i] = (i == 0)? 0: -INF;
    for (int i = 0; i < len; i++) {
        for (int step = 1; i + step <= len && step <= T; step++) {
            for (int j = 0; j < step; j++)
                perm[j] = j; 

            //db2(step, fact[step]);
            for (int tt = 0; tt < fact[step]; tt++) {
                long long sum = 0; 
                bool flag = 1;
                for (int j = 0; j < step; j++) {
                    int from = l + i + j;
                    int to = perm[j] + l + i;
                    if (p[from] == to) {
                        flag = 0;
                        break;
                    }
                    //db2(i + l + j, l + i + perm[j]);
                    sum += w[from].fr * h[to].fr;
                }
                if (flag) {
                    //db2("here", sum);
                    upd(dp[i + step], dp[i] + sum);
                }
                next_permutation(perm, perm + step);
            }
        }
    }
    return dp[len];
}

void clear(int v) {
    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++)
            data[v][i][j] = 0;
}
 
void reCalc(int v, int ll, int rr) {
    clear(v);
    int mid = (ll + rr) / 2;
    for (int l1 = 0; l1 < T; l1++)
        for (int l2 = 0; l2 < T; l2++)
            for (int r1 = 0; r1 < T; r1++)
                for (int r2 = 0; r2 < T; r2++) {
                    //db("here");
    upd(data[v][l1][r2], data[v * 2 + 1][l1][r1] + data[v * 2 + 2][l2][r2] + stupidSolve(mid - r1, mid + l2));
                }

}

void lowUpd(int v, int ll, int rr) {
    //assert(rr - ll >= 4);
    for (int left = 0; left < T; left++)
        for (int right = 0; right < T; right++) {
            data[v][left][right] = stupidSolve(ll + left, rr - right);
        } 
}

bool checkSmall(int ll, int rr) {
    int len = rr - ll;
    if (len / 2 < (T - 1) * 2) return 1;
    return 0;
}

void upd(int v, int ll, int rr, int pos) {
    //assert(rr -
    if (pos < ll || rr <= pos) return;
    if (checkSmall(ll, rr)) {
        lowUpd(v, ll, rr);
        return;
    }

    upd(v * 2 + 1, ll, (ll + rr) / 2, pos);
    upd(v * 2 + 2, (ll + rr) / 2, rr, pos);
    reCalc(v, ll, rr);
}


void build(int v, int ll, int rr) {
    //cerr << "v ll rr: " << v << " " << ll << " " << rr << endl;
    //assert(v >= 0);
    if (checkSmall(ll, rr)) {
        lowUpd(v, ll, rr); 
        return;
    }
    build(v * 2 + 1, ll, (ll + rr) / 2);
    build(v * 2 + 2, (ll + rr) / 2, rr);
    
    reCalc(v, ll, rr);
   
}

vector < long long > solve() {

    for (int i = 0; i < n; i++) {
        w[i].sc = i;
        h[i].sc = i;
    }
    sort(w, w + n);
    sort(h, h + n); 
    vector < int > revH(n), revW(n);

    for (int i = 0; i < n; i++) {
        revW[w[i].sc] = i;
        revH[h[i].sc] = i;
    }
    for (int i = 0; i < n; i++) {
        p[revW[i]] = revH[i];        
    }
    //for (int i = 0; i < n; i++)
       //cerr << w[i].fr << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++)
       //cerr << h[i].fr << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++)
       //cerr << p[i] << " ";
    //cerr << endl;
    

    //cerr << stupidSolve(0, n) << endl;
    //exit(0); 

    //db("here");
    if (n >= 4)
        build(0, 0, n);
    //db("here");

    vector < long long > answer;
    //db(data[0][0][0]);
    //exit(0);
    for (int i = 0; i < q; i++) {
        int v, u;
        //scanf("%d%d", &v, &u); v--; u--;
        v = query[i].fr;
        u = query[i].sc;
        v = revW[v];
        u = revW[u];
        swap(p[v], p[u]);
        if (n >= 4) {
            upd(0, 0, n, v);
            upd(0, 0, n, u);
        }
        long long res = data[0][0][0];
        //db2(res, r2);
        //assert(res == r2);
        if (n < 4) {
            long long r2 = stupidSolve(0, n);
            answer.pb(r2);
        }
        else
            answer.pb(res);
    }

    return answer;
}

void printAns(vector < long long > ans) {
    for (auto x: ans)
        printf("%lld\n", x);
}

bool cmpId(pair < long long, int > a, pair < long long, int > b) {
    return a.sc < b.sc;
}

void printTest() {
    cout << n << " " << q << endl;
    sort(w, w + n, cmpId);
    sort(h, h + n, cmpId);
    for (int i = 0; i < n; i++) 
        cout << w[i].fr << " "; 
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << h[i].fr << " "; 
    }
    cout << endl;
    for (int i = 0; i < q; i++)
        cout << query[i].fr + 1 << " " << query[i].sc + 1 << endl;

}

void genTest() {
    n = 100;
    q = 30;
    int T = 20;
    for (int i = 0; i < n; i++) {
        w[i].fr = rand() % T + 1;
        h[i].fr = rand() % T + 1;
    }
    sort(w, w + n);
    sort(h, h + n);
    for (int i = 0; i < q; i++)  {
        query[i].fr = rand() % n;
        query[i].sc = rand() % n;
    }
}

void stress() {
    for (int tt = 0; ;tt++) {
        cerr << "test id: " << tt << endl;
        genTest();
        //printTest();
        solve();
    }
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    fact[0] = 1;
    for (int i = 0; i < 10; i++)
        fact[i + 1] = fact[i] * (i + 1);
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            printAns(solve());
        }
    }
    else {
        stress();
    }

    return 0;
}