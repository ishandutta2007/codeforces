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



int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    ll n, l;
    scanf("%lld%lld", &n, &l);
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
    }
    n = 32;
    for (;sz(c) < n;) {
        c.pb(c.back() * 2);
    }
    for (int i = 0; i < n - 1; i++) {
        c[i + 1] = min(c[i + 1], c[i] * 2);
    }
    for (int i = n - 1; i > 0; i--) {
        c[i - 1] = min(c[i - 1], c[i]);
    }
    ll answer = 1e18;
    ll sum = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (pw(i) & l) {
            answer = min(answer, sum + c[i + 1]);
            sum += c[i];
        }
    }
    answer = min(answer, sum);

    cout << answer << endl;






    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}