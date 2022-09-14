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
mt19937 rr(random_device{}());

const int ALPH = 26;

vector<vector<int>> g;
vector<vector<ll>> cnt; 
vector<vector<ll>> sum; 

int n, k;

ll ans = 0;

void dfs(int v, int p) {
    cnt[v][0] = 1;
    for (int u : g[v]) {
        if (u == p)
            continue;
        dfs(u, v);
    }

    if (sz(g[v]) == 1 && p != -1)
        return;

    vector<ll> cCnt(k);
    vector<ll> cSum(k);

    for (int u : g[v]) {
        if (u == p)
            continue;
        for (int i = 0; i < k - 1; ++i) {
            cnt[v][i + 1] += cnt[u][i];
            sum[v][i + 1] += sum[u][i];
        }
        cnt[v][0] += cnt[u][k - 1];
        sum[v][0] += sum[u][k - 1] + cnt[u][k - 1];

        for (int i = 0; i < k; ++i) {
            ans += cnt[u][i] + sum[u][i];
        }

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (i + j + 2 <= k) {
                    ans += cnt[u][i] * cSum[j] + sum[u][i] * cCnt[j] + cnt[u][i] * cCnt[j];
                } else {
                    ans += cnt[u][i] * cSum[j] + sum[u][i] * cCnt[j] + 2 * cnt[u][i] * cCnt[j];
                }
            }
        }
        for (int i = 0; i < k; ++i) {
            cCnt[i] += cnt[u][i];
            cSum[i] += sum[u][i];
        }
    }
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    g.resize(n);
    cnt.resize(n, vector<ll>(k));
    sum.resize(n, vector<ll>(k));

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, - 1);

    cout << ans << endl;


    return 0;
}