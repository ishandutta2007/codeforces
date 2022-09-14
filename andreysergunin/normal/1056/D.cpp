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
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 100500;
vector<int> g[MAXN];
int w[MAXN];

int dfs(int v) {
    w[v] = (sz(g[v]) == 0);
    for (int u : g[v]) {
        w[v] += dfs(u);
    }
    return w[v];
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

    sort(w, w + n);
    for (int i = 0; i < n; ++i) {
        cout << w[i] << " ";
    }
    cout << endl;



}