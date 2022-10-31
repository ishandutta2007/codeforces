#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#ifdef __GNUC__
#define aut(v, x) __typeof(x) v = (x)
#else
#define aut(v, x) auto v = (x)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
using namespace std;
typedef long long ll; typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pii> vpii;
const int INF = 0x3f3f3f3f; const ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ll n;
    scanf("%I64d",&n);
    int a[10] = {};
    for(ll x = n; x > 0; x /= 10) a[x%10] ++;
    int r = 0;
    for(ll i = 1; i*i <= n; i ++) if(n%i==0){
        for(ll x = i; x > 0; x /= 10) if(a[x%10]) goto ok;
        continue;
ok:;
        r++;
    }
    for(ll i = 1; i*i <= n; i ++) if(n%i==0&&n/i!=i){
        for(ll x = n/i; x > 0; x /= 10) if(a[x%10]) goto ok2;
        continue;
ok2:;
        r++;
    }
    printf("%d\n",r);
    return 0;
}