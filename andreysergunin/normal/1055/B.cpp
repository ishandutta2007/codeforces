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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int n, m, l;
    cin >> n >> m >> l;

    vector<ll> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > l) {
            ++res;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > l && a[i + 1] > l) {
            --res;
        }
    }

    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;
        if (type == 0) {
            cout << res << endl;
        } else {
            ll p, d;
            cin >> p >> d;
            --p;
            if (a[p] <= l && a[p] + d > l) {
                ++res;
                if (p + 1 < n && a[p + 1] > l) {
                    --res;
                }
                if (p - 1 >= 0 && a[p - 1] > l) {
                    --res;
                }
            }
            a[p] += d;
        }
    }




}