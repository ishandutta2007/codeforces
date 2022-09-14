#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int mod;
    cin >> mod;

    vector<int> a(n);
    int sum = 0;
    for (int i =0 ; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }

    int best = 0;
    int lf = 0;
    for (int i = 0; i < n - 1; ++i) {
        lf += a[i];
        lf %= mod;
        int rg = sum - lf % mod;
        if (rg < 0) {
            rg += mod;
        }
        best = max(best, lf + rg);
    }

    cout << best << "\n";

}