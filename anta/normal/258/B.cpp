#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <stack>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define reps(i,n,s) for(int (i)=0;(i)<(int)(n);(i)+=(s))
#define reus(i,l,u,s) for(int (i)=(int)(l);(i)<(int)(u);(i)+=(s))
#if defined(_MSC_VER)
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;


const ll MOD = 1000000007;
int mDigits[12];
int dp[12][10][2][2];
int counting(int i, int lucky, bool lz, bool cmp) {
    if(lucky < 0) return 0;
    if(dp[i][lucky][lz][cmp] != -1) return dp[i][lucky][lz][cmp];
    int r = 0;
    if(i == 11) return lucky == 0 && lz;
    rep(d, 10) if(cmp || d <= mDigits[i]) {
        r += counting(i+1, lucky - (d == 4 || d == 7), lz || d != 0, cmp || d < mDigits[i]);
    }
    return dp[i][lucky][lz][cmp] = r;
}
int main() {
    int m;
    cin >> m;
    int x = m; rep(i, 11) mDigits[i] = x % 10, x /= 10;
    reverse(mDigits, mDigits+11);
    static int count[10];
    mset(dp, -1);
    rer(i, 0, 9) {
        count[i] = counting(0, i, false, false);
    }
    ll r = 0;
    rer(myCount, 0, 9) {
        rep(i1, 10) rep(i2, 10) rep(i3, 10) rep(i4, 10) rep(i5, 10) rep(i6, 10) {
            int is[7] = {i1, i2, i3, i4, i5, i6};
            if(accumulate(is, is+6, 0) >= myCount) continue;
            is[6] = myCount;
            sort(is, is+7);
            ll x = 1; int t = 0;
            rep(i, 7) {
                if(i == 0 || is[i-1] != is[i]) t = 0;
                else t ++;
                (x *= count[is[i]] - t) %= MOD;
            }
            (r += x) %= MOD;
        }
    }
    cout << r << endl;
    return 0;
}