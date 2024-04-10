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
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;

mt19937 rr(random_device{}());

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);    
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(all(b));

    vector<int> to(n);
    for (int i = 0; i < n; ++i) {
        to[i] = b[i].second;
    }

    vector<int> used(n);
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i) {
        if (used[i])
            continue;

        int k = to[i];
        vector<int> f = {i};
        used[i] = 1;
        for (; !used[k]; k = to[k]) {
            used[k] = 1;
            f.push_back(k);
        }
        res.push_back(f);
    }

    cout << sz(res) << "\n";

    for (int i = 0; i < sz(res); ++i) {
        cout << sz(res[i]) << " ";
        for (int j = 0; j < sz(res[i]); ++j) {
            cout << res[i][j] + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}