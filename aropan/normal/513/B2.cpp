#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define foreach(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    //for (int _m = 0; _m < (1LL << (n - 1)); ++_m) {
        //m = _m;
        ll k = 1LL << (n - 1);
        int l, r;
        l = 0;
        r = n;
        int ans[n];
        for (int i = 0; i < n; ++i) {
            k >>= 1;
            if (m > k) {
                ans[--r] = i;
                m -= k;
            } else {
                ans[l++] = i;
            }
        }

        //int res = 0;
        //for (int i = 0; i < n; ++i) {
            //int x = ans[i];
            //for (int j = i; j < n; ++j) {
                //x = min(x, ans[j]);
                //res += x;
            //}
        //}
        //cout << res << " ";
        for (int i = 0; i < n; ++i) {
            if (i) {
                cout << " ";
            }
            cout << ans[i] + 1;
        }
        cout << endl;
    //}
    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}