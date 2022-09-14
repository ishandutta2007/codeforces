#include <stdio.h>
#include <iostream>
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
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

const int P = 1e9 + 7;

ll binPow(ll a, ll b) {
    if (b == 0)
        return 1;

    ll x = binPow(a, b / 2);
    x *= x;
    x %= P;

    if (b & 1) {
        x *= a;
        x %= P;
    }

    return x;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    if (k == 1 || k > n) {
        cout << binPow(m, n) << endl;
        return 0;
    }        

    if (k == n) {
        cout << binPow(m, (n + 1) / 2) << endl;
        return 0;
    }

    if (k & 1) {
        cout << m * m % P << endl;
    } else {
        cout << m % P << endl;
    }

    return 0;
}