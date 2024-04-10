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


ll getC(int n, int k) {
    if (k * 2 > n) return getC(n, n - k);
    ll res = 1;
    for (int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}


int f(int n) {
    vector<int> perm;
    for (int i = 0; i < n; i++) {
        perm.pb(i);
    } 
    int cnt = 0;
    do {
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            ok &= (i != perm[i]);
        }
        cnt += ok;

    } while(next_permutation(all(perm)));
    //db2(n, cnt);
    return  cnt;
}

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    ll answer = 1;
    for (int i = 2; i <= k; i++) {
        //db2(getC(n, i), f(i));
        ll F = getC(n, i) * f(i);
        //db(F);
        answer += F;
    }
    cout << answer << endl;
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}