#include <bits/stdc++.h>
using namespace std;
 
//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 
 
//Constants
#define EPS 1e-6
#define INF 2e9
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,1,a.size()-1)
 
//For loops
#define FE(i,a,b)  for(int i=a; i<=b; i++)
#define FRE(i,b,a) for(int i=b; i>=a; i--)
#define FA(x,cont) for(auto& x : cont)
 
//For debug 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
//Definitions 
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s; s = "#"+s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

void solve()
{
    ld n,l;
    cin>>n>>l;

    vector<ld> rleft(n+2);
    rleft[0] = 0;
    vector<ld> rright(n+2);
    rright[n] = 0;
    vector<ld> a(n+2);
    a[0] = 0;
    a[n+1] = l;
    FE(i,1,n)
        cin>>a[i];

    ld speed = 1;
    FE(i,1,n)
    {
        rleft[i] = rleft[i-1] + (a[i] - a[i-1])/speed;
        speed++;
    }
    rleft[0] = 0;
    debug(rleft);


    speed = 1;
    FRE(i,n,1)
    {
        rright[i] = rright[i+1] + (a[i+1] - a[i])/speed;  
        speed++;
    }   
    rright[n+1] = 0;
    debug(rright);

    function<int(ld)> f= [&](ld t)
    {
        ld dleft, dright;
        int I1,I2;
        FRE(i,n,0)
        {
            if(t >= rleft[i])
            {
                I1 = i;
                break;
            }
        }

        FE(i,1,n+1)
        {
            if(t >= rright[i])
            {
                I2 = i;
                break;
            }
        }
        // debug(t, I1, I2);
        ld speedl = 1+I1;
        dleft     = a[I1] + (t-rleft[I1])*speedl;
        // debug(speedl, dleft);
        ld speedr = 1+(n-I2+1);
        dright    = l-a[I2] + (t-rright[I2])*speedr;         
        // debug(speedr, dright);     
        if(dleft + dright >=l)
            return 1;
        else
            return 0;
    };

    cout<<fixed;
    cout<<setprecision(12);
    ld left = 0, right = (l/2), ans = -1;
    debug(left, right);
    FE(i,1,100)
    {
        ld mid = (left+right)/2.0;
        debug(mid);
        if(f(mid)){
            right = mid;
            ans = mid;
        }
        else
        {
            left = mid;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    fastIO; 
    cini(t);
    while(t--)
        solve();
    return 0;
}