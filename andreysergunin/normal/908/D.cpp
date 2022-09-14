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
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int P = 1e9 + 7;
const int MAXN = 1111;

int p[MAXN][2 * MAXN];

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

int  binPow(int a, int b) {
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
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);        

    int k, pa, pb;
    cin >> k >> pa >> pb;

    int q = binPow(pa + pb, P - 2);

    mul(pa, q);
    mul(pb, q);

    p[1][0] = 1;
    int res = 0;

    for (int a = 1; a < k; ++a) {
        for (int cnt = 0; cnt < 2 * k; ++cnt) {
            if (cnt >= k) {
                int cur = p[a][cnt];
                mul(cur, cnt);
                add(res, cur);
                continue;   
            }

            int cur = p[a][cnt];
            mul(cur, pa);
            add(p[a + 1][cnt], cur);

            cur = p[a][cnt];
            mul(cur, pb);
            add(p[a][cnt + a], cur);
        }
    }
    
    int r = binPow( P + 1 - pa, P - 2);

    for (int cnt = 0; cnt < k; ++cnt) {

        int cur = cnt;
        int x = pb;
        mul(x, k);
        mul(x, r);
        add(cur, x);

        x = pb;
        mul(x, pa);
        mul(x, r);
        mul(x, r);
        add(cur, x);

        mul(cur, p[k][cnt]);

        add(res, cur);
    }

    cout << res << endl;
    

}