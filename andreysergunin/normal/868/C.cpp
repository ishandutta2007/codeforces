// MIPT Shock Content
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
typedef complex<ld> Complex;

mt19937 rr(random_device{}());

int main() {

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(1 << k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            x ^= 1;
            a[i] |= x * (1 << j);
         }
        b[a[i]] = 1;
    }

    for (int i = 0; i < (1 << k); ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            if (b[i] && b[j] && ((i | j) == (1 << k) - 1)) {
                cout << "YES\n";
                return 0; 
            }
        }
    }
    cout << "NO\n";    
}