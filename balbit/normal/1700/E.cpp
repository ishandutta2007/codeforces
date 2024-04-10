#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define f first
#define s second

#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)

#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define pb push_back

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<"- "<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template<typename T> void _do( T && x) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do( T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif // BALBIT

const int maxn = 4e5+5;

pii where[maxn];
vector<vector<int> > g;
vector<vector<int> > now;
int nbad = 0;

inline bool bad(int r, int c) {
//    bug(r,c);
    return g[r][c] != 1 && min({g[r-1][c],g[r+1][c],g[r][c-1],g[r][c+1]}) > g[r][c];
}

void upd(int r, int c) {
    if (g[r][c] == 1000000) return;
    nbad -= now[r][c];
    now[r][c] = bad(r,c);
    nbad += now[r][c];
}

int dx[] = {0,1,0,-1,0};
int dy[] = {1,0,-1,0,0};

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    bug(1,2);

    int n,m; cin>>n>>m;
    g.resize(n+2, vector<int>(m+2, 1000000));
    now.resize(n+2, vector<int>(m+2, 0));

    REP1(i,n) REP1(j,m) {
        cin>>g[i][j];
    }


    REP1(i,n) REP1(j,m) {
        now[i][j] = bad(i,j);
        nbad += now[i][j];
        bug(i,j,now[i][j]);
    }

    if (nbad == 0) {
        cout<<0<<endl; return 0;
    }

    int R, C;
    REP1(i,n) REP1(j,m) {
        if (now[i][j]) {
            R = i, C = j;
            break;
        }
    }
    vector<pii> re;
    REP(J, 5) {
        int r = R + dx[J], c = C + dy[J];

        if (g[r][c] != 1000000) {
            bug(r,c);
            REP1(OR,n) REP1(oc,m) {
                if (g[r][c] == g[OR][oc]) continue;
                swap(g[r][c], g[OR][oc]);

                REP(J,5) {
                    upd(r+dx[J], c+dy[J]);
                    upd(OR+dx[J], oc+dy[J]);
                }

                bug(r,c,OR,oc);

                if (nbad == 0) {
                    int x = g[r][c], y = g[OR][oc];
                    if (x > y) swap(x,y);
                    bug(x,y);
                    re.pb({x,y});
                }

                swap(g[r][c], g[OR][oc]);
                REP(J,5) {
                    upd(r+dx[J], c+dy[J]);
                    upd(OR+dx[J], oc+dy[J]);
                }
            }
        }
    }
    sort(ALL(re)); re.resize(unique(ALL(re)) - re.begin());

    if (SZ(re)) {
        cout<<1<<' '<<SZ(re)<<endl;
    }else{
        cout<<2<<endl;
    }


}