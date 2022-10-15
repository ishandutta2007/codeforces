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

const int iinf = 1<<29;
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

const int maxn = 1e6+5;

int n, k; 
int dep[maxn], blk[maxn];
int fa[21][maxn];
vector<int> g[maxn];
int top = -1;


void lcadfs(int v){
    for (int u:g[v]){
        if (u!=fa[0][v]){
            fa[0][u] = v;
            dep[u] = dep[v]+1;
            lcadfs(u);
        }
    }
}

void build(){
    FOR(i,1,21){
        REP(j,maxn){
            fa[i][j] = fa[i-1][fa[i-1][j]];
        }
    }
}

int kth(int a, int k){
    REP(i,21){
        if (k&(1<<i)){
            a = fa[i][a];
        }
    }
    return a;
}

int lca(int a, int b){
    if (dep[a]<dep[b]) swap(a,b);
    a = kth(a,dep[a]-dep[b]);
    RREP(j, 21){
        if (fa[j][a]!=fa[j][b]){
            a = fa[j][a]; b = fa[j][b];
        }
    }
    return a==b? a : fa[0][a];
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    k = n-k;
    REP(i,n-1){
        int a, b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    lcadfs(0); build();
    RREP(cnt,n){
        int i = cnt;
        if (blk[i]) continue;
        if (top == -1){
            top = i;
            blk[i] = 1; k--;
        }else{
            int c = lca(top, i);

            if (c==i){
                int df = dep[top] - dep[i];
                if (k>=df){
                    k-=df;
                    REP(j,df){
                        top = fa[0][top]; blk[top]= 1;
                    }
                }
            }else{
                
                if (c==top){
                    int at = i;
                    RREP(j,21){
                        if (dep[fa[j][i]]>dep[top] && blk[fa[j][i]]==0){
                            i = fa[j][i];
                        }
                    }
                    int df = dep[at] - dep[i] + 1;
                    // debug(df);
                    if (k<df) continue;
                    k-=df;
                    while (at != i){
                        blk[at] = 1; at = fa[0][at];
                    }
                    blk[i] = 1;
                }else{
                    int dst = dep[top] - dep[c] + dep[i] - dep[c];
                    if (k >= dst){
                        k-=dst;
                        while (i != c){
                            blk[i] = 1; i = fa[0][i];
                        }
                        while (top != c){
                            blk[top] = 1; top = fa[0][top];
                        }
                        blk[top] = 1;
                        assert(top==c);
                    }
                }
            }
        }
    }
    REP(i,n){
        if (!blk[i]){
            cout<<i+1<<' ';
        }
    }
}