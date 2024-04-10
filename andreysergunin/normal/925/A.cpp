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
typedef pair<ll, ll> pll;
typedef long double ld;

const int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout);  

    int n, m, w, a, b, v;
    cin >> n >> m >> a >> b >> v;
    set<int> s;
    set<int> l;

    for (int i = 0; i < a; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    for (int i = 0; i < b; ++i) {
        int x;
        cin >> x;
        l.insert(x);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2) {
            swap(y1, y2);
        }
        if (x1 > x2) {
            swap(x1, x2);
        }
        int ans = INF;

        if (x1 == x2) {
            ans = y2 - y1;
        }

        auto it = s.lower_bound(y1);

        if (it != s.end()) {
            int y = *it;
            ans = min(ans, x2 - x1 + abs(y1 - y) + abs(y2 - y));
        }

        if (it != s.begin()) {
            --it;
            int y = *it;
            ans = min(ans, x2 - x1 + abs(y1 - y) + abs(y2 - y));
        }

        it = l.lower_bound(y1);

        if (it != l.end()) {
            int y = *it;
            ans = min(ans, abs(y1 - y) + abs(y2 - y) + (x2 - x1 + v - 1) / v);
        }

        if (it != l.begin()) {
            --it;
            int y = *it;
            ans = min(ans, abs(y1 - y) + abs(y2 - y) + (x2 - x1 + v - 1) / v);
        }
        cout << ans << endl;
    } 




    return 0;
}