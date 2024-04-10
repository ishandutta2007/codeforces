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
#include <csetjmp>
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
template<typename T, typename U> inline void amin(T &x, U y) { if(x > y) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int c[100];
int main() {
    //zero-sum
    //
    //zero-sum
    //

    //(a) floor(s_i/2)
    //(b) 
    //(c) 
    //  (1) 1
    //  (2) 
    //  (3) 
    //(a),(b)(3)
    //(c)(1),(2)greedy
    //
    //
    //

    int n;
    scanf("%d", &n);
    vi mids;
    int ans[2] = {};
    rep(i, n) {
        int s;
        scanf("%d", &s);
        rep(i, s) scanf("%d", &c[i]);
        rep(i, s / 2) {
            ans[0] += c[i];
            ans[1] += c[s-1-i];
        }
        if(s % 2 == 1)
            mids.pb(c[s / 2]);
    }
    sort(all(mids), greater<int>());
    rep(i, mids.size())
        ans[i % 2] += mids[i];
    printf("%d %d\n", ans[0], ans[1]);
    return 0;
}