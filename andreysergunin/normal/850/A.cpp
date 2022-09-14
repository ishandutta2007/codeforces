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

typedef long  ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");
    
    int n;
    cin >> n;
    if (n >= 100) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> v(n, vector<int>(5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j)
            cin >> v[i][j];
    }

    vector<int> res;
    for (int i = 0; i < n; ++i) {
        bool f = true;
        for (int j = 0; j < n; ++j) {

            if (i == j)
                continue;
            for (int k = j + 1; k < n; ++k) {
                if (i == k)
                    continue;
                int x = 0;
                for (int l = 0; l < 5; ++l) {
                    x += (v[j][l] - v[i][l]) * (v[k][l] - v[i][l]);
                }
                if (x > 0) {
                    f = false;
                    break;
                }
            }
            if (!f)
                break;
        }
        if (f) {
            res.push_back(i + 1);
        }
    }
    cout << sz(res) << endl;
    sort(all(res));
    for (int id : res)
        cout << id << " ";
    cout << endl;
}