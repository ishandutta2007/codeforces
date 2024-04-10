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
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 5e5;

bool pr[MAXN + 1];

void sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!pr[i]) {
            for (int j = i; (ll)i * j <= n; ++j) {
                pr[i * j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // sieve(MAXN);

    int n;
    cin >> n;
    vector<int> arr(n);
    int a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        a += (arr[i] == 1);
    }

    int b = n - a;
        
    arr.clear();
    if (a > 0 && b > 0) {
        arr.push_back(2);
        arr.push_back(1);
        --a; --b;
    }

    for (int i = 0; i < b; ++i) {
        arr.push_back(2);
    }
    for (int i = 0; i < a; ++i) {
        arr.push_back(1);
    }
    
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }    
    cout << endl;

    // int sum = 0;
    // int res = 0;
    // for (int i = 0; i < n; ++i) {
    //     sum += arr[i];
    //     if (!pr[sum]) {
    //         ++res;
    //     }
    // }

    // cout << res << endl;
}