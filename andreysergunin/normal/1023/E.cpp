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

bool request(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    string s;
    cin >> s;
    return (s == "YES");
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    string s, t;

    int x = 1, y = 1;

    for (int i = 0; i < n - 1; ++i) {
        if (request(x, y + 1, n, n)) {
            ++y;
            s += 'R';
        } else {
            ++x;
            s += 'D';
        }
    }

    x = n, y = n;
    for (int i = 0; i < n - 1; ++i) {
        if (request(1, 1, x - 1, y)) {
            --x;
            t += 'D';
        } else {
            --y;
            t += 'R';
        }
    }
    reverse(all(t));
    string res = s + t;

    cout << "! " << res << endl;
}