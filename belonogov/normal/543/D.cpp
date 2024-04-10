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

#define equal equalll
#define less lesss
const int N = 3e5 + 10;
const int INF = 1e9 + 19;
const int MOD = 1e9 + 7;

int n;
vector < int > e[N];
long long answer[N];
long long dp[N];
bool use[N];

void read() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d ", &x); x--;
        e[i].pb(x);
        e[x].pb(i);
    }

}

long long binPow(long long a, long long b) {
    assert(0 < a && a < MOD);
    long long ans = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1)
            ans = (ans * a) % MOD; 
        a = (a * a) % MOD;
    }
    return ans;
}

void dfs0(int v) {
    use[v] = 1;
    long long mul = 1;
    for (auto u: e[v])  {
        if (!use[u])  {
            dfs0(u);
            mul = (mul * (dp[u] + 1)) % MOD;
        }
    }
    dp[v] = mul;
}

void dfs1(int v, long long cnt) {
    //db2(v, cnt);
    int cnt0 = 0;
    use[v] = 1;
    vector < long long > all;
    all.pb((cnt + 1) % MOD);
    for (auto u: e[v]) 
        if (!use[u])  {
            all.pb((dp[u] + 1) % MOD);
        }
    long long res = 1;
    for (auto x: all) {
        cnt0 += x == 0;
        res = (res * x) % MOD;
    } 
    answer[v] = res;  
    for (auto u: e[v]) 
        if (!use[u]) {
            long long val;
            if (cnt0 >= 2)
                val = 0;
            else if (cnt0 == 0) 
                val = (res * binPow(dp[u] + 1, MOD - 2)) % MOD;
            else {
                assert(cnt0 == 1);
                if ((dp[u] + 1) % MOD == 0) {
                    long long R = 1; 
                    for (auto x: all)
                        if (x != 0)
                            R = (x * R) % MOD;
                    val = R;
                }
                else
                    val = 0;
            }
            dfs1(u, val);
        }
}

vector < long long > solve(int v) {
    memset(use, 0, sizeof(use));
    dfs0(v);
    memset(use, 0, sizeof(use));
    //for (int i = 0; i < n; i++)
        //cerr << dp[i] << " ";
    //cerr << endl;
    dfs1(v, 0); 
    vector < long long > r(n); 
    for (int i = 0; i < n; i++)
        r[i] = answer[i];
    //if (rand() % 20 == 0)
        //r[0]++;
    return r;
}

void printAns() {
    for (int i = 0; i < n; i++)
        cout << answer[i] << " ";
    cout << "\n";

}

void genTest() {
    n = 100;
    for (int i = 0; i < n; i++)
        e[i].clear();
    
    for (int i = 1; i < n; i++) {
        int v = rand() % i;
        e[i].pb(v);
        e[v].pb(i);
    }
}


void printTest() {
    for (int v = 0; v < n; v++)
        for (auto u: e[v])
            if (v > u)
                cerr << v << " " << u << endl;
}

void stress() {
    for (int tt = 0; ;tt++) {
        cerr << "test id: " << tt << endl;
        genTest();
        int v = rand() % n;
        int u = rand() % n;
        vector < long long > r1 = solve(v);
        vector < long long > r2 = solve(u);
        db2(v, u);
        if (r1 != r2) {
            for (auto x: r1)
                cerr << x << " ";
            cerr << endl;
            for (auto x: r2)
                cerr << x << " ";
            cerr << endl;
            printTest();

        }
        for (int i = 0; i < n; i++) {
            assert(0 <= r1[i] && r1[i] < MOD);
            assert(r1[i] == r2[i]);
        }

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
            //solve(0);
            //printAns();
            solve(1);
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}