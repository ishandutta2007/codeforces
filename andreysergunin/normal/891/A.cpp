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

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        assert(n <= 5 || a[i] <= 10000);
    }
    int minn = n;
    for (int i = 0; i < n; ++i)  {
        int cur = a[i];
        if (cur == 1) {
            minn = 0;
        }
        for (int j = i + 1; j < n; ++j) {
            cur = gcd(cur, a[j]);
            if (cur == 1) {
                minn = min(minn, j - i);
            }
        }
    }
    if (minn == n) {
        cout << -1 << endl;
        return 0;
    } 
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 1) {
            ++cnt;
        }
    }
    cnt = min(cnt, n - 1);
    int ans = cnt + minn;    
    cout << ans << endl;
}