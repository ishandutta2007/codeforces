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

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(all(a));

    int q;
    cin >> q;   

    vector<ll> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = a[i + 1] - a[i];
    }
    sort(all(d));

    // for (int i = 0; i < sz(d); ++i) {
    //     cout << d[i] << " ";
    // }
    // cout << endl;


    vector<ll> res(n);
    for (int j = 0; j < n - 1; ++j) {
        res[j + 1] = res[j] + (d[j] - (j == 0 ? 0 : d[j - 1])) * (n - j);
    }
    

    // for (int i = 0; i < sz(res); ++i) {
    //     cout << res[i] << " ";
    // }
    // cout << endl;



    for (int i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        r -= l;
        ++r;

        int id = lower_bound(all(d), r) - d.begin();

        ll ans = res[id] + (n - id) * (r - (id == 0 ? 0 : d[id - 1]));

        cout << ans << " ";
    }
    cout << endl;

}