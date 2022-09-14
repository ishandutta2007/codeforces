#pragma GCC optimize("Ofast", "unroll-loops")

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

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;
using Complex = complex<double>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif  
        
    int n;
    cin >> n;
    string s;
    cin >> s;


    vector<int> st(n);
    for (int i = 0; i < n; ++i) {
        st[i] = s[i] - '0';
    }   
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    int res = 0;

    for (int t = 1; t <= 1000; ++t) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += st[i];
        }
        res = max(res, cur);

        for (int i = 0; i < n; ++i) {
            if (t >= b[i] && (t - b[i]) % a[i] == 0) {
                st[i] ^= 1;
            }
        }
    }   

    cout << res << endl;;




#ifdef LOCAL
    cerr << "Time: " << ld(clock()) / CLOCKS_PER_SEC << endl;
#endif
}