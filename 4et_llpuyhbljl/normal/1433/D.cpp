#pragma comment(linker, "/STACK:9759095000")
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
const long long INF = 1e18;
//const int mod = 1000000007;
int mod;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 300100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
vector<int>f;
int find(int v) { return f[v] == v ? v : f[v] = find(f[v]); }
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
        int n;
        cin >> n;
        vector<int>a(n);
        f.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            f[i] = i;
        }
        vector<pair<int, int>>rb;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] == a[j])continue;
                if (find(i) != find(j)) {
                    rb.push_back({ i + 1,j + 1 });
                    f[find(i)] = find(j);
                }
            }
        }
        if (rb.size() + 1 == n) {
            cout << "YES\n";
            for (auto x : rb)cout << x.first << " " << x.second << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}