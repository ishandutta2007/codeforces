#pragma comment (linker, "/STACK:128000000")
#include <iostream> 
#include <cstdio> 
#include <fstream>
#include <functional>
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout); 
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;
    
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

const li mod = 1000000007;

li bpow(li x, li y) {
    if (y == 0) {
        return 1;
    }
    li res = bpow(x, y / 2);
    res = (res * res) % mod;
    if (y & 1) {
        res = (res * x) % mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector <li> fact(n + 10);
    vector <li> revfact(n + 10);

    fact[0] = 1;
    revfact[0] = 1;
    for (int i = 1; i < fact.size(); ++i) {
        fact[i] = (fact[i - 1] * li(i)) % mod;
        revfact[i] = bpow(fact[i], mod - 2);
    }

    vector <li> b(n + 1);
    b[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k < i; ++k) {
            b[i] = (b[i] + (((b[k] * fact[i - 1]) % mod) * revfact[i - 1 - k]) % mod * revfact[k]) % mod;
        }
    }

    li ans = 0;

    for (int i = 1; i <= n; ++i) {
        ans += (((b[n - i] * fact[n]) % mod) * revfact[n - i]) % mod * revfact[i] % mod;
        ans %= mod;
    }
    cout << ans << endl;
}