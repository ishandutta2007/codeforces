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

const int INF = 1e9 + 8;

vector<vector<int>> a;
vector<int> cnt;

vector<int> p = {500, 1000, 1500, 2000, 2500, 3000};
vector<int> l = {2, 4, 8, 16, 32, 0};
vector<int> r = {1, 2, 4, 8, 16, 32};

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    a.resize(n, vector<int>(5));
    cnt.resize(5);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
            if (a[i][j] != -1)
                ++cnt[j];
        }
    }

    int ans = INF;

    for (int mask = 0; mask < 36 * 36 * 6; ++mask) {
        vector<int> t(5);
        int c = mask;
        for (int i = 0; i < 5; ++i) {
            t[i] = c % 6;
            c /= 6;
        }
        int lf = 0;
        int rg = INF;

        for (int i = 0; i < 5; ++i) {
            lf = max(lf, cnt[i] * r[t[i]] - n);
            if (a[0][i] != -1) {
                if (n - cnt[i] * l[t[i]] >= 0 && l[t[i]] != 0) {
                    lf = max(lf, (n - cnt[i] * l[t[i]]) / (l[t[i]] - 1) + 1);
                }
            } else {
                if (l[t[i]] != 0)
                    rg = min(rg, cnt[i] * l[t[i]] - n);
            }   
        }

        if (lf >= rg)
            continue;

        int u = 0;
        int v = 0;
        for (int i = 0; i < 5; ++i) {
            if (a[0][i] != -1) {
                u += p[t[i]] - p[t[i]] / 250 * a[0][i];
            }
            if (a[1][i] != -1) {
                v += p[t[i]] - p[t[i]] / 250 * a[1][i];
            }
        }
        if (u > v) {

            if (lf == 1) {
                cout << u << " " << v << endl;

                for (int i = 0; i < 5; ++i)
                    cout << t[i] << " ";
                cout << endl;
            }
            ans = min(ans, lf);
        }
    }



    cout << (ans == INF ? -1 : ans) << endl;





    return 0;

}