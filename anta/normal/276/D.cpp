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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
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

ll l, r;
ll dp[65][2][2];
ll rec(int bit, int lgt, int rlt) {
    if(dp[bit+1][lgt][rlt] != -1) return dp[bit+1][lgt][rlt];
    int lbit = l >> bit & 1, rbit = r >> bit & 1;
    ll r = -INFL;
    if(bit == -1) {
        r = 0;
    } else {
        rep(a, 2) if((lgt || lbit <= a) && (rlt || a <= rbit))
        rep(b, 2) if((lgt || lbit <= b) && (rlt || b <= rbit)) {
            ll next = rec(bit-1, lgt || lbit < a, rlt || b < rbit);
            if(next != -INFL)
                r = max(r, ((ll)(a ^ b) << bit) | next);
        }
    }
    return dp[bit+1][lgt][rlt] = r;
}
int main() {
    scanf("%I64d%I64d", &l, &r);
    mset(dp, -1);
    printf("%I64d\n", rec(63, 0, 0));
    return 0;
}