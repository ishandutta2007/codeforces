#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<ctime>
#include<random>
using namespace std;
const unsigned long long INF = 1e17;
const int INFi = 2e8;
const int Y = 200100;
const long long m = 998244353;
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
long long PW(long long et, long long b) {
    if (b == 0)return 1;
    long long tmp = PW(et, b / 2);
    tmp = (tmp * tmp) % m;
    if (b % 2 == 1)tmp = (tmp * et) % m;
    return tmp;
}
long long f[Y];
long long g[Y];
long long c(int n, int k) {
    return f[n] * g[k] % m * g[n - k] % m;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    f[0] = g[0] = 1;
    int n, k;
    cin >> n >> k;
    if (k >= n) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * i % m;
        g[i] = PW(f[i], m - 2);
    }
    if (k == 0) {
        cout << f[n];
        return 0;
    }
    long long res = 0;
    int k1 = n - k;
    //res = (res * c(n, k1)) % m;
    for (int i = 0; i <= k1; ++i) {
        if (i % 2 == 0) {
            res = (res + c(k1, i) * PW(k1 - i, n)) % m;
        }
        else {
            res = ((res - c(k1, i) * PW(k1 - i, n)) % m + m) % m;
        }
    }
    res = (res * c(n, k1)) % m;
    cout << res * 2 % m;
    return 0;
}