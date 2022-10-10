#include <bits/stdc++.h>
using namespace std;
#if DEBUG && !ONLINE_JUDGE
    #include "/home/chaman/Desktop/cpp/debug.h"
#else
    #define debug(args...)
    #define DBG(x...)
#endif
typedef     long long int                        ll;
typedef     long double                          ld;
typedef     vector<ll>                           vi;
typedef     pair<ll,ll>                          pii;
typedef     vector<pii>                          vpi;
typedef     vector<vi>                           vvi;
typedef     map<ll,ll>                           mii;
typedef     map<char,ll>                         mci;
typedef     priority_queue<ll>                   pqi;
typedef     priority_queue<pii>                  pqii;
typedef     priority_queue<ll,vi,greater<ll>>    pqmini;
typedef     priority_queue<pii,vpi,greater<pii>> pqminpi;

#define     fi              first
#define     se              second
#define     sz(a)           (ll)((a).size())
#define     rep(i,n)        for(ll i=0;i<n;i++)
#define     repA(i,a,n)     for(auto i=a;i<=n;i++)
#define     repD(i, a, n)   for(auto i = a; i >= (n); --i)
#define     trav(a, x)      for(auto& a : x)
#define     all(x)          x.begin(), x.end()
#define     fill(a)         memset(a, 0, sizeof (a))
#define     pb              push_back
#define     MOD             1000000007
#define     PI              3.14159265359
#define     EULER           2.7182818284

//////////////////////////////////////////////////////////////////////
vi cnt;
vi w(20,0);
ll btod(string s){
    ll k=0;
    ll l=s.length();
    repD(i,l-1,0){
        k+=(s[i]-'0')*(1<<(l-1-i));
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // ifstream in("input.txt");
    // streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    // cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    // ofstream out("output.txt");
    // streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    // cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
    cout.precision(20);
    ll n,m,q;
    cin>>n>>m>>q;
    rep(i,n){
        cin>>w[i];
    }
    ll ss = (1<<(n));
    cnt = vi(ss+1,0);
    string s;
    rep(i,m){
        cin>>s;
        ll t=btod(s);
        cnt[t]++;
    }
    DBG(w);
    vvi dp(ss,vi(120,0));
    rep(i,ss){
        ll p=0;
        rep(j,ss){
            if(!cnt[j]){continue;}
            ll c =0;
            rep(ii,n){
                if(ii>n-1)break;
                if((i&(1<<ii))==(j&(1<<ii)))c+=w[n-1-ii];
                if(c>100)break;
            }
            if(c<102)dp[i][c]+=cnt[j];
        }
    }
    vi vis(ss,0);
    rep(i,q){
        cin>>s;
        ll w1;
        cin>>w1;
        ll k = btod(s);
        if(!vis[k]){
            vis[k]=1;
            repA(j,1,100){
                dp[k][j]+=dp[k][j-1];
            }
        }
        cout<<dp[k][w1]<<'\n';
    }




    debug("\nRuntime = " + to_string((ld)clock()/(ld)CLOCKS_PER_SEC));
    return 0;
}