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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        --x[i];
    }

    int res = n;

    vector<int> d;
    for (int i = 0; i < n - 1; ++i) {
       d.push_back(x[i + 1] - x[i] - 1);
    }
    sort(all(d));
    for (int i = 0; i < n - k; ++i) {
        res += d[i];
    }

    cout << res << endl;

}