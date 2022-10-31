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
#define reps(i,n,s) for(int (i)=0;(i)<(int)(n);(i)+=(s))
#define reus(i,l,u,s) for(int (i)=(int)(l);(i)<(int)(u);(i)+=(s))
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

vector<vi> g;
int b[111111];
int K;
vi w;
int dfs(int i, int t) {
    b[i] = t;
    random_shuffle(all(g[i]));
    each(j, g[i]) if(b[*j] == 0) {
        if(int x = dfs(*j, t+1)) {
            w.pb(i);
            if(x-1 == i) {
                return 0;
            }else return x;
        }else return 0;
    }else if(t-b[*j] >= K) {
        w.pb(i);
        return *j+1;
    }
    return 0;
}
int main() {
    int n, m;
    cin >> n >> m >> K;
    g.resize(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a --, b --;
        g[a].pb(b);
        g[b].pb(a);
    }
    clock_t c = clock();
    while(1) {
        mset(b, 0);
        dfs((rand()*(RAND_MAX+1)+rand())%n, 1);
        if(w.size()) {
            cout << w.size() << endl;
            rep(i, w.size()) cout << w[i]+1 << " ";
            cout << endl;
            return 0;
        }
    }
    return 1;
}