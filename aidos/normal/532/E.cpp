#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <numeric>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define y1 stupid_y1
#define ll long long
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define file "a"

const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);

char s[100100], t[100100];
int n;

int dp[100100][2][2];


int calc(int pos, bool ss, bool tt){
    if ( pos == n + 1 ){
        return ss == 1 && tt == 1;
    }
    int &res = dp[pos][ss][tt];
    if ( res != -1 ) return res;
    res = 0;
    int poss = pos - ss;
    int post = pos - tt;
    if ( poss != n && post != n && s[poss] == t[post] ){
        res = calc(pos+1, ss, tt);
        return res;
    }
    if ( !tt ){
        res += calc(pos+1, ss, tt|1);       
    }
    if ( !ss )
        res += calc(pos+1, ss|1, tt);
    return res;
}


int main () {
    #ifdef LOCAL
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
    #endif

    scanf("%d\n", &n);
    scanf("%s\n", s);
    scanf("%s\n", t);


    memset(dp, -1, sizeof(dp));
    cout <<calc(0, 0, 0)<<endl;





    #ifdef LOCAL
    cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif

    return 0;
}