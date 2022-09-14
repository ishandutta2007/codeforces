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
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

mt19937 rr(random_device{}());

const int MAXN = 1e7;

int p = 0;
bool pr[MAXN];

void add(int &a, int b) {
    a += b;
    if (a >= p)
        a -= p;
}

void mul(int &a, int b) {
    ll ans = (ll)a * b;
    ans %= p;
    a = ans;
}

int binPow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int ans = binPow(a, b / 2);
    mul(ans, ans);
    if (b & 1) {
        mul(ans, a);
    }
    return ans;
}

bool check(int g, const vector<int> &d) {
    for (int divisor : d) {
        if (binPow(g, (p - 1) / divisor) == 1) {
            return false;
        }
    }
    return true;
}

int getGenerator() {
    vector<int> d;
    int m = p - 1;
    for (int i = 2; i * i <= m; ++i) {
        if (m % i == 0) {
            for (; m % i == 0; m /= i);
            d.push_back(i);
        }
    }
    if (m != 1) {
        d.push_back(m);
    }

    for (; ; ) {
        int g = rand() % p;
        if (!g) {
            continue;
        }
        if (check(g, d)) {
            return g;
        }
    }
    return 0;

}

int main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < MAXN; ++i) {
        if (!pr[i]) {   
            for (int j = i; (ll)i * j < MAXN; ++j)
                pr[i * j] = 1;
        }
    }

    int n;
    cin >> n;
    
    for (int i = 1; n * i + 1 < MAXN; ++i) {
        if (!pr[n * i + 1]) {
            p = n * i + 1;
        }
    } 

    int g = getGenerator();
    
    g = binPow(g, (p - 1) / n);

    string s;
    cin >> s;
    int cur = 1;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = s[i] - '0';
        mul(tmp, cur);
        add(res, tmp);
        mul(cur, g);
    }  
    cout << (res == 0 ? "YES\n" : "NO\n");
}