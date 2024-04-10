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



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, p, q, r;
    scanf("%d%d%d%d", &n, &p, &q, &r);
    vector<ll> a(n);
    forn(i, n) {
        scanf("%lld", &a[i]);
    } 
    vector<ll> pref(n); 
    vector<ll> suf(n);
    forn(i, n) {
        pref[i] = p * a[i];
        if (i > 0) {
            pref[i] = max(pref[i], pref[i - 1]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = r * a[i];
        if (i != n - 1) {
            suf[i] = max(suf[i], suf[i + 1]);
        }
    }

    ll answer = -4e18;
    forn(i, n) {
        answer = max(answer, q * a[i] + pref[i] + suf[i]);
    }

    cout << answer << endl;



    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}