#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
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

char s[5001];
bool b[5001]; int c[5001];
int main() {
    const char *p = "bear"; int m = 4;
    scanf("%s", s);
    int n = strlen(s);
    mset(b, 0);
    rer(i, 0, n-m) {
        bool ok = true;
        rep(j, m) ok &= s[i+j] == p[j];
        b[i] = ok;
    }
    rep(i, n) c[i+1] = c[i] + b[i];
    int ans = 0;
    rep(i, n) rer(j, i+1, n) {
        if((c[j] - c[i]) - (c[j] - c[max(0, j-m+1)]) > 0)
            ans ++;
    }
    printf("%d\n", ans);
    return 0;
}