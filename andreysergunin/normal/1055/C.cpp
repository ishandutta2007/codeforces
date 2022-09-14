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
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

ll intersect(int l1, int r1, int l2, int r2) {
    if (r2 < l1 || r1 < l2) {
        return 0;
    }

    return min(r1, r2) - max(l1, l2) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll l[2], r[2], t[2], len[2];

    for (int i = 0; i < 2; ++i) {
        cin >> l[i] >> r[i] >> t[i];
        len[i] = r[i] - l[i];
    }

    ll g = __gcd(t[0], t[1]);

    for (int i = 0; i < 2; ++i) {
        l[i] %= g;
        r[i] = l[i] + len[i];
    }

    ll res = 0;
    for (ll d = -1; d <= 1; ++d) {
        res = max(res, intersect(l[0], r[0], l[1] + g * d, r[1] + g * d));
    }

    cout << res << endl;
        





}