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

bool notprime[100100+1];
void sieve(int n){
    notprime[0]=notprime[1]=true;
    rer(i,2,n){
        if(notprime[i])continue;
        else for(int j=i*2;j<=n;j+=i)
            notprime[j] = true;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    static int a[555][555];
    rep(i, n) rep(j, m) scanf("%d", &a[i][j]);
    sieve(100100);
    static int nextprime[100200];
    nextprime[100100+1] = INF;
    for(int i = 100100; i >= 0; i --) {
        if(!notprime[i]) nextprime[i] = i;
        else nextprime[i] = nextprime[i+1];
    }
    int r = INF;
    rep(y, n) {
        int c = 0;
        rep(j, m) c += nextprime[a[y][j]] - a[y][j];
        r = min(r, c);
    }
    rep(x, m) {
        int c = 0;
        rep(i, n) c += nextprime[a[i][x]] - a[i][x];
        r = min(r, c);
    }
    cout << r << endl;
    return 0;
}