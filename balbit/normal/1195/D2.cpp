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

#define int ll

const int maxn = 1e5+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 998244353;


void GG(){cout<<"No\n"; exit(0);}

ll pow(ll a, ll n){ // a^n % mod
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

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    ll re = 0;
    int len; 
    vector<string >str;
    vector<int> app(11);
    REP(i,n){
        string s; cin>>s; str.pb(s);
        app[s.length()]++;
    }
    vector<int> ps(11);
    FOR(i,1,11){
        ps[i]=ps[i-1]+app[i];
    }
    REP(j,n){
        string s = str[j];
        len = s.length();
        vector<ll> myps(len+1);
        FOR(i,1,len){
            myps[i]=(myps[i-1]*10+(s[i-1]-'0'))%mod;
        }
        int p10 = 1;
        int npush = 1;
        int sum = 0;
        RREP(i,len){
            sum+=p10*(s[i]-'0')%mod; sum%=mod;
            re+=app[npush]*sum*11%mod; 
            p10*=100; p10%=mod;
            re+=2*app[npush]*myps[len-npush]*p10;
            npush++;
            re%=mod;
        }
        FOR(i,npush,11){
            re+=sum*app[i]*11;
        }


        re%=mod;
    }
    cout<<(re)%mod<<endl;

    
}