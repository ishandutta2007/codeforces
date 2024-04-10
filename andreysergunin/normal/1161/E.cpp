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

const int MAXN = 1010;
const int P = 998244353;

vector<int> ask(vector<pii> arr) {
    int n = sz(arr);
    if (n == 0) {
        return {};
    } 
    cout << "Q ";
    cout << n << " ";
    for (pii p : arr) {
        cout << p.first + 1 << " " << p.second + 1 << " ";
    }
    cout << endl;

    string s;
    cin >> s;

    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = (s[i] == '1');
    }   

    return res;
}

void solve() {
    int n; 
    cin >> n;
    vector<pii> arr[4];
    for (int s = 0; s < 2; ++s) {
        for (int i = s; i + 1 < n; i += 2) {
            arr[s].push_back({i, i + 1});
        }
    }

    for (int i = 0; i + 2 < n; ++i) {
        if (i % 4 < 2) {
            arr[2].push_back({i, i + 2});
        } else {
            arr[3].push_back({i, i + 2});
        }
    }

    vector<int> res[4];

    for (int i = 0; i < 4; ++i) {
        res[i] = ask(arr[i]);
    }

    vector<vector<int>> g(n);
    vector<vector<int>> w(n);


    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < sz(res[k]); ++i) {
            int u = arr[k][i].first;
            int v = arr[k][i].second;
            g[v].push_back(u);
            w[v].push_back(res[k][i]);
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < sz(g[i]); ++j) {
    //         cout << i << " " << g[i][j] << " " << w[i][j] << endl;
    //     }
    // }

    int cnt = 0;

    vector<int> tp(n, -1);

    tp[0] = cnt++;

    vector<pii> to_ask;

    vector<int> prv = {-1};

    for (int i = 1; i < n; ++i) {

        int m = sz(w[i]);
        for (int j = 0; j < m; ++j) {
            if (w[i][j] == 1) {
                tp[i] = tp[g[i][j]];
            }
        }

        if (tp[i] >= 0)  {
            if (tp[i] != tp[i - 1]) {
                prv[tp[i]] = i - 1;
                prv[tp[i - 1]] = i;
            }
            continue;
        }

        bool eq = true;
        for (int j = 0; j < m; ++j) {
            eq &= tp[g[i][j]] == tp[g[i][0]];
        }

        if (!eq) {
            tp[i] = cnt++;
            prv.push_back(i - 1);
            if (tp[i] != tp[i - 1]) {
                prv[tp[i]] = i - 1;
                prv[tp[i - 1]] = i;
            }
            continue;
        }

        int t = tp[i - 1];

        tp[i] = cnt++;
        prv.push_back(i - 1);

        // cout << i << " " << t << " " << prv[t] << endl;
        // cout << sz(prv) << endl;
        if (prv[t] == -1) {
            if (tp[i] != tp[i - 1]) {
                prv[tp[i]] = i - 1;
                prv[tp[i - 1]] = i;
            }
            continue;
        }

        to_ask.push_back({prv[t], i});

        if (tp[i] != tp[i - 1]) {
            prv[tp[i]] = i - 1;
            prv[tp[i - 1]] = i;
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << tp[i] << " ";
    // }
    // cout << endl;


    int steps = 0;
    while (sz(to_ask) > 0) {    
        ++steps;
        assert(steps < 4);
        vector<pii> arr;
        vector<int> used(n);
        for (int i = 0; i < sz(to_ask); ++i) {
            pii p = to_ask[i];
            int u, v;
            tie(u, v) = p;

            if (used[u] || used[v]) {
                continue;
            }   
            used[u] = 1; used[v] = 1;
            arr.push_back(p);
            swap(to_ask[i], to_ask.back());
            --i;
            to_ask.pop_back();
        }
        vector<int> res = ask(arr);

        for (int i = 0; i < sz(arr); ++i) {
            int u = arr[i].first;
            int v = arr[i].second;
            g[v].push_back(u);
            w[v].push_back(res[i]);
        }
    }

    vector<int> ans(n);
    ans[0] = 1;

    bool fst = true;
    for (int i = 1; i < n; ++i) {

        for (int j = 0; j < sz(g[i]); ++j) {
            if (w[i][j] == 1) {
                ans[i] = ans[g[i][j]];
            }
        }

        if (ans[i] > 0) {
            continue;
        }

        if (fst) {
            fst = false;
            ans[i] = 2;
            continue;
        }

        vector<int> used(4);
        for (int j = 0; j < sz(g[i]); ++j) {
            used[ans[g[i][j]]] = 1;
        }

        for (int j = 1; j <= 3; ++j) {
            if (!used[j]) {
                assert(ans[i] == 0);
                ans[i] = j;
            }
        }
    }

    cout << "A ";
    vector<int> part[3];
    for (int i = 0; i < n; ++i) {
        part[ans[i] - 1].push_back(i);
    }

    for (int i = 0; i < 3; ++i) {
        cout << sz(part[i]) << " ";
    }
    cout << endl;

    for (int i = 0; i < 3; ++i) {
        for (int j : part[i]) {
            cout << j + 1 << " "; 
        }
        cout << endl;
    }

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    

    for (int test = 0; test < tests; ++test) {
        solve();
    }
}