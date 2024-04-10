#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
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

const int MAXP = 19;
long long p10[MAXP];

const int MAXC = 1000000;
int c[MAXC];

long long get(int l)
{
    return l < 1? 0LL : p10[l - 1] * l * 45;
}


int f(long long x)
{
    int res = 0;
    while (x >= MAXC) {
        res += c[x % MAXC];
        x /= MAXC;
    }
    return res + c[x];
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    p10[0] = 1;
    for (int i = 1; i < MAXP; ++i) {
        p10[i] = p10[i - 1] * 10;
    }

    c[0] = 0;
    for (int i = 1; i < MAXC; ++i) {
        c[i] = c[i / 10] + i % 10;
    }

    long long a;
    //for (long long a = 1e+7; a <= 1e+7 + 1e+3; ++a) {
    while (cin >> a) {
        vector <int> factor;
        factor.push_back(1);
        factor.push_back(2);
        factor.push_back(3);
        factor.push_back(5);
        factor.push_back(7);
        long long left, right;
        bool ok = false;
        for (size_t I = 0; I < factor.size() && !ok; ++I) {
            long long m = a * factor[I];
            int l = 1;
            while (get(l) < m) {
                l += 1;
            }
            left = 1;
            right = 0;
            long long s = 0;
            for (int i = l; i >= 1; --i) {
                for (int x = 1; x <= 10; ++x) {
                    long long v =
                        (x - 1) * p10[i - 1] + get(i - 1);
                    v += s * p10[i - 1];
                    if (m < v) {
                        s += x - 1;
                        right += (x - 1) * p10[i - 1];
                        break;
                    }
                    m -= v;
                }
            }
            right -= 1;
            for (int iter = 0; iter < 1e+7 && m; ++iter) {
                if (m > 0) {
                    m -= f(++right);
                } else {
                    m += f(left++);
                }
            }
            ok = m == 0;
        }
        assert(ok);
        //if (right < 10000000) {
            //long long res = 0;
            //for (long long x = left; x <= right; ++x) {
                //res += f(x);
            //}
            //if (res % a != 0) {
                //cout << left << " " << right << " " << a << endl;
                //assert(false);
            //}
        //}
        cout << left << " " << right << "\n";
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}