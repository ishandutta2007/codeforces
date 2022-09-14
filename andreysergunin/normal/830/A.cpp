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
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef double ld;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n, k, pos;
    cin >> n >> k >> pos;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> b(k);
    for (int i = 0; i < k; ++i) 
        cin >> b[i];
    sort(all(b));

    int lf = -1, rg = 2e9 + 1;

    while (rg - lf > 1) {
        int mid = ((ll)lf + (ll)rg) / 2;
        // cout << mid << endl;
        vector<pii> p(n);
        for (int i = 0; i < n; ++i) {
            if (mid >= abs(pos - a[i])) {
                int l = min(a[i], pos);
                int r = max(a[i], pos);

                int x = l - (mid - (r - l)) / 2;
                int y = r + (mid - (r - l)) / 2 + 1;
                // cout << x << " " << y << endl;
                p[i] = {x, y};
            }
        }
        // cout << endl;

        // for (int i = 0; i < n; ++i)
        //     cout << p[i].first << " " << p[i].second << endl;

        // cout << endl;

        sort(all(p));

        int cur = 0;
        set<pii> s;

        for (int i = 0; i < n; ++i) {
            while (cur < k && b[cur] < p[i].first)
                ++cur;

            s.insert({p[i].second, i});

            while (sz(s) > 0 && cur < k && (*s.begin()).first > b[cur]) {
                s.erase(s.begin());
                ++cur;
            }
        }
        if (sz(s) == 0) {
            rg = mid;
        } else {
            lf = mid;
        }
    }

    cout << rg << endl;
}