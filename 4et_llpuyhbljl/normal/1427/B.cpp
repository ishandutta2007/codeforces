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
const long long INF = 1e9;
const int mod = 1000000007;
const double eps = 1e-9, pi = acos(-1);
const int maxN = 1000100, maxT = 2001;
void file_inc() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int>id;
        int sum = 0;
        int ln = -1;
        int ix = 0;
        while (ix < n && s[ix] == 'L')++ix;
        vector<int>lns;
        for (int i = ix; i < n; ++i) {
            if (s[i] == 'W') {
                if (i == 0 || s[i - 1] == 'L') {
                    if (ln != -1)lns.push_back(ln);
                    ln = 0;
                    id.push_back(i);
                    ++sum;
                }
                else {
                    sum += 2;
                }
            }
            else ++ln;
        }
        sort(lns.begin(), lns.end());
        if (sum == 0) {
            cout << max(0, 2 * min(n, k) - 1) << "\n";
            continue;
        }
        for (auto x : lns) {
            if (x > k) {
                ln += x;
                break;
            }
            if (x == k) {
                sum += 2 * k + 1;
                k = 0;
                break;
            }
            if (k > x) {
                sum += 2 * x + 1;
                k -= x;
            }
        }
        if (k == 0) {
            cout << sum << "\n";
            continue;
        }
        if (k >= ix) {
            sum += 2 * ix;
            k -= ix;
        }
        else {
            if (k > ln) {
                sum += 2 * ln;
                k -= ln;
            }
            else {
                sum += 2 * k;
                k = 0;
            }
            if (k != 0) {
                sum += 2 * k;
                k = 0;
            }
        }
        if (k != 0) {
            sum += min(k, ln) * 2;
        }
        cout << sum << "\n";
    }
    return 0;
}