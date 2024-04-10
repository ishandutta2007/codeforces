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
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 555;

int a[MAXN][MAXN];
int b[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<ll> a(n);
    ll cnt = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (2 * cnt <= a[i]) {
            ll x = cnt + (a[i] - 2 * cnt) / 3;
            ans += x;
            cnt = a[i] + cnt - 3 * x;
        } else {
            ll x = a[i] / 2;
            ans += x;
            cnt = cnt + a[i] - 3 * x;
        }
    }

    cout << ans << endl;

}