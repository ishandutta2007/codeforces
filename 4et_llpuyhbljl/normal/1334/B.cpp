
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
const int Y = 100000;
const int INF = 1000000;
int L = 0;
long long arr[Y + 1];
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
        long long n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        long long s = 0, res = 0;
        sort(arr + 1, arr + 1 + n);
        long long ct = n;
        while (true) {
            s += arr[ct--];
            long long tmp = n - ct;
            if (s / tmp >= x) {
                if (ct == 0) {
                    res = n;
                    break;
                }
            }
            else {
                res = tmp - 1;
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}