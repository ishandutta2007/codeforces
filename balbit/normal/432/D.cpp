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
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int maxn = 1e5+5;
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

int f[maxn];
int dp[maxn];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s; cin>>s;
    f[0]=0; // Star Node
    int n = s.length();
    REP(i,n){
        int j = f[i];
        while (j!=0 && s[i]!=s[j+1-1]){
            j = f[j];
        }
        if (i!=0 && s[i]==s[j]){
            f[i+1] = j+1;
        }else {
            f[i+1]=j;  
        }
        // cout<<i+1<<": "<<f[i+1]<<'\n';
    }
    fill(dp, dp+n+1,1);
    RREP(i,n+1){
        dp[f[i]]+=dp[i];
    }
    vector<pii> re;
    int j = f[n];
    while (j!=0){
        re.pb({j,dp[j]});
        j = f[j];
    }
    cout<<SZ(re)+1<<'\n';
    reverse(ALL(re));
    for (pii xx: re){
        cout<<xx.f<<' '<<xx.s<<'\n';
    }
    cout<<n<<' '<<1<<'\n';
}