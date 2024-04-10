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
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

string f(string s) {
    string t;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] != 'a') {
            t += s[i];
        }
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int n = sz(s);
    int m = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] != 'a') {
            ++m;
        }
    }

    if (0 == m) {
        cout << s << endl;
        return 0;
    }

    if (m % 2 == 1) {
        cout << ":(" << endl;
        return 0;
    }

    m /= 2;

    string u, v;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'a') {
            --m;
            if (m == -1) {
                u = s.substr(0, i);
                v = s.substr(i, n - i);
                break;
            }
        }
    }   

    // cout << u << " " << v << endl;

    if (f(u) == v) {
        cout << u << endl;
    } else {
        cout << ":(" << endl;
    }
}