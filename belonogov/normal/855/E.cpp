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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = 35;
const int INF = 1.01e9;
typedef vector<int> vi;


ll dp[N][N * 3];
ll c[N * 3][N * 3];
map<pair<pair<int,int>, int>, ll> mem;


ll calcComb(int base, int oneBit, int cntPos) {
    //db3(base, oneBit, cntPos);
    if ((oneBit + cntPos) % 2 == 1) return 0;
    auto st = make_pair(make_pair(base, oneBit), cntPos);
    if (mem.count(st) == 0) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        //db(base);
        forn(i, base) {
            for (int used = 0; used <= cntPos; used++) {
                for (int j = i < oneBit; j + used <= cntPos; j += 2) {
                    dp[i + 1][used + j] = (dp[i + 1][used + j] + dp[i][used] * c[cntPos - used][j]);
                }
            }
        } 
        //for (int i = 0; i <= base; i++, cerr << endl)
            //for (int j = 0; j <= cntPos; j++)
                //cerr << dp[i][j] << " ";
        //cerr << endl;
        mem[st] = dp[base][cntPos];
        //return dp[base][cntPos];
    }
    //db("done");
    return mem[st];
}

ll f(int base, ll r) {
    //db2(base, r);
    vector<int> b; 
    ll x = r;
    for (; x > 0; ) {
        b.pb(x % base);
        x /= base;
    }
    reverse(all(b));
    ll answer = 0;
         
    //db(sz(b));
    for (int i = 0; i < sz(b); i++) {
        for (int val = 0; val < b[i]; val++) {
            if (i == 0 && val == 0) continue;
            int mask = pw(val);
            for (int j = 0; j < i; j++) {
                mask ^= pw(b[j]);
            }
            int bit = __builtin_popcount(mask); 
            int cntPos = sz(b) - (i + 1);
            answer += calcComb(base, bit, cntPos);
            //db3(base, bit, cntPos);
            //db2(i, answer);
        }
    }
    //dbv(b);
    //db(answer);
    for (int len = 1; len < sz(b); len++) {
        answer += (base - 1) * calcComb(base, 1, len - 1);
    }
    return answer;
}


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    c[0][0] = 1;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            c[i + 1][j] += c[i][j];
            c[i + 1][j + 1] += c[i][j];
        }
    }
    //db(calcComb(2, 0, 2));
    //db(f(2, 10));
    //db(f(2, 4));
    //return 0;
    int q;
    scanf("%d", &q);
    forn(t, q) {
        ll b, l, r;
        scanf("%lld%lld%lld", &b, &l, &r);
        printf("%lld\n", f(b, r + 1) - f(b, l));
    }
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}