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
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {
    string s, t;
    cin >> s >> t;
    int x = 0, y = 0;
    for (int i = 0; i < sz(s); ++i) {
        x += s[i] == '1';
    }
    for (int i = 0; i < sz(t); ++i) {
        y += t[i] == '1';
    }
    x += x & 1;
    cout << (x >= y ? "YES" : "NO") << endl;
    
    return 0;
}