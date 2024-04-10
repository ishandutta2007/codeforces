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

int popcount(ll x) {
    int r = 0;
    while(x) {
        if(x & 1) r ++;
        x >>= 1;
    }
    return r;
}

ll n, t;
ll dp[66][66][2];
ll rec(int i, int x, bool lt) {
    if(x < 0) return 0;
    if(dp[i+1][x][lt] != -1) return dp[i+1][x][lt];
    ll r = 0;
    if(i == -1) r = x == 0;
    else rep(b, 2) if(lt || !((n >> i & 1) == 0 && b == 1)) {
        r += rec(i-1, x - b, lt || ((n >> i & 1) && b == 0));
    }
    return dp[i+1][x][lt] = r;
}

int main() {
    cin >> n >> t;
    if(popcount(t) != 1) { cout << "0" << endl; return 0; }
    int log2 = 0;
    while((1LL << log2) != t) log2 ++;
    mset(dp, -1);
    ++ n;
    ll r = rec(62, log2+1, false);
    if(log2 == 0) r --;
    cout << r << endl;
    return 0;
}