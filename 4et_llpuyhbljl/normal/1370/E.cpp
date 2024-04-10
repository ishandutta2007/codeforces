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
const int Y = 1100;
const long long mod = 1000000007;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int c1 = 0;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1')++c1;
        if (t[i] == '1')--c1;
    }
    if (c1 != 0) {
        cout << -1;
        return 0;
    }
    string s1 = "", t1 = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            s1.push_back(s[i]);
            t1.push_back(t[i]);
        }
    }
    int l1 = 0, l2 = 0;
    n = s1.length();
    int ans = 0;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == '1')++b;
        else --b;
        l1 = max(l1, b);
        l2 = min(l2, b);
    }
    ans = l1 - l2;
    cout << ans << endl;
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