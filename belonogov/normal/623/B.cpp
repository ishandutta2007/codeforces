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


long long n, a, b;
int c[N];
long long cost[N];
long long dp[N][2];

void read() {
    scanf("%lld%lld%lld", &n, &a, &b);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
}

set < int > q;

void add(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            q.insert(i);
        for (; x % i == 0; x /= i);
    }
    if (x > 1)
        q.insert(x);
}


long long solve() {
    add(c[0]);
    add(c[0] - 1);
    add(c[0] + 1);
    add(c[n - 1]);
    add(c[n - 1] - 1);
    add(c[n - 1] + 1);

    long long answer = 1e18;
    for (int tt = 0; tt < 2; tt++) {

        for (auto p: q) {
            //p = 2;
            memset(cost, -1, sizeof(cost));
            for (int i = 0; i < n; i++) {
                if (c[i] % p == 0)
                    cost[i] = 0;
                else {
                    if ((c[i] + 1) % p == 0 || (c[i] - 1) % p == 0)
                        cost[i] = 1;
                }
            }
            //for (int i = 0; i < n; i++)
                //cerr << cost[i] << " ";
            //cerr << endl;
            memset(dp, 63, sizeof(dp));
            dp[0][0] = 0;  
            for (int i = 0; i < n; i++) {
                dp[i + 1][1] = min(dp[i + 1][1], min(dp[i][0], dp[i][1]) + a);
                if (cost[i] == 0 || cost[i] == 1)
                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + cost[i] * b);
            }
            //for (int j = 0; j < 2; j++, cerr << endl)
                //for (int i = 0; i <= n; i++)
                    //cerr << dp[i][j] << " ";
            int cnt = 0; 
            for (int i = n - 1; i >= 0; i--) {
                if (cost[i] == -1) break;
                cnt += cost[i];
                answer = min(answer, min(dp[i][0], dp[i][1]) + cnt * 1ll * b);
            }
            //db(answer);
            //exit(0);
        }
        reverse(c, c + n);
    }
    return answer;

}


void printAns(long long answer) {
    printf("%lld\n", answer);
}

void genTest() {
    n = rand() % 10 + 1;
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;
    int T = 10;
    for (int i = 0; i < n; i++)
        c[i] = rand() % T + 2;
}

long long answerS;
int tmp[N];
vector < int > g;
int lenA;

void rec(int pos, int nn) {
    if (pos == nn) {
        int cnt = 0;
        for (int i = 0; i < nn; i++)
            cnt += abs(tmp[i]); 
        assert(nn == (int)g.size()); 
        vector < int > gg;
        for (int i = 0; i < nn; i++)
            gg.pb(g[i] + tmp[i]);
        int d = gg[0];
        for (int i = 0; i < nn; i++)
            d = __gcd(d, gg[i]);
        if (d > 1) {
            //db2(cnt, lenA);
            answerS = min(answerS, cnt * 1ll * b + lenA * 1ll *  a);
        }
        return;
    }
    for (int t = -1; t <= 1; t++) {
        tmp[pos] = t;
        rec(pos + 1, nn);
    }
}

void go(vector < int > data) {
    g = data;
    //db("go");
    //for (auto x: data)
        //cerr << x << " ";
    //cerr << endl;

    rec(0, data.size());
}

long long stupid() {
    answerS = 1e18;
    lenA = 0;
    vector < int > tmp;
    for (int i = 0; i < n; i++)
        tmp.pb(c[i]);
    go(tmp);

    for (int l = 0; l < n; l++)
        for (int len = 1; len < n; len++) {
            lenA = len;
            vector < int > tmp;
            for (int i = 0; i < n; i++) {
                if (i < l || l + len <= i)
                    tmp.pb(c[i]);
            }
            go(tmp);
        }

    return answerS;
}


void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        auto r1 = solve();
        auto r2 = stupid();
        db2(r1, r2);
        assert(r1 == r2);
    }

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            printAns(solve());
            //printAns(stupid());
        }
    }
    else {
        stress();
    }

    return 0;
}