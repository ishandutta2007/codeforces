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

int q[111], qr[111], s[111];
int d[222][111];
int dp[111][222];
bool ss[222];
int n, k;
bool rec(int kk, int i) {
    if(dp[kk][k+i] != -1) return dp[kk][k+i];
    if(kk == 0) return ss[k+i];
    bool r;
    if(ss[k+i]) r = false;
    else {
        r = rec(kk-1, i-1) || rec(kk-1, i+1);
    }
    return dp[kk][k+i] = r;
}
int main() {
    cin >> n >> k;
    rep(i, n) cin >> q[i], q[i]--;
    rep(i, n) cin >> s[i], s[i]--;
    rep(i, n) qr[q[i]] = i;
    rep(i, n) d[k+0][i] = i;
    rer(i, 1, k) rep(j, n) d[k+i][j] = d[k+i-1][q[j]];
    rer(i, 1, k) rep(j, n) d[k-i][j] = d[k+-i+1][qr[j]];
    rer(i, -k, k) {
        ss[k+i] = vi(d[k+i], d[k+i]+n) == vi(s, s+n);
    }
    mset(dp, -1);
    bool r = rec(k, 0);
    cout << (r ? "YES" : "NO") << endl;
    return 0;
}