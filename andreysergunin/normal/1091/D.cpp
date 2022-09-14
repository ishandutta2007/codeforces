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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;
typedef pair<ll, int> pli;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1000100;
const int P = 998244353;

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


void mul(int &a, int b) {
    ll c = (ll)a * b;
    c %= P;
    a = c;
}

int fact[MAXN], rfact[MAXN], r[MAXN];



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1];
        mul(fact[i], i);
    }

    r[1] = 1;
    for (int i = 2; i <= n; ++i) {
        r[i] = P - P / i;
        mul(r[i], r[P % i]);
    }



    rfact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        rfact[i] = rfact[i - 1];
        mul(rfact[i], r[i]);
    }


    int ans = fact[n];
    mul(ans, n);

    for (int i = 1; i <= n; ++i) {
        int cur = fact[n];
        mul(cur, rfact[i]);
        sub(ans, cur);
    }

    add(ans, 1);

    cout << ans << endl;


}