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
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int P = 998244353;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int n = sz(s);

    string t = "";

    for (int i = 0,  j = n - 1; i + 3 <= j; i += 2, j -= 2) {
        if (s[i] == s[j] || s[i] == s[j - 1]) {
            t += s[i];
        } else {
            t += s[i + 1];
        }
    }
    int m = sz(t);  
    if (n % 4 != 0) {
        t += s[n / 2];
    }

    for (int i = m - 1; i >= 0; --i) {
        t  += t[i];
    }
    cout << t << endl;

    // assert(sz(t) >= sz(s) / 2);



    return 0;
}