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
    #define  all(x)         (x).begin(),(x).end()
    #define  mset(x,val)    memset(x,val,sizeof(x))
    #define  newl           cout<<"\n"
    #define  f              first
    #define  s              second
    #define  pb             push_back
    #define  INPa(a,n)      foo(i,1,n) cin>>a[i];
    #define  deb2d(a,n,m)   foo(i,1,n){foo(j,1,m){cout<<a[i][j]<<" ";}newl;}    
    #define  deb1d(a,n)     foo(i,1,n)cout<<a[i]<<" ";newl;
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
     
    const ll   MOD   =  1e+9+7;
    const ll   INF   =  LLONG_MAX;
    const int  INFi  =  INT_MAX;
    const ll   N     =  1e+5+8;
     
    vll adj[N]; ll vis[N];
    ll dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};
     
    ll test_cases = 1; randomINIT;
     
    /*********************************************************************************************************/
    /***************************************** VARIABLE DECLARATIONS *****************************************/
    ll nr, ng, nb, r[N], g[N], b[N];
    ll X, Y, Z;
     
    /***************************************** FUNCTION IMPLEMENTATIONS **************************************/
    ll P1(ll key, ll c, ll ch){
        if(ch == 1){
            return r[key] >= c;
        }
        if(ch == 2){
            return g[key] >= c;
        }
     
        return b[key] >= c;
    }
     
    ll P2(ll key, ll c, ll ch){
        
        if(ch == 1){
            return r[key] <= c;
        }
     
        if(ch == 2){
            return g[key] <= c;
        }
     
        return b[key] <= c;
    }
     
    ll bsmin(ll L, ll R, ll c, ll ch){
        while (L < R) { 
          ll mid = (L + R) / 2;
          if (P1(mid, c, ch)) R = mid;
          else L = mid + 1;
        }
        return L;
    }
     
    ll bsmax(ll L, ll R, ll c, ll ch){
        while (L < R) {
            ll mid = (L + R + 1) / 2;
            if (P2(mid, c, ch)) L = mid;
            else R = mid - 1;
        } 
        return L;
    }
     
    ll sq(ll x){
        return x*x;
    }
     
    ll ret(){
        return sq(abs(X-Y)) + sq(abs(Y-Z)) + sq(abs(Z-X)); 
    }
     
     
    /***************************************** START OF MAIN FUNCTION ****************************************/
    void MAIN(ll tc){
        ll ans = INF; 
        cin>>nr>>ng>>nb; 
        INPa(r,nr); INPa(g,ng); INPa(b,nb);
        sort(r+1, r+nr+1); sort(g+1, g+ng+1); sort(b+1, b+nb+1);
        foo(i,1,nr){
            X = r[i];
            Y = g[bsmin(1,ng,X,2)];
            Z = b[bsmin(1,nb,Y,3)];
            //deb3(X,Y,Z);
            ans = min(ans, ret());
            
            Z = b[bsmax(1,nb,Y,3)];
            //deb3(X,Y,Z);
            ans = min(ans, ret());
     
            Y = g[bsmax(1,ng,X,2)];
            Z = b[bsmin(1,nb,Y,3)];
            ans = min(ans, ret());
            //deb3(X,Y,Z);
     
            Z = b[bsmax(1,nb,Y,3)];
            //deb3(X,Y,Z);
            ans = min(ans, ret());
        }
     
        foo(i,1,nr){
            X = r[i];
            Z = b[bsmin(1,nb,X,3)];
            Y = g[bsmin(1,ng,Z,2)];
            //deb3(X,Y,Z);
            ans = min(ans, ret());
            
            Y = g[bsmax(1,ng,Z,2)];
            //deb3(X,Y,Z);
            ans = min(ans, ret());
     
            Z = b[bsmax(1,nb,X,3)];
            Y = g[bsmin(1,ng,Z,2)];
            ans = min(ans, ret());
            //deb3(X,Y,Z);
     
            Y = g[bsmax(1,ng,Z,2)];
            //deb3(X,Y,Z);
            ans = min(ans, ret());
        }
     
        foo(i,1,ng){
            Y = g[i];
            Z = b[bsmin(1,nb,Y,3)];
            X = r[bsmin(1,nr,Z,1)];
            //deb3(X,Y,Z);
            ans = min(ans, ret());
            
            X = r[bsmax(1,nr,Z,1)];
            //deb3(X,Y,Z);
            ans = min(ans, ret());
     
            Z = b[bsmax(1,nb,Y,3)];
            X = r[bsmin(1,nr,Z,1)];
            ans = min(ans, ret());
            //deb3(X,Y,Z);
     
            X = r[bsmax(1,nr,Z,1)];
            //deb3(X,Y,Z);
            ans = min(ans, ret());
        }
     
        foo(i,1,ng){
            Y = g[i];
            Z = r[bsmin(1,nr,Y,1)];
            X = b[bsmin(1,nb,Z,3)];
            //deb3(X,Y,Z);
            ans = min(ans, ret());
            
            X = b[bsmax(1,nb,Z,3)];
            //deb3(X,Y,Z);
            ans = min(ans, ret());
     
            Z = r[bsmax(1,nr,Y,1)];
            X = b[bsmin(1,nb,Z,3)];
            ans = min(ans, ret());
            //deb3(X,Y,Z);
     
            X = b[bsmax(1,nb,Z,3)];
            //deb3(X,Y,Z);
            ans = min(ans, ret());
        }
     
        foo(i,1,nb){
            X = b[i];
            Y = g[bsmin(1,ng,X,2)];
            Z = r[bsmin(1,nr,Y,1)];
            //deb4(X,Y,Z,ret());
            ans = min(ans, ret());
            
            Z = r[bsmax(1,nr,Y,1)];
            //deb4(X,Y,Z,ret());
            ans = min(ans, ret());
     
            Y = g[bsmax(1,ng,X,2)];
            Z = r[bsmin(1,nr,Y,1)];
            ans = min(ans, ret());
            //deb4(X,Y,Z,ret());
     
            Z = r[bsmax(1,nr,Y,1)];
            //deb4(X,Y,Z,ret());
            ans = min(ans, ret());
        }
     
        foo(i,1,nb){
            X = b[i];
            Y = r[bsmin(1,nr,X,1)];
            Z = g[bsmin(1,ng,Y,2)];
            //deb4(X,Y,Z,ret());
            ans = min(ans, ret());
            
            Z = g[bsmax(1,ng,Y,2)];
            //deb4(X,Y,Z,ret());
            ans = min(ans, ret());
     
            Y = r[bsmax(1,nr,X,1)];
            Z = g[bsmin(1,ng,Y,2)];
            ans = min(ans, ret());
            //deb4(X,Y,Z,ret());
     
            Z = g[bsmax(1,ng,Y,2)];
            //deb4(X,Y,Z,ret());
            ans = min(ans, ret());
        }
     
        cout<<ans;newl;
    }
     
    int main(){
        SPEED;
     
        cin>>test_cases;
        foo(i,1,test_cases){
            MAIN(i);
        }
    }