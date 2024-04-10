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

const int maxn = 1e5+5;

int nq[maxn]; // Number of question marks on prefix sum, 1-indexed
int ldif[maxn]; // Last different
pii dp[maxn]; // (greatest number, greatest remaining question marks), 1-indexed
int type[maxn];


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ldif[0]=-1;
    int totq = 0;
    int n; cin>>n;
    string s; cin>>s;
    // int n = s.length();
    int m; cin>>m;
    vector<int> a(s.length());
    int prev = -1, lat = -1;
    vector<int> tp(3);
    REP(i, s.length()){
        nq[i+1]=nq[i];
        if (i) ldif[i]=ldif[i-1];
        if (s[i]=='a'){
            a[i]=0^(i&1);
            tp[a[i]]++;
        }else if (s[i]=='b'){
            a[i]=1^(i&1); 
            tp[a[i]]++;
        }else{
            // if (i+m-1-1>=0) type[i+m-1]=type[i+m-1-1];
            a[i]=2; nq[i+1]++; 
        }
        
        if (tp[0]>0 && tp[1]==0) type[i]=0;
        else if (tp[0]==0&& tp[1]>0 ) type[i]=1;
        else if (tp[0]>0 && tp[1]>0) type[i]=-1;
        else type[i]=2;
        if (i-m+1>=0) {
            tp[a[i-m+1]]--;
        }
    }
    dp[0]={0,iinf};
    REP(i, n){
        dp[i+1]=dp[i];
        if (i>=m-1){
            // cout<<i<<' '<<type[i]<<endl;
            int head = i-m+1; 
            if ((type[i]==2 ) or (type[i]^(head&1)==0) and (type[i]!=-1)){
                // cout<<"I can change at "<<i+1<<endl;
                pii poss = {dp[head].f+1, dp[head].s - (nq[i+1]-nq[head]) };
                MXTO(dp[i+1],poss);
            } 
            
        }
    }
    cout<<iinf-dp[n].s<<endl;
}