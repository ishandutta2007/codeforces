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

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    static int a[200100];
    rep(i, n) scanf("%d", &a[i]);
    static int count[200100];
    mset(count, 0);
    rep(i, q) {
        int l, r;
        scanf("%d%d", &l, &r);
        l --, r --;
        count[l] ++, count[r+1] --;
    }
    reu(i, 1, n) count[i] += count[i-1];
    sort(count, count+n, greater<int>());
    sort(a, a+n, greater<int>());
    ll sum = 0;
    rep(i, n) sum += (ll)count[i] * a[i];
    printf("%I64d\n", sum);
    return 0;
}