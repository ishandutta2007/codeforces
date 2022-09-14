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

const int INF = 1e9 + 100;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int mn = INF;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn = min(mn, a[i]);
    }

    int r = mn % k;
    ll ans = 0 ;
    for (int i = 0; i < n; ++i) {
        if (a[i] % k != r) {
            cout << -1 << "\n";
            return 0;
        }
        ans += (a[i] - mn) / k;
    }
    cout << ans << endl;
}