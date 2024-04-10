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

mt19937 rnd(random_device{}());

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);


    int n;
    cin >> n;

    int a = 1, b = n;

    for (int i = 1; i <= n; ++i) {
        int x = i;
        int y = (n - 1) / i + 1;
        if (x + y < a + b) {
            a = x;
            b = y;
        }
    }

    vector<int> p;

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            p.push_back(min(b * (i + 1), n) - j);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}