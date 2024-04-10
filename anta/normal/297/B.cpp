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
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    map<int,int> a, b;
    rep(i, n) {
        int x; scanf("%d", &x);
        a[x] ++;
    }
    rep(i, m) {
        int x; scanf("%d", &x);
        b[x] ++;
    }
    map<int,int> c;
    each(i, a) c[i->first] = -1;
    each(i, b) c[i->first] = -1;
    k = 0;
    each(i, c) i->second = k ++;
    static ll A[200001], B[200001];
    mset(A, 0); mset(B, 0);
    each(i, a) {
        A[0] += i->second;
        A[c[i->first]+1] -= i->second;
    }
    each(i, b) {
        B[0] += i->second;
        B[c[i->first]+1] -= i->second;
    }
    reu(i, 1, k) A[i] += A[i-1];
    reu(i, 1, k) B[i] += B[i-1];
    bool ok = false;
    rep(i, k) ok |= A[i] > B[i];
    puts(ok ? "YES" : "NO");
    return 0;
}