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

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> pref(n + 1);
    vector<int> suff(n + 1);

    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + (a[i] == 1);
    }

    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] + (a[i] == 2);
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int maxx1 = 0, maxx2 = 0;
        for (int j = i; j >= 0; --j) {
            if (a[j] == 1) {
                ++maxx1;
            } else {
                maxx2 = max(maxx1, maxx2) + 1;
            }
            ans = max(ans, max(maxx1, maxx2) + pref[j] + suff[i + 1]);
        }
    }
    cout << ans << endl;


    return 0;
}