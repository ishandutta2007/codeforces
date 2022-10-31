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

int a[200000];
int b[200000];
int main() {
    int n;
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);
    mset(b, 0);
    set<int> notyetoverflowedvessels;
    rep(i, n) notyetoverflowedvessels.insert(i);
    int m;
    scanf("%d", &m);
    rep(i, m) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            int p, x;
            scanf("%d%d", &p, &x);
            p --;
            while(x != 0) {
                auto it = notyetoverflowedvessels.lower_bound(p);
                if(it == notyetoverflowedvessels.end()) break;
                int t = min(x, a[*it] - b[*it]);
                b[*it] += t;
                x -= t;
                if(b[*it] == a[*it])
                    notyetoverflowedvessels.erase(it);
            }
        }else {
            int k;
            scanf("%d", &k);
            k --;
            printf("%d\n", b[k]);
        }
    }
    return 0;
}