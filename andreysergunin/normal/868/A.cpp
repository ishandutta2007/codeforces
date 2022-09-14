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

    string s;
    cin >> s;
    int n;
    cin >> n;

    vector<string> t(n);
    for (int i = 0; i < n; ++i ) {
        cin >> t[i];
    }

    bool f = false;
    for (int i = 0; i < n; ++i) {
        f |= (s == t[i]);
        for (int j = 0; j < n; ++j) {
            f |= (s[0] == t[i][1] && s[1] == t[j][0]);
        }
    }

    cout << (f ? "YES\n" : "NO\n");
}