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
typedef long double ld;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 3e5;

vector<int> g[MAXN];
int p[MAXN];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        sort(all(g[i]));
    }

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    
    if (p[0] != 0) {
        cout << "No" << endl;
        return 0;
    }

    queue<int> queue;
    queue.push(p[0]);


    for (int i = 1; i < n; ++i) {
        if (queue.empty()) {
            cout << "No" << endl;
            return 0;
        }

        int v = queue.front();

        auto it = lower_bound(all(g[v]), p[i]);

        if (it != g[v].end() && *it == p[i]) {
            queue.push(p[i]);
        } else {
            queue.pop();
            --i;
        }
    }

    cout << "Yes" << endl;

}