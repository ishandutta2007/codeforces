#pragma comment(linker, "/STACK:2759095000")
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
const double INF = 1e17;
const int mod = 998244353;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 100100, maxT = 2001;
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
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        for (auto& x : a)cin >> x;
        int cl = 0;
        for (int i = 1; i < n; ++i)if (a[i] != a[i - 1])++cl;
        if (k == 1) {
            if (cl == 0)cout << "1\n";
            else cout << "-1\n";
        }
        else {
            --k;
            cout << max(1, (cl + k - 1) / k) << "\n";
        }
    }
    return 0;
}