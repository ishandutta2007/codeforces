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

int p[1000100];
int main() {
    int n;
    scanf("%d",&n);
    mset(p, 0);
    set<ll> s;
    for(int i = 2; i <= 1000010; i ++) {
        if(p[i]==0) {
            s.insert((ll)i*i);
            for(int j = i; j <= 1000010; j += i)
                p[j] = i;
        }
    }
    rep(i, n) {
        ll x;
        scanf("%I64d", &x);
        printf("%s\n", s.count(x)?"YES":"NO");
    }
    return 0;
}