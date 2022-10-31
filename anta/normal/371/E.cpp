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

unsigned long long y[300000];
unsigned long long sum[300000];
unsigned long long linearsum[300000];
int main() {
    int n;
    scanf("%d", &n);
    vpii xs(n);
    rep(i, n) scanf("%d", &xs[i].first);
    rep(i, n) xs[i].second = i;
    int k;
    scanf("%d", &k);
    sort(all(xs));
    rep(i, n-1) y[i] = xs[i+1].first - xs[i].first;
    reu(i, 1, n) sum[i] = sum[i-1] + y[i-1];
    reu(i, 1, n) linearsum[i] = linearsum[i-1] + (ll)y[i-1] * (i-1);

    unsigned long long a = 0;
    reu(j, 0, 0+k-1)
        a += y[j] * (j-0+1) * (0+k-1-j);
    pair<unsigned long long,int> r = mp(a, 0);
    rer(i, 0, n-k) {
        r = min(r, mp(a, i));
        //  (j-(i+1)+1) * ((i+1)+k-1-j) - (j-i+1) * (i+k-1-j)
        //= 2*j-2*i-k+1
        if(i == n-k) break;
        a -= y[i] * (k-1);
        a += (sum[i+k-1] - sum[i+1]) * (-2*i-k+1);
        a += (linearsum[i+k-1] - linearsum[i+1]) * 2;
        a += y[i+k-1] * (k-1);
    }
//  cerr << r.first << endl;
    int x = r.second;
    reu(i, x, x + k) {
        printf("%d", xs[i].second + 1);
        if(i+1 != x + k) putchar(' ');
    }
    puts("");
    return 0;
}