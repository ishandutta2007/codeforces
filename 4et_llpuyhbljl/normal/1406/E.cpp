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
#define int long long
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
const int maxN = 100010, maxT = 2001;
int prme[maxN];
int wt[maxN];
int qw(int chi, string tip = "B") {
    cout << tip << " " << chi << endl;
    int tmp = 1;
    cin >> tmp;
    return tmp;
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(15);
    int n;
    cin >> n;
    vector<int>p, p1;
    for (int i = 2; i <= n; ++i) {
        if (prme[i] == 0) {
            if (i * i <= n)p.push_back(i);
            else p1.push_back(i);
            for (int j = i; j <= n; j += i) {
                if (prme[j] == 0)++wt[i];
                prme[j] = 1;
            }
        }
    }
    int ans = 1;
    for (auto x : p) {
        qw(x);
    }
    int cc = 0;
    int stw = n + 1;
    int cn = qw(1, "A");
    for (auto x : p1) {
        int tmp = qw(x);
        ++cc;
        cn -= tmp;
        if (cc == 100) {
            cc = 0;
            int tt = qw(1, "A");
            if (tt != cn) {
                stw = x;
                break;
            }
        }
    }
    int y = upper_bound(p1.begin(), p1.end(), stw) - p1.begin();
    y = max(y - 105, 0LL);
    for (int j = 0; j < 110; ++j) {
        if (y + j >= p1.size())break;
        int tmp = qw(p1[y + j]);
        if (tmp != 0) {
            ans *= p1[y + j];
            break;
        }
    }
    for (auto x : p) {
        int tmp = qw(x);
        if (tmp == 0)continue;
        int add = x;
        for (int i = x * x; i <= n; i *= x) {
            if (i > n)break;
            tmp = qw(i, "A");
            if (tmp != 0) {
                add = i;
            }
            else break;
        }
        ans *= add;
    }
    cout << "C " << ans << endl;
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