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

int s(ll n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;

    ll res = -1;

    for (int mask = 0; mask < (1 << 13); ++mask) {
        ll k = 0;
        for (int i = 0; i < 13; ++i) {
            k *= 10;
            k += (mask & (1 << i) ? 0 : 9);
        }

        if (k <= n) {
            if (res < s(k) + s(n - k)) {
                res = s(k) + s(n - k);
            }
        }
    }  
    assert(res >= 0); 
    cout << res << endl;
}