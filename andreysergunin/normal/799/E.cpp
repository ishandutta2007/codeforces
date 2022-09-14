#include <stdio.h>
#include <iostream>
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
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const ll INF = 1e18;
    
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<int> x(n);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int id;
        cin >> id;
        --id;
        x[id] += 1;
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int id;
        cin >> id;
        --id;
        x[id] += 2;
    }
    
    vector<int> a[4];

    for (int i = 0; i < n; ++i)
        a[x[i]].push_back(p[i]);

    for (int i = 0; i < 4; ++i)
        sort(all(a[i]));

    swap(a[0], a[3]);

    vector<ll> pref[4];

    for (int i = 0; i < 4; ++i) {
        pref[i].resize(sz(a[i]) + 1);
        for (int j = 0; j < sz(a[i]); ++j) 
            pref[i][j + 1] = pref[i][j] + a[i][j];
    }


    // for (int i = 0; i < 4; ++i) {
    //     for (int j = 0; j < sz(a[i]); ++j)
    //         cout << a[i][j] << " ";
    //     cout << endl;
    // }
            
    ll ans = INF;
    for (int i = 0; i <= sz(a[0]); ++i) {
        if (sz(a[1]) + i < k || sz(a[2]) + i < k)
            continue;


        if (i + sz(a[1]) + sz(a[2]) + sz(a[3]) < m || i + 2 * max(0, k - i) > m)
            continue;

        int l = -1, r = 1e9 + 1;

        while (r - l > 1) {
            int mid = (l + r) / 2;
            int x = (upper_bound(all(a[1]), mid) - a[1].begin());
            x = max(x, k - i);
            int y = (upper_bound(all(a[2]), mid) - a[2].begin());
            y = max(y, k - i);
            int z = (upper_bound(all(a[3]), mid) - a[3].begin());
            if (i + x + y + z < m) {
                l = mid;
            } else {
                r = mid;
            }
        }

        int x = (lower_bound(all(a[1]), r) - a[1].begin());
        x = max(x, k - i);
        int y = (lower_bound(all(a[2]), r) - a[2].begin());
        y = max(y, k - i);
        int z = (lower_bound(all(a[3]), r) - a[3].begin());

        ans = min(ans, pref[0][i] + pref[1][x] + pref[2][y] + pref[3][z] + r * (m - x - y - z - i));
    }

    cout << (ans == INF ? -1 : ans) << endl;
}