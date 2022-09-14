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
typedef long double ld;
typedef unsigned int uint;

mt19937 rnd(random_device{}());


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
        
    string s, t;
    int n, m;
    cin >> n >> m;
    cin >> s >> t;

    bool flag = false;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            flag = true;
        }
    }

    if (sz(s) > sz(t) + 1) {
        cout << "NO" << endl;
        return 0;
    }

    if (!flag) {
        cout << (s == t ? "YES" : "NO") << endl;
        return 0;
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            break;
        }
        if (s[i] != t[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[n - 1 - i] == '*') {
            break;
        }
        if (s[n - 1 - i] != t[m - 1 - i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;


}