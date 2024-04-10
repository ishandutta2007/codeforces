#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;

using namespace std;

string s;
int x, y;
int dp1[1000100], dp2[1000100];
int pw1[1000100], pw2[1000100];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> s >> x >> y;
    int cur1 = 0;
    int cur2 = 0;
    for(int i = 0; i < s.size(); i++){
        dp1[i] = (cur1 * 10 + s[i] - '0') %x;
        dp2[i] = (cur2 * 10 + s[i] - '0') %y;
        cur1 = dp1[i];
        cur2 = dp2[i];
    }
    pw1[0] = 1;
    pw2[0] = 1;
    for(int i = 1; i<s.size(); ++i){
        pw1[i] = pw1[i-1] * 10 % x;
        pw2[i] = pw2[i-1] * 10 % y;
    }

    cur1=0;
    cur2=0;
    int sum = 0;
    int n = s.size();
    for(int i = n - 1; i>0; i--){
        sum += s[i] - '0';
        if( sum == 0) continue;
        cur1 = (cur1 + (s[i] - '0') * pw1[n - i-1]) %x;
        cur2 = (cur2 + (s[i] - '0' ) * pw2[n-i-1]) %y;
        if(cur2 == 0 && dp1[i-1] == 0){
            cout << "YES\n";
            cout << s.substr(0, i) << endl;
            cout << s.substr(i) << endl;
            return 0;
        }
    }
    cout << "NO\n";



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}