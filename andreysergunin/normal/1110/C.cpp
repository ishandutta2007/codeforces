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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;
typedef pair<ll, int> pli;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rnd(1);

map<int, int> mapa;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int n;
    cin >> n;

    vector<int> u = {1, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};
    for (int i = 1; i <= 25; ++i) {
        mapa[(1 << i) - 1] = u[i - 1];
    }

    // for (int i = 1; i <= 25; ++i) {
    //     int a = (1 << i) - 1;
    //     int res = 1;
    //     for (int b = 1; b < a; ++b) {
    //         res = max(res, __gcd(a ^ b, a & b));
    //     }
        
    //     cout << res << ", ";
    // }
    // cout << endl;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (mapa.count(a)) {
            cout << mapa[a] << endl;
            continue;
        }

        int res = 1;
        while (a > res) {
            res = res * 2 + 1;
        }
        cout << res << endl;
        // cin >> a;
        // a = i + 1;
        // int res = 1;
        // for (int b = 1; b < a; ++b) {
        //     res = max(res, __gcd(a ^ b, a & b));
        // }
        // cout << a << " " << res << endl;
    }

}