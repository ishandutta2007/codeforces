/**
 *    author:  SPb ITMO University 1
 *    created: 27.10.2016 11:46:58       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int MAXN = 5120;
const int INF = (int)(1e9);

int n, m, w;
int qq;
vector<int> e[MAXN];
vector<pair<int, int> > a[MAXN];
int q[MAXN], qL, qR;
int d[MAXN];

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    scanf("%d",&w);
    for (int i = 0; i < w; i++) {
        int c, k, p;
        scanf("%d%d%d", &c, &k, &p);
        a[--c].push_back(make_pair(p, k));
    }

    scanf("%d", &qq);
    for (int it = 0; it < qq; it++) {
        //cerr << endl;
        int g, r, mx;
        scanf("%d%d%d", &g, &r, &mx);
        --g;

        priority_queue<pair<int, int> > pq;
        int cnt = 0;
        ll cost = 0;

        for (int i = 0; i < n; i++) d[i] = INF;
        qL = 0, qR = 0;
        q[qR++] = g;
        d[g] = 0;

        int ans = -1;        
        while (qL < qR) {
            int v = q[qL++];
            //cerr << v << " " << d[v] << endl;
            for (int to : e[v]) {
                if (d[to] > d[v] + 1) {
                    d[to] = d[v] + 1;
                    q[qR++] = to;
                }
            }

            for (auto o : a[v]) {
                pq.push(o);
                cnt += o.second;
                cost += 1LL * o.first * o.second;
            }

            while (cnt > r) {
                auto o = pq.top();
                pq.pop();
                cnt -= o.second;
                cost -= 1LL * o.second * o.first;
                if (cnt < r) {
                    int x = r - cnt;
                    cnt += x;
                    cost += 1LL * x * o.first;
                    pq.push(make_pair(o.first, x));
                }
            }

            if (cnt == r && cost <= mx) {
                ans = d[v];
                break;
            }
        }
        printf("%d\n", ans);
    }
    
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}