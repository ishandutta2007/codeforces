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
#include<bitset>
#include<random>
using namespace std;
//#define double long long;
typedef unsigned long long ull;
#define double long double
const double e = 0.00000005;
const double pi = 3.1415926535898;
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
long long gcd(long long i, long long j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
//const long long INF = 100000000000000;
const int Y = 100100;
const long long INF = 1000000000000000000;
const long long m = 998244353;
long long pw(int b, long long et) {
    if (b == 1)return et;
    long long tmp = pw(b / 2, et);
    tmp = (tmp * tmp) % m;
    if (b % 2 == 1)tmp = (tmp * et) % m;
    return tmp;
}
vector<long long>simple;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    int n;
    cin >> n;
    vector<int>a(n);
    for (auto& x : a)cin >> x;
    vector<int>p(n);
    for (auto& x : p)cin >> x;
    long long lp = 0;
    int m;
    cin >> m;
    vector<int>b(m);
    for (auto& x : b)cin >> x;
    vector<long long>dp(m + 1, INF);
    dp[0] = 0;
    vector<long long> costEt(m);
    for (int i = 0; i < n; ++i) {
        int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if (j == m)lp += p[i];
        else {
            if (p[i] < 0)costEt[j] += p[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if (j == m)continue;
        if (b[j] == a[i]) {
            long long add = max(0, -p[i]);
            dp[j + 1] = min(dp[j + 1], costEt[j] + dp[j] + add);
        }
        if (p[i] > 0)costEt[j] += p[i];
    }
    if (dp[m] > INF / 10) {
        cout << "NO";
    }
    else cout << "YES\n" << dp[m] + lp;
    return 0;
}
/*
782574093100800
1
782574093100800 1
*/