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
typedef complex<double> Complex;

mt19937 rnd(random_device{}());

template<class T>
void print(const vector<T> &arr) {
    for (T a : arr)  {
        cout << a << " ";
    }
    cout << endl;
}

void precalc() {

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    int x = 0, y = 0;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'B') {
                ++cnt;
                x += i;
                y += j;
            }
        }
    }
    x /= cnt;
    y /= cnt;
    cout << x + 1 << " " << y + 1 << endl;

}