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

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    int n;
    cin >> n;

    if (n <= 2) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> res;
    if (n % 2 == 0) {
        res.push_back({1, 2, 3});
        res.push_back({2, 3, 4});
        res.push_back({3, 4, 1});
        res.push_back({4, 1, 2});
    } else {
        res.push_back({1, 2, 3});
        res.push_back({1, 2, 3});
    }

    for (int i = (n % 2 == 0 ? 5 : 4); i < n; i += 2) {
        res.push_back({i, i + 1, 1});
        res.push_back({i, i + 1, 1});
        for (int j = 0; j < i - 2; ++j) {
            res.push_back({i, (2 * j) % (i - 2) + 2, i + 1, (2 * j + 1) % (i - 2) + 2});
        }
    }

    cout << sz(res) << endl;
    for (int i = 0; i < sz(res); ++i) {
        cout << sz(res[i]) << " ";
        for (int j = 0; j < sz(res[i]); ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }


}