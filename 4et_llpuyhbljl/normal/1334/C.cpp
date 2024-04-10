
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
        long long s = 0, res = 0;
        long long mn = 1000000000000000;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)cin >> arr[i] >> b[i];
        arr[n] = arr[0];
        for (int i = 0; i < n; ++i) {
            s += arr[i];
            b[i] = min(b[i], arr[i + 1]);
            res += b[i];
            mn = min(mn, b[i]);
        }
        s -= (res - mn);
        cout << s << "\n";
    }
    return 0;
}