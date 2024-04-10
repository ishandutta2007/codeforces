#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;

template <class T> T inline sqr(T x) {
    return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;


const int N = 1 << 14;

int popcnt(int x) {
    int r = 0;
    while (x) {
        r += (x & 1);
        x >>= 1;
    }
    return r;
}

int main()
{
    int n = 100000, k = 7;
    scanf("%d%d", &n, &k);
    vi a(n);
    vector<i64> q(N);
    forn (i, n) {
        //a[i] = rand() % 10001;
        scanf("%d", &a[i]);
        q[a[i]]++;
    }
    vi pk;
    forn (i, N)
        if (popcnt(i) == k) {
            pk.pb(i);
        }
    i64 ans = 0;
    if (!k) {
        forn (i, N)
            ans += q[i] * (q[i] - 1) / 2;
        cout << ans << "\n";
        return 0;
    }

    forn (i, N)
        if (q[i]) {
            int z = 0;
            for (int x: pk) {
                int y = x ^ i;
                z += q[y];
            }
            ans += z * q[i];
        }
    cout << ans / 2 << "\n";
    return 0;
}