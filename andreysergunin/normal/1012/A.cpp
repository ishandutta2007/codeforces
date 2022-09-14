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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const ll INF = 2e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;   

    vector<ll> a(2 * n);

    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    sort(all(a));

    ll ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);

    ll curmin = INF;

    for (int i = 1; i < n; ++i) {
        curmin = min(curmin, a[i + n - 1] - a[i]);
    }

    ans = min(curmin * (a[2 * n - 1] - a[0]), ans);

    cout << ans << endl;
    return 0;
}