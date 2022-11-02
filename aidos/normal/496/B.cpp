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

using namespace std;


int n;
char c[1010], x[1010];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    scanf("%s\n", &c);
    string s;
    for(int i = 0; i < n; i++){
        s += '9';
    }
    for(int i = 0; i < n; i++){
        int t = '9' - c[i] + 1;
        string x = "";
        for(int j = i; j<n; j++){
            int k = c[j] - '0' + t;
            k %= 10;
            x += (char) (k + '0');
        }
        for(int j = 0; j<i; j++){
            int k = c[j] - '0' + t;
            k %= 10;
            x += (char) (k + '0');
        }
        if( x<s) s = x;
    }
    cout << s << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}