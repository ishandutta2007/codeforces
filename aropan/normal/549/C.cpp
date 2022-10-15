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

#if (_WIN32 || __WIN32__ || _WIN64 || __WIN64__)
#define INT64 "%I64d"
#define UNS64 "%I64u"
#else
#define INT64 "%lld"
#define UNS64 "%llu"
#endif

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

//map < pair <int, int>, int > m;

//int rec(int n, int k, int a, int b)
//{
    //if (a + b == k) {
        ////cerr << "\t" << a << " " << b << endl;
        //return b & 1;
    //}
    //int &res = m[make_pair(a, b)];
    //if (res == 0) {
        //if ((n - a - b) & 1) {
            //res = 1;
            //if (a) {
                //res = min(res, rec(n, k, a - 1, b));
            //}
            //if (b) {
                //res = min(res, rec(n, k, a, b - 1));
            //}
        //} else {
            //res = 0;
            //if (a) {
                //res = max(res, rec(n, k, a - 1, b));
            //}
            //if (b) {
                //res = max(res, rec(n, k, a, b - 1));
            //}
        //}
        //res += 1;
    //}
    ////cerr << a << " " << b << " " << res - 1 << endl;
    //return res - 1;
//}

int f(int n, int k, int a, int b)
{
    if (k == a + b) {
        return b & 1;
    }

    int c = b - a;
    if ((n - k) & 1) {
        if (c <= -k) {
            return 0;
        }
        if ((k & 1) == 0 && c >= k) {
            return 0;
        }
        return 1;
    } else {
        if ((k & 1) == 1 && c >= k) {
            return 1;
        }
        return 0;
    }
    assert(false);
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    #endif

    //for (int n = 1; n <= 50; ++n) {
        //for (int k = 0; k <= n; ++k) {
            //for (int a = 0; a <= n; ++a) {
                ////cerr << endl;
                //int b = n - a;
                //m.clear();
                //int answer = rec(n, k, a, b);
                //int result = f(n, k, a, b);
                //if (answer != result) {
                    //return false;
                //}
            //}
        //}
    //}



    int n, k;
    while (scanf("%d %d", &n, &k) == 2) {
        //m.clear();
        int a, b;
        a = b = 0;
        for (int i = 0; i < n; ++i) {
            int x = 0;
            assert(scanf("%d", &x) == 1);
            x &= 1;
            a += x == 0;
            b += x == 1;
        }
        //bool result = rec(n, k, a, b);
        int result = f(n, k, a, b);
        puts(result? "Stannis" : "Daenerys");
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}