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

const int MAXN = 5100;
const int P = 1e9 + 7;

int s[MAXN][MAXN];
int fact[MAXN], rfact[MAXN];

void add(int &a, int b) {
    a += b;
    if (a >= P) {
        a -= P;
    }
}

void mul(int &a, int b) {
    ll c = (ll)a * b;
    c %= P;
    a = c;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);    
    // freopen("output.txt", "w", stdout); 
    
    

    int n, k;
    cin >> n >> k;

    s[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= i; ++j) {
            s[i][j] = s[i - 1][j];
            mul(s[i][j], j);
            add(s[i][j], s[i - 1][j - 1]);
        }
    }

    // fact[0] = 1;
    // rfact[0] = 1;
    // for (int i = 1; i <= k; ++i) {
    //     fact[i] = fact[i - 1] * i;
    //     rfact[i] = binPow(fact[i], P - 2);
    // }

    int res = 0;
    for (int i = 0; i <= k; ++i) {
        if (i > n) {
            continue;
        }
        int cur = s[k][i];
        for (int j = 0; j < i; ++j) {
            mul(cur, n - j);
        }
        mul(cur, binPow(2, n - i));
        add(res, cur);
    }

    cout << res << endl;

    

    return 0;
}