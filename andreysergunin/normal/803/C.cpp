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
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int INF = 1e9;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;
    if (k >= 1e6) {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> d;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            d.push_back(i);
            d.push_back(n / i); 
        }
    }
    sort(all(d));

    ll res = -1;
    for (int i = 0; i < sz(d); ++i) {
        ll m = n / d[i];
        if (k * (k + 1) / 2 <= n / d[i])
            res = d[i];
    }
    if (res == -1) {
        cout << -1 << endl;
        return 0;
    }

    n /= res;
    vector<ll> ans(k);
    for (int i = 0; i < k; ++i) {
        ans[i] = (i + 1) * res;
    }
    n -= (k + 1) * k / 2;
    ans[k - 1] += n * res;

    for (int i = 0; i < k; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}