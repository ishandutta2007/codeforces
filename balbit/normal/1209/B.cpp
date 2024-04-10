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

const int maxn = 1e2+1;

bool on[maxn];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    string s; cin>>s;
    vector<int> a(n), b(n);
    REP(i,n) cin>>b[i]>>a[i];
    int re = 0;
    REP(i,n) re += s[i]=='1', on[i]=s[i]=='1';
    int mx = re;
    FOR(t, 1, 10000){
        REP(i,n){
            if (t-a[i] >= 0 && (t-a[i])%b[i]==0){
                if (on[i]) re--;
                else re++;
                on[i] ^= 1;
                // cout<<"HO"<<endl;
            }
        }
        MX(mx, re);
    }
    cout<<mx<<endl;
    
}