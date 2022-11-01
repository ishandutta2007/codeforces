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
        vector < int>a;
        vector<int>b;
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n; ++i) {
            int tmp;
            cin >> tmp;
            if (tmp % 2 == 0)a.push_back(i);
            else b.push_back(i);
        }
        for (int i = 1; i <= n - 1; ++i) {
            if (a.size() >= 2) {
                cout << a.back() << " ";
                a.pop_back();
                cout << a.back() << "\n";
                a.pop_back();
            }
            else {
                cout << b.back() << " ";
                b.pop_back();
                cout << b.back() << "\n";
                b.pop_back();
            }
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