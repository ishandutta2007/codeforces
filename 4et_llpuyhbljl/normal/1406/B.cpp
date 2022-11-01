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
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 300000, maxT = 2001;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long>a_ot, a_pl;
        long long ans = -INF;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            if (tmp == 0)ans = 0;
            else {
                if (tmp > 0)a_pl.push_back(tmp);
                else a_ot.push_back(tmp);
            }
        }
        sort(a_pl.begin(), a_pl.end());
        sort(a_ot.begin(), a_ot.end());
        for (int i = 0; i <= 5; ++i) {
            int c_p = i, c_o = 5 - i;
            if (c_p <= (int)a_pl.size() && c_o <= (int)a_ot.size()) {
                long long tmp = 1;
                for (int j = 0; j < c_o; ++j) {
                    if (c_o != 5) {
                        tmp *= a_ot[j];
                    }
                    else {
                        tmp *= a_ot[(int)a_ot.size() - 1 - j];
                    }
                }
                for (int j = 0; j < c_p; ++j) {
                    tmp *= a_pl[(int)a_pl.size() - 1 - j];
                }
                ans = max(ans, tmp);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
7 12
6 7 1
7 6 1
1 2 2
2 3 1
3 2 1
2 4 2
5 3 2
4 5 1
5 4 1
6 3 5
4 7 3
5 6 2
*/