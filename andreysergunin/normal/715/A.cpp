#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <random>
#include <tuple>
#include <functional>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define fs first
#define sc second

typedef pair<int, int> pii;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    long long k = 2;

    for (long long i = 1; i <= n; ++i) {
        cout << i * (i + 1) * (i + 1) - k / i << endl;
        k = i * (i + 1);
    }
    return 0;
}