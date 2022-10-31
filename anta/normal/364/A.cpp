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

int main() {
    int a;
    cin >> a;
    string s;
    cin >> s;
    int n = s.size();
    static int sumcnts[9*4000+1];
    rep(i, n) {
        int sum = 0;
        rer(j, i+1, n) {
            sum += s[j-1] - '0';
            sumcnts[sum] ++;
        }
    }
    ll r = 0;
    if(a == 0) {
        int segs = n * (n+1) / 2;
        r += (ll)sumcnts[0] * segs;
        r += (ll)segs * sumcnts[0];
        r -= (ll)sumcnts[0] * sumcnts[0];
    }else for(int i = 1; i*i <= a; i ++) if(a % i == 0) {
        rep(bb, 2) {
            if(i*i == a && bb) break;
            int x = !bb ? i : a / i, y = a / x;
            if(x > 9*4000 || y > 9*4000) continue;
            r += (ll)sumcnts[x] * sumcnts[y];
        }
    }
    cout << r << endl;
    return 0;
}