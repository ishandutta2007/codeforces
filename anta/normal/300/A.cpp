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
    int n;
    scanf("%d", &n);
    vi s[3];
    vi neg, pos; int zeros = 0;
    rep(i, n) {
        int a;
        scanf("%d", &a);
        if(a == 0) zeros ++;
        else if(a > 0) pos.pb(a);
        else if(a < 0) neg.pb(a);
    }
    if(!pos.empty()) {
        s[1].pb(pos.back()); pos.pop_back();
    }else {
        s[1].pb(neg.back()); neg.pop_back();
        s[1].pb(neg.back()); neg.pop_back();
    }
    s[0].pb(neg.back()); neg.pop_back();
    rep(i, zeros) s[2].pb(0);
    each(i, pos) s[2].pb(*i);
    each(i, neg) s[2].pb(*i);
    rep(i, 3) {
        printf("%d ", s[i].size());
        rep(j, s[i].size()) printf("%d ", s[i][j]);
        puts("");
    }
    return 0;
}