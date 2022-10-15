#include <bits/stdc++.h>

#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define bug(x) cerr<<#x<<" is "<<x<<endl

using namespace std;

#define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 55;

int vx[55], vy[55], my[55], mx[55];
ll slk[55], lx[55], ly[55];
int g[55][55];
int n;

bool dfs(int v){
    vx[v] = 1;
    REP(i,n){
        if (vy[i]) continue;
        if (g[v][i] == lx[v] + ly[i]) {
            vy[i] = 1; 
            if (my[i]==-1 || dfs(my[i])){
                my[i] = v; mx[v] = i;return 1;
            }
        }else{
            MN(slk[i], lx[v] + ly[i] - g[v][i]); 
        }
    }
    return 0;
}

void mxmch(){
    REP(i,n) REP(j,n) MX(lx[i], g[i][j]);
    fill(my, my+n, -1);  fill(mx, mx+n, -1);
    REP(i,n){
        while (1){
            fill(vx, vx+n, 0); fill(vy, vy+n, 0); fill(slk, slk+n, inf);
            if (dfs(i)) break;
            ll hv = *min_element(slk, slk+n);
            REP(i,n) if (vx[i]) lx[i] -= hv;
            REP(i,n) if (vy[i]) ly[i] += hv;
        }
    }
    ll re= 0;
    REP(i,n){
        re += g[my[i]][i];
    }
    cout<<re<<endl;
    REP(i,n){
        int m = mx[i];
        if (m>=26) cout<<(char)('A' + m - 26);
        else cout<<(char)('a' + m);
    }
}

int id(char c){
    if (c>='a' && c<='z') return c-'a';
    else return c-'A' + 26;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int N; cin>>N>>n;
    string a, b; cin>>a>>b;
    REP(i,N){
        g[id(a[i])][id(b[i])]++;
    }
    mxmch();
}