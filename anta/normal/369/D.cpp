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
#include <memory>
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

int n, k;
int p[3000];
int ps[3001];
int b[3003][3003];
void amin(int &x, int y) {
    if(x > y) x = y;
}
int main() {
    cin >> n >> k;
    rep(i, n)
        cin >> p[i];
    ps[n] = 0;
    for(int i = n-1; i >= 0; i --)
        ps[i] = max(ps[i+1], p[i]);
    mset(b, INF);
    int r = 0;
    b[0][1] = 0;
    rer(left, 1, n+1) rep(first, left) {
        int x = b[first][left];
//      if(x != INF) cout << first << ", " << left << ": " << x << endl;
        if(x > k) continue;
        r ++;
        if(left >= n) continue;
        if(p[first] != 100 && ps[left] != 0)
            amin(b[left][left+1], x + 1);
        if(p[first] != 0 && ps[left] != 100)
            amin(b[first][left+1], x + 1);
        if(p[first] != 0 && ps[left] != 0)
            amin(b[left+1][left+2], x + 1);
    }
    cout << r << endl;
    return 0;
}