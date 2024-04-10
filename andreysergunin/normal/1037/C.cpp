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
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int cost = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) {
            continue;
        }
        if (i + 1 < n && s[i + 1] != t[i + 1] && s[i] != s[i + 1]) {
            swap(s[i], s[i + 1]);
            ++cost;
        } else {
            s[i] = '1' + '0' - s[i];
            ++cost;
        }
    }
    assert(s == t);
    
    cout << cost << endl;
}