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

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int n = sz(s);
    s += s; 
    
    int res = 0;
    int cur = 1;
    for (int i = 1; i < sz(s); ++i) {
        if (s[i] != s[i - 1]) {
            ++cur;
        } else {
            res = max(res, cur);
            cur = 1;
        }
    }
    res = max(res, cur);
    res = min(res, n);

    cout << res << endl;

}