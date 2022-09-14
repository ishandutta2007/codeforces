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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    deque<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    vector<pii> res;

    for (int i = 0; i < n; ++i) {
        int x = a.front();
        a.pop_front();
        int y = a.front();
        a.pop_front();
        if (x > y) {
            a.push_front(x);
            a.push_back(y);
        } else {
            a.push_front(y);
            a.push_back(x);
        }

        res.push_back({x, y});
    }

    for (int k = 0; k < q; ++k) {
        ll t;
        cin >> t;
        --t;

        if (t < n) {
            cout << res[t].first << " " << res[t].second << endl;
            continue;
        }
        t -= n;
        t %= n - 1;
        cout << a[0] << " " << a[t + 1] << endl;
    }

}