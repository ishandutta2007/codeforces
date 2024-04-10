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

const int P = 1e9 + 9;

void mul(int &a, int b) {
    ll c = (ll)a * b;
    c %= P;
    a = c;
}

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += P;
    }
}

int binPow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int x = binPow(a, b / 2);
    mul(x, x);
    if (b & 1) {
        mul(x, a);
    }
    return x;
}

int rev(int a) {
    return binPow(a, P - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout);  

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    string s;
    cin >> s;

    vector<int> res(k);

    for (int i = 0; i < k; ++i) {
        res[i] = (s[i] == '+' ? 1 : P - 1);
    }

    int cur = 1;
    for (int i = 0; i < k; ++i) {
        mul(res[i], cur);
        mul(cur, b);
    }
    
    cur = 1;
    for (int i = k - 1; i >= 0; --i) {
        mul(res[i], cur);
        mul(cur, a);
    }

    int sum = 0;
    for (int i = 0; i < k; ++i) {
        add(sum, res[i]);
    }

    if (binPow(a, k) == binPow(b, k)) {
        mul(sum, (n + 1) / k);
        mul(sum, binPow(a, n - k + 1));
    } else {
        int tmp = binPow(a, n + 1);
        sub(tmp, binPow(b, n + 1));
        mul(sum, tmp);
        tmp = binPow(a, k);
        sub(tmp, binPow(b, k));
        mul(sum, rev(tmp));
    }

    cout << sum << endl;






    return 0;
}