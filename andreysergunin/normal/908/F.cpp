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
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);        

    int n;
    cin >> n;

    vector<int> x(n);
    vector<char> c(n);

    vector<int> r, g, b;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> c[i];
        if (c[i] == 'R') {
            r.push_back(i);
        } else if (c[i] == 'G') {
            g.push_back(i);
        } else {
            b.push_back(i);
        }
    }

    if (sz(g) == 0) {
        int ans = 0;
        if (sz(r) != 0) {
            ans += x[r.back()] - x[r[0]];
        }

        if (sz(b) != 0) {
            ans += x[b.back()] - x[b[0]];
        }

        cout << ans << endl;

        return 0;
    }

    int ans = 0;


    if (sz(r) > 0) {
        ans += max(x[g[0]] - x[r[0]], 0);
        ans += max(x[r.back()] - x[g.back()], 0);
    }

    if (sz(b) > 0) {
        ans += max(x[g[0]] - x[b[0]], 0);
        ans += max(x[b.back()] - x[g.back()], 0);
    }

    for (int k = 0; k + 1 < sz(g); ++k) {

        vector<int> rr = {x[g[k]]};
        vector<int> bb = {x[g[k]]};

        for (int i = g[k]; i < g[k + 1]; ++i) {
            if (c[i] == 'R') {
                rr.push_back(x[i]);
            }
            if (c[i] == 'B') {
                bb.push_back(x[i]);
            }
        }

        rr.push_back(x[g[k + 1]]);
        bb.push_back(x[g[k + 1]]);

        int maxr = 0, maxb = 0;
        for (int i = 0; i + 1 < sz(rr); ++i) {
            maxr = max(maxr, rr[i + 1] - rr[i]);
        }

        for (int i = 0; i + 1 < sz(bb); ++i) {
            maxb = max(maxb, bb[i + 1] - bb[i]);
        }

        int len = x[g[k + 1]] - x[g[k]];
        ans += min((ll)2 * len, (ll)3 * len - maxr - maxb);
    }

    cout << ans << endl;

    




}