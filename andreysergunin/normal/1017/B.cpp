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

mt19937 rnd(random_device{}());

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    ll n;
    cin >> n;

    string s, t;    
    cin >> s;
    cin >> t;

    ll a = 0, b = 0, c = 0, d = 0;

    for (int i = 0; i < n; ++i) {
        a += (s[i] == '0');
        b += (s[i] == '1');
        c += (s[i] == '0' && t[i] == '1');
        d += (s[i] == '1' && t[i] == '1');
    }

    ll ans = (n - 1) * n / 2 - ((a - 1) * a / 2 + (b - 1) * b / 2 + c * d);

    cout << ans << endl;

    return 0;
}