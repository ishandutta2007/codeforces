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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;


int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> deg(n);
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
        --p[i];
        ++deg[p[i]];
    }

    vector<int> f(n);
    for (int i = 1; i < n; ++i) {
        if (deg[i] == 0) {
            ++f[p[i]];
        }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        ok &= (deg[i] == 0 || f[i] >= 3);
    }

    cout << (ok ? "Yes\n" : "No\n");


    return 0;
}