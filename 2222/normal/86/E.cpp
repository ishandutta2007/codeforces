#include <algorithm>
#include <iostream>
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

int k;
ll M;
vector<ll> D;

void mul(ll *c, ll *a, ll *b) {
    memset(c, 0, k * sizeof(ll));
    REP (i, k)
        REP (j, k)
            if (a[i] & 1ll << j)
                c[i] ^= b[j];
}

void mul(ll *a, ll *b) {
    ll c[k];
    memcpy(c, a, k * sizeof(ll));
    mul(a, c, b);
}

void sqr(ll *a) {
    ll c[k];
    memcpy(c, a, k * sizeof(ll));
    mul(a, c, c);
}

int mpow(ll *A, ll n) {
    ll a[k], b[k];
    REP (i, k) {
        a[i] = A[i];
        b[i] = 1ll << i;
    }
    for (; n; n >>= 1, sqr(a))
        if (n & 1) mul(b, a);
    REP (i, k)
        if (b[i] == 0)
            return 0;
    REP (i, k)
        if (b[i] != (1ll << i))
            return -1;
    return 1;
}

bool check(ll c) {
    ll a[k];
    REP (i, k - 1)
        a[i] = 1ll << (i + 1);
    a[k - 1] = 0;
    REP (i, k) if ((c >> i) & 1)
        a[k - 1] |= 1ll << (k - 1 - i);
    if (mpow(a, M) != 1) return false;
    for (ll x : D)
        if (mpow(a, x) != -1) return false;
    return true;
}

int main(){
    #ifdef LocalHost
    freopen("x.in", "r", stdin);
    freopen("x.out", "w", stdout);
    #endif
    cin >> k;
    M = (1ll << k) - 1;
    ll x = rand();
    for (ll i = 2; i * i <= M; ++i)
        if (M % i == 0) {
            D.pb(i);
            if (i * i != M) D.pb(M / i);
        }
    for (; ; ) {
        x = (x * 98723472623985767 ^ rand()) & M;
        ll y = x | (1 << (k - 1));
        if (check(y)) {
            REP (i, k) {
                if (i) putchar(' ');
                cout << ((y >> i) & 1);
            }
            puts("");
            REP (i, k) {
                if (i) putchar(' ');
                cout << 1;
            }
            return 0;
        }
    }
    return 0;
}