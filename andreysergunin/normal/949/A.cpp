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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout); 

    string s;
    cin >> s;
    int n = sz(s);

    vector<int> v[2];
    vector<vector<int>> res;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (sz(v[1]) == 0) {
                res.push_back({i});
                v[0].push_back(sz(res) - 1);
            } else {
                int id = v[1].back();
                v[1].pop_back();
                v[0].push_back(id);
                res[id].push_back(i);
            }
        } else {
            if (sz(v[0]) == 0) {
                cout << "-1" << endl;
                return 0;
            } else {
                int id = v[0].back();
                v[0].pop_back();
                v[1].push_back(id);
                res[id].push_back(i);
            }
        }
    }

    if (sz(v[1]) != 0) {
        cout << "-1" << endl;
        return 0;
    }

    cout << sz(res) << endl;

    for (int i = 0; i < sz(res); ++i) {
        cout << sz(res[i]) << " ";
        for (int j = 0; j < sz(res[i]); ++j) {
            cout << res[i][j] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}