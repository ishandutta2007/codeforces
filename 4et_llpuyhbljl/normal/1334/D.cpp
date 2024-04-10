
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
#include<iostream>
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
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
//const long long INF = 100000000000000;
const int Y = 300000;
const int INF = 1000000;
int L = 0;
long long arr[Y + 1];
long long b[Y + 1];
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
        long long n, l, r;
        cin >> n >> l >> r;
        long long tmp = n - 1;
        long long dd = 1;
        int fd = 1;
        while (tmp * 2 + dd < l && tmp > 0) {
            ++fd;
            dd += tmp * 2;
            --tmp;
        }
        for (int i = fd; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (dd > r)break;
                if (dd < l) {
                    if (dd + 1 == l) {
                        cout << j << " ";
                    }
                    dd += 2;
                }
                else {
                    if (dd == r) {
                        dd += 2;
                        cout << i << " ";
                        break;
                    }
                    else {
                        dd += 2;
                        cout << i << " " << j << " ";
                    }
                }
            }
            if (dd > r)break;
        }
        if (dd == r)cout << "1 ";
        cout << "\n";
    }
    return 0;
}