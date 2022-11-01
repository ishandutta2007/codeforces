#include<iostream>
#include<vector>
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
using namespace std;
int gcd(int i, int j) {
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
const long long INF = 10000000;
const int Y = 200100;
const long long mod = 1000000007;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n == 1 || n == 4) {
            cout << "FastestFinger\n";
            continue;
        }
        if (n % 2 == 1) {
            cout << "Ashishgup\n";
            continue;
        }
        if (n % 4 == 0) {
            while (n % 2 == 0)n /= 2;
            int c = 0;
            for (long long j = 2; j * j <= n; ++j) {
                while (n % j == 0) {
                    n /= j;
                    ++c;
                }
            }
            if (n != 1) {
                ++c;
            }
            if (c == 0) {
                cout << "FastestFinger\n";
            }
            else {
                cout << "Ashishgup\n";
            }
            continue;
        }
        n /= 2;
        int c = 0;
        for (long long j = 2; j * j <= n; ++j) {
            while (n % j == 0) {
                n /= j;
                ++c;
            }
        }
        if (n != 1) {
            ++c;
        }
        if (c == 1) {
            cout << "FastestFinger\n";
        }
        else {
            cout << "Ashishgup\n";
        }
    }
    return 0;
}
//freopen("painter.in", "r", stdin);
//freopen("painter.out", "w", stdout);
/*
3
ooo
o..
o..
*/
/* Fri May 15 2020 19:54:42 GMT+0300 (MSK) */

/* Wed May 20 2020 19:33:48 GMT+0300 (MSK) */