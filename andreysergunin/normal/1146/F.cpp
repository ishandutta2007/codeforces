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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 200200;
const int P = 998244353;

void add(int &a ,int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void sub(int &a ,int b) {
    a -= b;
    if (a < 0) {
        a += P;
    }
}

void mul(int &a, int b) {
    ll c=  (ll)a * b;
    c %= P;
    a = c;
}

vector<int> g[MAXN];
int dp1[MAXN], dp2[MAXN];

void dfs(int v) {

    if (sz(g[v]) == 0) {
        dp1[v] = 1;
        dp2[v] = 1;
        return;
    }

    for (int u : g[v]) {
        dfs(u);
    }

    int n = sz(g[v]);
    vector<int> pref(n + 1);
    vector<int> suff(n + 1);

    pref[0] = 1;
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i];
        mul(pref[i + 1], dp1[g[v][i]]);
    }

    suff[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1];
        mul(suff[i], dp1[g[v][i]]);
    }

    // cout << "-----------> " << v << endl;
    // for (int i = 0; i <= n; ++i) {
    //     cout << pref[i] << " " << suff[i] << endl;;
    // } 

    int x1 = 1;
    int x2 = 1;
    int x3 = 0;

    for (int i = 0; i < n; ++i) {
        int u = g[v][i];

        mul(x1, dp1[u]);
        mul(x2, dp1[u] + dp2[u]);

        int cur = dp2[u];
        mul(cur, pref[i]);
        mul(cur, suff[i + 1]);
        add(x3, cur);
    }

    add(dp1[v], x2);
    sub(dp1[v], x3);
    
    dp2[v] = dp1[v];
    sub(dp2[v], x1);
    add(dp2[v], x3);

    // cout << v << " " << dp1[v] << " " << dp2[v] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].push_back(i);
    }

    dfs(0);

    cout << dp1[0] << endl;
    
}