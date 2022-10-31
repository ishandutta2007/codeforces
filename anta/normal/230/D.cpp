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

vector<vpii> w;
map<pii,int> o;
map<pii,int> ot;
set<pii> os;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    w.clear();
    w.resize(n);
    rep(i, m) {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        a--;b--;
        w[a].pb(mp(b,c));
        w[b].pb(mp(a,c));
    }
    rep(i, n) {
        int k;
        scanf("%d", &k);
        rep(j, k) {
            int t;
            scanf("%d", &t);
            os.insert(mp(t, i));
        }
    }
    each(i, os) {
        pii p = mp(i->first-1,i->second);
        if(os.count(p)) {
            o[*i] = o[mp(ot[p],i->second)];
            o[mp(ot[p],i->second)] ++;
            ot[*i] = ot[p];
        }else {
            ot[*i] = i->first;
            o[*i] = 1;
        }
    }
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(mp(0, 0));
    int t = 0;
    map<int,int> y;
#define NEXT(f,s) if(!y.count(s) || y[s] > (f)) q.push(mp((f),(s)))
    while(!q.empty()) {
        pii p = q.top(); q.pop();
        if(p.second == n-1) {
            printf("%d\n", p.first);
            return 0;
        }
        if(o.count(p)) {
            NEXT(p.first+o[p], p.second);
        } else {
            if(y.count(p.second) && y[p.second] <= p.first) {
                continue;
            } else y[p.second] = p.first;
            each(j, w[p.second]) NEXT(p.first+j->second, j->first);
        }
    }
    printf("-1\n");
    return 0;
}