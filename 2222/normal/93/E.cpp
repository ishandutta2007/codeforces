#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)          (a).begin(), (a).end()
#define sz(a)           int((a).size())
#define FOR(i, a, b)    for (int i(a); i < b; ++i)
#define REP(i, n)       FOR(i, 0, n)
#define UN(v)           sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)        memset(a, b, sizeof a)
#define pb              push_back
#define X               first
#define Y               second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int U = 80;
const int L = 20000;

ll n;
int m, a[111];

int F[U][L];

int f0(int n, int i) {
    if (n == 0 || i < 0) return n;
    int &res = F[i][n];
    if (res < 0) {
        res = n;
        for (; i >= 0; --i)
            res -= f0(n / a[i], i - 1);
    }
    return res;
}

ll f(ll n, int i) {
    if (n == 0) return 0;
    if (i < U && n < L) return f0(n, i);
    ll res = n;
    for (; i >= 0; --i)
        res -= f(n / a[i], i - 1);
    return res;
}

int main(){
    #ifdef LocalHost
    freopen("x.in", "r", stdin);
    freopen("x.out", "w", stdout);
    #endif
    CL(F, -1);
    cin >> n >> m;
    REP (i, m) cin >> a[i];
    sort(a, a + m);
    cout << f(n, m - 1) << endl;
    return 0;
}