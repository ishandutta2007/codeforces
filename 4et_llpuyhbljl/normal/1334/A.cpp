
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
int arr[Y + 1];
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
        int n;
        cin >> n;
        int p = 0, c = 0;
        bool res = true;
        cin >> p >> c;
        if (p < c)res = false;
        for (int i = 1; i < n; ++i) {
            int np, nc;
            cin >> np >> nc;
            if (np < nc)res = false;
            if (np < p)res = false;
            if (nc < c)res = false;
            if (nc - c > np - p)res = false;
            p = np;
            c = nc;
        }
        if (res)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}