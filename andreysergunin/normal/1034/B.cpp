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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n, m;
    cin >> n >> m;

    if (n > m) {
        swap(n, m);
    }

    if (n == 1) {
        cout << (m / 6) * 6 + max(0ll, ((m % 6) - 3) * 2) << endl;
        return 0;
    }

    if (n == 2 && m == 2) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 2 && m == 3) {
        cout << 4 << endl;
        return 0;
    } 

    if (n == 2 && m == 7) {
        cout << 12 << endl;
        return 0;
    }

    if (n == 2) {
        cout << n * m << endl;
        return 0;
    }

    cout << n * m - (n * m % 2) << endl;

}