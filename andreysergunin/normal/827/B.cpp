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
typedef pair<int, int> pii;
typedef double ld;
typedef unsigned int uint;

vector<pii> edges;

int solve(int n, int k) {
    if (n > k) {
        int ans = solve(n - k, k);
        for (int i = n - k + 1; i <= n; ++i)
            edges.push_back({max(1, i - k), i});
        return ans + 2;
    } else {
        for (int i = 2; i <= n; ++i)
            edges.push_back({1, i});
        return (n <= 2 ? n - 1 : 2);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    int n, k;
    cin >> n >> k;

    int ans = solve(n, k);
    cout << ans << endl;

    for (int i = 0; i < sz(edges); ++i)
        cout << edges[i].first << " " << edges[i].second << "\n";
}