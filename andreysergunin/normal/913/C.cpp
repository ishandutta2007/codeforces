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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int n;
vector<int> c;

ll solve(ll m) {
    ll ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans += (ll)c[i] * (m / (1 << i));
        m %= (1 << i);
    }
    // cout << m << " " << ans << endl;

    return ans;

} 

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> n >> m;

    c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        if (2 * c[i] < c[i + 1]) {
            c[i + 1] = 2 * c[i];
        }
    }

    for (int i = n - 1; i >= 1; --i) {
        if (c[i] < c[i - 1]) {
            c[i - 1] = c[i];
        }
    }

    ll ans = solve(m);

    for (int i = 0; i < 30; ++i) {
        ans = min(ans, solve(((m >> i) << i) + (1 << i)) );
    }

    cout << ans << endl;



    return 0;
}