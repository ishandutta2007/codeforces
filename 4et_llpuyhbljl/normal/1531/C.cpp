#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#pragma comment(linker, "/STACK:36777216")
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
#include<unordered_map>
#include<random>
#include<ctime>
//#include<complex>
#include<numeric>
#define pb push_back
#define eb emplace_back
#define F first
#define S second

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

using namespace std;
ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}
const ll INF = 1e9;
const int mod = 1000000007;
const ld eps = 1e-7, pi = acosl(-1);
const ll maxN = 100010, maxT = 1000000, A = 263;
void panic() {
    cout << "-1\n";
    exit(0);
}
void solve() {
    int n;
    cin >> n;
    if (n == 2) 
        panic();
    int ans = INF;
    vector<vector<char>>a;
    for (int mid = 1; mid <= 100; ++mid) {
        if (mid * mid > n || (n - mid * mid) % 2 == 1)
            continue;
        int ost = (n - mid * mid) / 2;
        if (mid + (ost + mid - 1) / mid < ans) {
            ans = mid + (ost + mid - 1) / mid;
            a.assign(ans, vector<char>(ans, '.'));
            for (int i = 0; i < mid; ++i) {
                for (int j = 0; j < mid; ++j) {
                    a[i][j] = 'o';
                }
            }
            for (int i = 0; i < ost; ++i) {
                a[mid + i / mid][i % mid] = 'o';
                a[i % mid][mid + i / mid] = 'o';
            }
        }
    }
    reverse(a.begin(), a.end());
    cout << ans << "\n";
    for (int i = 0; i < ans; ++i) {
        for (int j = 0; j < ans; ++j) {
            cout << a[i][j];
        }
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(4);
    // srand(time(0));
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}