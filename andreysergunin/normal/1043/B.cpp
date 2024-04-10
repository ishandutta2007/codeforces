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

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> res;

    for (int k = 1; k <= n; ++k) {
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (i - k - 1 < 0) {
                continue;
            }
            if (a[i] - a[i - 1] != a[i - k] - a[i - k - 1]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            res.push_back(k);
        }
    }

    cout << sz(res) << endl;
    for (int el : res) {
        cout << el << " ";
    }
    cout << endl;
}