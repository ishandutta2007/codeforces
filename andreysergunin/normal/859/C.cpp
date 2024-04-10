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
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int INF = 1e9;
const int MAXN = 60;

int dp[MAXN];
int a[MAXN];
int pref[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        dp[i] = dp[i + 1];
        dp[i] = max(dp[i], pref[n] - pref[i] - dp[i + 1]);
    }

    cout << pref[n] - dp[0] << " " << dp[0] << endl;
        

}