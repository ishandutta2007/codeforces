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
#define forn(i, n) for (int i = 0; i < (n); i++)
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



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> data(pw(k));
    forn(i, n) {
        int mask = 0;
        forn(j, k) {
            int x;
            scanf("%d", &x);
            if (x == 0) {
                mask |= pw(j); 
            }
        }
        data[mask] = 1;
    }
    vector<int> sum(k);
    
    forn(mask, pw(pw(k))) {
        if (mask == 0) continue;
        bool ok = 1;
        forn(i, pw(k)) {
            if (mask & pw(i))
                ok &= data[i];
        }
        if (ok) {
            sum.assign(k, 0); 
            forn(i, pw(k)) {
                if (mask & pw(i)) {
                    forn(j, k) {
                        if (i & pw(j)) {
                            sum[j]++;
                        }
                        else {
                            sum[j]--;
                        }
                    }
                }
            }
            bool allPos = 1;
            for (auto x: sum) {
                allPos &= x >= 0;
            }
            if (allPos) {
                puts("YES");
                return 0;
            }
        }
    }

    puts("NO");
    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}