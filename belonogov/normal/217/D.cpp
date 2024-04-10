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
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;
typedef bitset<128> state;
const int MOD = 1e9 + 7;



int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
    //freopen("test.txt", "r", stdin);
#endif
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t); 
    vector<int> cnt(m / 2 + 1);
    for (int i = 0; i < t; i++) {
        int x;
        scanf("%d", &x);
        x %= m;
        //if (x >= (m + 1) / 2) {
        if (x >= m / 2 + 1) {
            x = m - x;
        }
        cnt[x]++;
    }
    ll answer = 0;
    function<void(state, int, ll)> rec = [&](state st, int pos, ll comb) {
        //db3(st, pos, comb);
        if (pos == m / 2 + 1) {
            answer = (answer + comb) % MOD;
            return;
        }
        rec(st, pos + 1, comb);
        if (st[pos] == 0 && cnt[pos] > 0) {
            state tmp = st;
            tmp |= (st << pos);
            tmp |= (st >> pos);
            tmp |= (st << (m - pos));
            tmp |= (st >> (m - pos));
            rec(tmp, pos + 1, comb * cnt[pos] % MOD);
        }
    };
    //dbv(cnt);

    state nst;
    nst[0] = 1;
    rec(nst, 0, 1);
    

    //db2(total, answer);
    cout << answer << endl;
    //cout << (total - answer + MOD) % MOD << endl;

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}