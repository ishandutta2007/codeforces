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
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const ld EPS = 1e-16;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int n, k, h;
    cin >> n >> k >> h;
    vector<pair<pii, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first.first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first.second;
    }
    for (int i = 0; i < n; ++i) {
        p[i].second = i + 1;
    }
    sort(all(p));

    ld lf = 0, rg = 1e9;
    for (int op = 0; op < 100; ++op) {
        ld t = (lf + rg) / 2;
        int l = k;
        for (int i = n - 1; i >= 0; --i) {
            if (p[i].first.second * t >= h * l) {
                --l;
            }
            if (l == 0) {
                break;
            }
        }
        if (l == 0) {
            rg = t;
        } else {
            lf = t;
        }
    }


    ld t = rg;

    int l = k;
    vector<int> res(k + 1);
    for (int i = n - 1; i >= 0; --i) {
        if (p[i].first.second * t >= h * l) {
            --l;
            res[l] = p[i].second;
        }
        if (l == 0) {
            break;
        }
    }
    for (int i = 0; i < k; ++i) { 
        cout << res[i] << " ";
    }
    cout << endl;
}