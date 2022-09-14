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

const double EPS = 1e-9;
const double PI = acos(-1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout);  

    int n, r, R;
    cin >> n >> R >> r;
    if (r > R) {
        cout << "NO\n";
        return 0;
    }
    if (n == 1) {
        cout << "YES\n";
        return 0;
    }
    if (2 * r > R) {
        cout << "NO\n";
        return 0;
    }

    double angle = 2 * asin((double)r / (R - r));
    if (n * angle < 2 * PI + EPS) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}