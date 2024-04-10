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
    int n, k;
    scanf("%d%d", &n, &k);
    vi p(k);
    rep(i, k) p[i] = i;
    static char vis[8];
    static char next[8];
    ll r = 0;
    rep(p, 1<<3*k){
        int j;
        rep(i, k) if((next[i] = (p >> 3*i & 7)) >= k)
            goto bad;
        ((int*)vis)[0] = 0;
        ((int*)vis)[1] = 0;
        j = 0;
        while(!vis[j]) {
            vis[j] = 1;
            j = next[j];
        }
        if(j != 0) continue;
        reu(i, 1, k) {
            j = i;
            if(vis[j]) continue;
            while(!vis[j]) {
                vis[j] = 1+i;
                j = next[j];
            }
            if(vis[j] == 1+i) goto bad;
        }
        r ++;
        bad:;
    }
    reu(i, k, n) (r *= n - k) %= 1000000007;
    cout << r << endl;
    return 0;
}