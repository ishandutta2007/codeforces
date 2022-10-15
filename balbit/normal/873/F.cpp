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

/*he[i]
 *sa[i]i
 *rk[i]  */

const int MAX = 2e5+5;

int ct[MAX], he[MAX], rk[MAX];
int sa[MAX], tsa[MAX], tp[MAX][2];
void suffix_array(string ip){
    int len = (ip).length();
    int alp = 256;
    memset(ct, 0, sizeof(ct));
    for(int i=0;i<len;i++) ct[ip[i]+1]++;
    for(int i=1;i<alp;i++) ct[i]+=ct[i-1];
    for(int i=0;i<len;i++) rk[i]=ct[ip[i]];
    for(int i=1;i<len;i*=2){
        for(int j=0;j<len;j++){
            if(j+i>=len) tp[j][1]=0;
            else tp[j][1]=rk[j+i]+1;        
            tp[j][0]=rk[j];
        }
        memset(ct, 0, sizeof(ct));
        for(int j=0;j<len;j++) ct[tp[j][1]+1]++;
        for(int j=1;j<len+2;j++) ct[j]+=ct[j-1];
        for(int j=0;j<len;j++) tsa[ct[tp[j][1]]++]=j;
        memset(ct, 0, sizeof(ct));
        for(int j=0;j<len;j++) ct[tp[j][0]+1]++;
        for(int j=1;j<len+1;j++) ct[j]+=ct[j-1];
        for(int j=0;j<len;j++)
      sa[ct[tp[tsa[j]][0]]++]=tsa[j];
        rk[sa[0]]=0;
        for(int j=1;j<len;j++){
            if( tp[sa[j]][0] == tp[sa[j-1]][0] &&
                tp[sa[j]][1] == tp[sa[j-1]][1] )
                rk[sa[j]] = rk[sa[j-1]];
            else
                rk[sa[j]] = j;
        }
    }
    for(int i=0,h=0;i<len;i++){
        if(rk[i]==0) h=0;
        else{
            int j=sa[rk[i]-1];
            h=max(0,h-1);
            for(;ip[i+h]==ip[j+h];h++);
        }
        he[rk[i]]=h;
    }
}

int par[MAX];
int rnk[MAX];

//No union by rank 
void setUp (int n){
    for (int i=0; i<n; i++) par[i]=i, rnk[i]=1; //From 0
}

int find(int x){
    if (x==par[x]){
        return x;
    }
    else{
        par[x]=find(par[x]);
        return par[x];
    }
}

void merge(int a, int b){
    if (a==-1 || b==-1) return;
    a=find(a), b = find(b);
    if (rnk[a]<rnk[b]) swap(a,b);
    rnk[a]+=rnk[b];
    par[b]=par[a];
}

vector<pii> mrg[MAX];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    setUp(n);
    string s; cin>>s;
    reverse(ALL(s));
    suffix_array(s);
    ll re = 0;
    string bl; cin>>bl;
    reverse(ALL(bl));
    int tmpprv = -1;
    // fill(next, next+MAX, -1); 
    // vector<int> a;
    // REP(i,n){
    //     cout<<he[i]<<' ';
    // }
    // cout<<endl;
    REP(i,n){
        if (bl[i]=='0'){
            MXTO(re, n-i);
            // if( re== 200000) assert(0);
        }
    }  
    
    RREP(i,n){
        if (bl[i]=='0'){
            int at = rk[i];
            int LPF = iinf; // Longest Prefix
            for (int j = at-1; j>=0; j--){
                MNTO(LPF, he[j+1]);   
                if (bl[sa[j]]=='0'){
                    if (LPF) mrg[LPF].pb({at, j});
                    break;
                } 
            } 
        } 
    } 
    
    RREP(i,n+1){
        for (auto &x : mrg[i]){
            merge(x.f, x.s);
            MXTO(re, (ll)rnk[find(x.f)] * (ll)i);
        }
    }
    cout<<re<<endl;
}