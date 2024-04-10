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
mt19937 rr(random_device{}());

const ll INF = 2e18;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    // n = 500;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) 
        cin >> a[i];
        // a[i] = 1000000000;

    int k = 70000;

    ll ans = INF;

    for (int i = 1; i <= k; ++i) {
        ll x = i;
        ll cur = 0;
        bool f = true;
        for (int j = 0; j < n; ++j) {
            int u = a[j] / (x + 1);
            int add = (u - a[j]) % x;
            if (add < 0)
                add += x;
            u -= add;
            if (u < 0) {
                f = false;
                break;;
            }
            cur += (a[j] - u) / x;

            // ll cnt = a[j] / x;
            // ll r = a[j] % x;
            // if (cnt < r) {
            //     f = false;
            //     break;
            // }
            // cur += cnt;
        }
        if (f) {
            // cout << i << " " << cur << endl;
            ans = min(ans, cur);
        }
    }

    for (int i = 1; i <= a[0] / k + 1; ++i) {
        ll x = a[0] / i;
        ll cur = 0;
        bool f = true;
        for (int j = 0; j < n; ++j) {
            int u = a[j] / (x + 1);
            int add = (u - a[j]) % x;
            if (add < 0)
                add += x;
            u -= add;
            if (u < 0) {
                f = false;
                break;;
            }
            cur += (a[j] - u) / x;

            // ll cnt = a[j] / x;
            // ll r = a[j] % x;
            // if (cnt < r) {
            //     f = false;
            //     break;
            // }
            // cur += cnt;
        }
        if (f) {
            // cout << i << " " << cur << endl;
            ans = min(ans, cur);
        }

        --x;
        if (x == 0)
            continue;

        cur = 0;
        f = true;
        for (int j = 0; j < n; ++j) {
            int u = a[j] / (x + 1);
            int add = (u - a[j]) % x;
            if (add < 0)
                add += x;
            u -= add;
            if (u < 0) {
                f = false;
                break;;
            }
            cur += (a[j] - u) / x;

            // ll cnt = a[j] / x;
            // ll r = a[j] % x;
            // if (cnt < r) {
            //     f = false;
            //     break;
            // }
            // cur += cnt;
        }
        if (f) {
            // cout << i << " " << cur << endl;
            ans = min(ans, cur);
        }
    }
    cout << ans << endl;
}