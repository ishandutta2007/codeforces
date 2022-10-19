#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 4e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

ll pot(ll b, int exp){
    if(exp == 0) return 1;
    ll a = pot(b,exp/2);
    a *= a;
    if(exp % 2 == 1) a *= b;
    a %= mod;
    return a;
}

/*void c(){
    string s,t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    vll dp(m);
    F0(i,m) if(t[i] == s[0]) dp[i] = 1;

    ll res = 0;
    vll nuevoDp(m);
    if(m == 1 and s[0] == t[0]) res += 1;
    F1(i,n-1){
        F0(l,m) nuevoDp[l] = 0;
        //agregar atras
        F0(l,m){
            if(l+i < m and s[i] == t[l+i]) nuevoDp[l] += dp[l];
            if(l+i >= m) nuevoDp[l] += dp[l];
        }
        //agregar adelante
        F0(l,m-1) {
            if(t[l] == s[i]){
                if(l+1 < m) nuevoDp[l] += dp[l+1];
                nuevoDp[l] %= mod;
            }
        }
        if(t[m-1] == s[i]) nuevoDp[m-1] += pot(2,i-1);

        dp = nuevoDp;
        if(i >= m-1) res += dp[0];
        res %= mod;
    }
    cout<<(res*2)%mod<<'\n';
}*/

void c(){
    string s,t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    vvll dp(m,vll(m));
    F0(i,m) if(t[i] == s[0]) dp[i][i] = 1;

    ll res = 0;
    if(m == 1 and s[0] == t[0]) res += 1;
    F1(i,n-1){
        F0(l,m-1) {
            if(t[l] == s[i]){
                int r = min(m-1,l+i);
                dp[l][r] += dp[l+1][r];
                dp[l][r] %= mod;
            }
        }
        F1(r,m-1){
            if(t[r] == s[i]){
                int l = max(0,r-i);
                dp[l][r] += dp[l][r-1];
                dp[l][r] %= mod;
            }
        }
        if(t[m-1] == s[i]) dp[m-1][m-1] += pot(2,i-1);
        F0(l,m-1){
            int r = l+i-1;
            if(r < m-1) dp[l][r] = 0;
        }
        res = (res + dp[0][m-1])%mod;
    }
    cout<<(res*2)%mod<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../c2.in","r",stdin);
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}