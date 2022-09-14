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

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int P = 1e9 + 7;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int n = sz(s);
    vector<int> f(n + 1);
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        f[i] = (2 * f[i - 1] + 1);
        if (f[i] >= P)
            f[i] -= P;
    }

    int cnt = 0;
    int ans = 0; 
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            ++cnt;
        } else {
            ans += f[cnt];
            if (ans >= P)
                ans -= P;
        }
    }
    cout << ans << endl;
    return 0;
}