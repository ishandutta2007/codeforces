/***************************************** START OF TEMPLATE *********************************************/
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;

#define  SPEED          ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  randomINIT     mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define  foo(i,a,n)     for(ll i = (a); i <= n; i++)
#define  frr(i,a,n)     for(ll i = (a); i >= n; i--)
#define  fo(i,n)        for(ll i = 0; i < n; i++)
#define  newl           cout<<"\n";
#define  f              first
#define  s              second
#define  pb             push_back
#define  mp             make_pair
#define  sym(s)         s="#"+s+"#";   
#define  all(x)         (x).begin(),(x).end()
#define  alll(x, n)     x+1, x+n+1
#define  mset(x,val)    memset(x,val,sizeof(x))
#define  mset1d(a,n,v)  foo(i,0,n+5)a[i]=v;
#define  mset2d(a,n,m,v)foo(i,0,n+5)foo(j,0,m+5)a[i][j]=v;
#define  INP(a,n)       foo(i,1,n) cin>>a[i];
#define  deb1d(a,n)     foo(i,1,n)cout<<a[i]<<" ";newl;
#define  deb2d(a,n,m)   foo(i,1,n){foo(j,1,m){cout<<a[i][j]<<" ";}newl;}    
#define  debm(a)        for(auto it: a)cout<<"{"<<it.f<<","<<it.s<<"}, ";newl;
#define  debp(a,n)      foo(i,1,n)cout<<"{"<<a[i].f<<","<<a[i].s<<"}, ";newl;
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<" ";newl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" ";newl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" ";newl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d;newl;
#define  ll             long long
#define  ld             long double
#define  pll            pair<ll,ll>
#define  vll            vector<ll>
#define  vpll           vector<pll>

const ld   PI    =  3.14159265358979323846; 
const ll   MOD   =  1e+9+7;
const ll   INF   =  LLONG_MAX;
const int  INFi  =  INT_MAX;
const ll   N     =  2e+2+8;

vll adj[N]; ll vis[N];
ll dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

ll test_cases = 1; randomINIT;

/*********************************************************************************************************/
/***************************************** VARIABLE DECLARATIONS *****************************************/
ll n, m,a[N][N],score[N];
vll glob_ans;

/***************************************** FUNCTION IMPLEMENTATIONS **************************************/



/***************************************** START OF MAIN FUNCTION ****************************************/
void MAIN(ll tc){
    cin>>n>>m;
    foo(i,1,m){
        foo(j,1,n){
            cin>>a[i][j];
        }
    }
    foo(i,1,m){
        foo(j,1,n){
            score[j]+=a[i][j];
        }
    }

    ll res = m;
    foo(i,1,m)glob_ans.pb(i);
    foo(k,1,n-1){
        //we are going to make ith guy bear our nth guy
        vpll diff;
        vll temp_ans;
        foo(j,1,m){
            diff.pb({a[j][n]-a[j][k], j});
        }
        sort(all(diff), greater<>());
        ll ksc = score[k];
        ll nsc = score[n];
        ll cnt=0;
        for(auto [d, wh]: diff){
            if(ksc>=nsc)break;
            ksc-=a[wh][k];
            nsc-=a[wh][n];
            temp_ans.pb(wh);
            cnt++;
        }   
        if(ksc<nsc)cnt=INF;
        if(cnt<res){
            res=cnt;
            glob_ans=temp_ans;
        }
        //deb3(k,res,cnt);
    }
    cout<<res;newl;
    debv(glob_ans);
}

int main(){
    SPEED;

    //cin>>test_cases;
    foo(i,1,test_cases){
    MAIN(i);
    }
}