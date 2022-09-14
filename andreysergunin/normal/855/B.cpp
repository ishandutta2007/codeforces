#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const ll INF = 4e18;

int main() {
    //freopen("comb.in", "r", stdin);
    //freopen("comb.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll p, q, r;
    cin >> n >> p >> q >> r;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> pref(n), suff(n);

    ll ans = -INF;
    for (int i = 0; i < n; ++i) {
        pref[i] = a[i] * p;
        if (i > 0) {
            pref[i] = max(pref[i], pref[i - 1]);
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        suff[i] = a[i] * r;
        if (i < n - 1) {
            suff[i] = max(suff[i], suff[i + 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        ans = max(ans, pref[i] + a[i] * q + suff[i]);
    }

    cout << ans << endl;
}