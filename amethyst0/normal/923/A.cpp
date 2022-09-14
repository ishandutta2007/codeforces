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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout); 


    int n;
    cin >> n;

    vector<int> pr(n + 1);

    for (int i = 2; i <= n; ++i) {
        if (!pr[i]) {
            for (int j = 1; i * j <= n; ++j) {
                pr[i * j] = i;
            }
        }
    }

    vector<int> f(n + 1);

    for (int i = 2; i <= n; ++i) {
        if (i != pr[i]) {
            f[i] = i - pr[i] + 1;
        }
    }

    int ans = INF;

    int rg = n;

    for (int i = n - pr[n] + 1; i <= n; ++i) {
        if (f[i] > 0) {
            ans = min(ans, f[i]);
        }
    }
    
    cout << ans << endl;



    return 0;
}