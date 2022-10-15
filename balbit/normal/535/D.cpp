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


void GG(){cout<<"0\n"; exit(0);}

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

const int maxn = 1e6+5;

bool ok[maxn];
bool took[maxn];
char re[maxn];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int N, m; cin>>N>>m;
    string s; cin>>s;
    int n = s.length();
    vector<int> f(n+1); f[0]=-1;
    FOR(i,1,n){
        f[i] = f[i-1];
        while (f[i]!=-1 && s[f[i]+1]!=s[i]){
            f[i] = f[f[i]];
        }
        if (s[f[i]+1]==s[i]) f[i]++;
    }
    // REP(i,n) cout<<f[i]<<'\n';
    for (int at = f[n-1]; at!=-1; at = f[at]){
        ok[at]=1;
    }
    vector<int> y(m);
    REP(i,m){
        cin>>y[i]; y[i]--;
        for (int j = y[i]+n-1; j>=y[i]; j--){
            if (took[j]) break; took[j]=1;
        }
        if (i && y[i]-y[i-1]<n){
            // cout<<"PAT"<<endl;
            int ol = n-(y[i]-y[i-1]); if (!ok[ol-1]) GG();
        }
    }
    int po = 0;
    REP(i,N){
        if (!took[i]) po ++;
    }
    cout<<mpow(26,po)<<endl;
}