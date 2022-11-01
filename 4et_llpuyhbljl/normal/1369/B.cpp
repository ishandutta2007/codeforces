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
const long long m = 1000000007;
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int id1 = -1, id2 = -1;
        string ans = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (id2 == -1)id2 = i;
            }
            else {
                id1 = i;
            }
        }
        if (id2 == -1 || id1 == -1) {
            cout << s << endl;
            continue;
        }
        if (id2 > id1) {
            cout << s << endl;
            continue;
        }
        for (int i = 0; i < id2; ++i)ans.push_back('0');
        ans.push_back('0');
        for (int i = id1 + 1; i < n; ++i)ans.push_back('1');
        cout << ans << endl;
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