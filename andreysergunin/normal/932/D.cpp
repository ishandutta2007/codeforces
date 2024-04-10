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

const int MAXN = 404000;
const int MAXL = 20;


ll sum[MAXN][MAXL];
ll to[MAXN][MAXL];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout); 

    int q;
    cin >> q;
    int cnt = 1;
    ll last = 0;

    vector<int> w(1);

    memset(to, -1, sizeof(to));

    vector<int> pow2(20);
    pow2[0] = 1;
    for (int i = 1; i < 20; ++i) {
        pow2[i] = pow2[i - 1] * 2;
    }

    for (int query = 0; query < q; ++query) {
        int type;
        ll p, q;
        cin >> type;
        cin >> p >> q;
        p ^= last;
        q ^= last;

        if (type == 1) {
            int v = p - 1;
            w.push_back(q);

            // cout << "! " << cnt + 1 << " " << w[cnt] << endl;

            int cur = v;

            if (w[v] >= w[cnt]) {
                to[cnt][0] = v;
                sum[cnt][0] = w[v];
            } else {
                for (int i = 19; i >= 0; --i) {
                    if (to[cur][i] != -1 && w[to[cur][i]] < w[cnt]) {
                        cur = to[cur][i];
                    }
                }
                cur = to[cur][0];
                to[cnt][0] = cur;
                sum[cnt][0] = w[cur];
            }
            // cout << to[cnt][0] << " " << sum[cnt][0] << endl;

            for (int i = 1; i < 20; ++i) {
                if (to[cnt][i - 1] == -1) {
                    break;
                }
                int u = to[cnt][i - 1];
                if (to[u][i - 1] == -1) {
                    break;
                } 
                to[cnt][i] = to[u][i - 1];
                sum[cnt][i] = sum[cnt][i - 1] + sum[u][i - 1];
            }
            ++cnt;
        } else {
            int v = p - 1;
            ll x = q;

            // cout << "? " << v + 1 << " " << x << endl;
            if (x < w[v]) {
                cout << 0 << endl;
                last = 0;
                continue;
            }
            x -= w[v];
            ll res = 1;

            // cout << to[v][1] << endl; 

            for (int i = 19; i >= 0; --i) {
                if (to[v][i] != -1 && sum[v][i] <= x) {
                    x -= sum[v][i];
                    res += pow2[i];
                    v = to[v][i];
                } 
            }

            cout << res << endl;
            last = res;
        }
    }

    return 0;
}