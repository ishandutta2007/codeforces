#pragma comment(linker, "/STACK:9759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include <unordered_map>
#include<random>
#include<ctime>
#define double long double
//#define int long long
using namespace std;
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
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
const long long INF = 1e18;
//const int mod = 1000000007;
int mod;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 300100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    // file_inc();
    int n;
    cin >> n;
    unsigned long long ans = 1;
    for (int j = 0; j < 2; ++j)
        for (int i = 1; i < n / 2; ++i)ans *= i;
    vector<vector<unsigned long long>>c(n + 1, vector<unsigned long long>(n + 1, 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)c[i][j] = c[i - 1][j] + c[i][j - 1];
    }
    n /= 2;
    c[n][n] /= 2;
    ans *= c[n][n];
    cout << ans;
    return 0;
}