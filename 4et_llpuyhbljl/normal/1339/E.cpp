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
const int INF = 100000000;
const long long m = 998244353;
bool vis[Y];
long long solve(long long n) {
    long long m = (--n) / 3;
    long long mv = 1, a = 1, b = 2;
    while (mv <= m) {
        a *= 4;
        m -= mv;
        mv *= 4;
    }
    b = 2 * a;
    a += m;
    long long tmp = mv / 4;
    while (tmp) {
        int c = 0;
        while (tmp <= m) {
            m -= tmp;
            ++c;
        }
        long long add = tmp;
        if (c == 1) {
            b += 2 * add;
        }
        else {
            if (c == 2)b += 3 * add;
            else if (c == 3)b += add;
        }
        tmp /= 4;
    }
    if (n % 3 == 2)return (a ^ b);
    else {
        if (n % 3 == 0) {
            return a;
        }
        else return b;
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    // freopen("INPUT.TXT", "r", stdin);
     //freopen("OUTPUT.TXT", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
    vis[1] = vis[2] = vis[3] = true;
    int ii = 2;
    for (int i = 2; i <= Y / 4; ++i) {
        if (vis[i])continue;
        int a = i, b, c;
        for (int j = a + 1; j < Y; ++j) {
            if (!vis[a^j]) {
                c = a ^ j;
                if (!vis[j]) {
                    b = j;
                    break;
                }
            }
        }
        int st = 0;
        for (int j = 0; j <= 14; ++j)if ((i & (1 << j)))st = j;
        st = (1 << st);
        vis[a] = vis[b] = vis[c] = true;
        cout << a << " " << b << " " << c << "\n";
        cout << solve(ii * 3 - 2) << " " << solve(3 * ii - 1) << " " << solve(ii * 3) << "\n\n";
        ++ii;
    }
    return 0;
}
/*
782574093100800
1
782574093100800 1
*/