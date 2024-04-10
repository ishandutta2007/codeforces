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

const int P = 1e9 + 7;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    sort(all(x));

    vector<ll> pow2(n + 1);
    pow2[0] = 1;
    for (int i = 1; i <= n; ++i)
        pow2[i] = pow2[i - 1] * 2 % P;

    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ll len = x[i] - x[i - 1];
        ll k = (pow2[i] - 1) * (pow2[n - i] - 1);
        k %= P;
        ans += len * k;
        ans %= P;
    }
    cout << ans << endl;


}