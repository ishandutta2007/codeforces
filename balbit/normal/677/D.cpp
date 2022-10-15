#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<28;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 300*300+1;


ll dst[301][301];
int bist[301][301];
bool done[301][301];
vector<pii> dir = {{0,1},{0,-1},{1,0}, {-1,0}};
vector<pii> at[maxn];

void bfs(int m){
    REP(i,301)REP(j,301) bist[i][j]=iinf, done[i][j]=0;
    queue<pii> qq;
    REP(i,at[m].size()){
        bist[at[m][i].f][at[m][i].s]=dst[at[m][i].f][at[m][i].s];
        qq.push(at[m][i]);
    }
    while (!qq.empty()){
        int r = qq.front().f, c = qq.front().s; qq.pop();
        for (auto xx: dir){
            if (r+xx.f<0 || r+xx.f > 300 || c+xx.s<0 || c+xx.s>300) continue;
            if (bist[r+xx.f][c+xx.s] > bist[r][c]+1){
                bist[r+xx.f][c+xx.s] = bist[r][c]+1;
                qq.push({r+xx.f, c+xx.s});
            }
        }
    }
    REP(i,at[m+1].size()){
        dst[at[m+1][i].f][at[m+1][i].s]=bist[at[m+1][i].f][at[m+1][i].s];
    }
}


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m, p; cin>>n>>m>>p;
    int B = sqrt(n*m);
    REP(i,n) REP(j,m){
        int x; cin>>x;
        at[x].pb({i,j});
        dst[i][j]=iinf;
    }
    // dst[0][0]=0;
    at[0].pb({0,0});
    for (pii x : at[1]){
        dst[x.f][x.s] = x.f+x.s;
    }
    FOR(i,1,p){
        // From i to i+1
        if (at[i+1].size() > B){
            bfs(i);
        }else{
            for (pii x : at[i]) {
                // cout<<"ONE";
                for (pii y : at[i+1]){
                    MNTO(dst[y.f][y.s], (dst[x.f][x.s] + abs(y.f-x.f) + abs(y.s-x.s) ) );
                }
            }
        }
    }


    cout<<dst[at[p][0].f][at[p][0].s]<<endl;
}