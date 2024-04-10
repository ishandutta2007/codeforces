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

int n, m;
int s[5555];
int dp[5555][5555], dp2[5555][5555];

int rec2(int j, int i) {
    if(dp2[j][i] != -1) return dp2[j][i];
    int r = 0;
    if(i == n) r = 0;
    else r = (j == s[i] ? 1 : 0) + rec2(j, i+1);
    return dp2[j][i] = r;
}

int rec(int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];
    int r = INF;
    if(j == m) {
        r = 0;
    }else {
        int x = rec2(j, i);
        r = min(r, x + rec(i, j+1));
        if(i != n) {
            r = min(r, (s[i] > j ? 1 : 0) + rec(i+1, j));
        }
    }
    return dp[i][j] = r;
}

int main() {
    cin >> n >> m;
    rep(i, n) {
        double x;
        cin >> s[i] >> x;
        s[i] --;
    }
    mset(dp, -1); mset(dp2, -1);
    cout << rec(0, 0) << endl;
    return 0;
}