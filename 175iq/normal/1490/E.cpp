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
#define INF 0x3f3f3f3f
 
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
#define cins(s) string s; cin>>s; s = "#" + s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

#define int ll

void solve()
{
    cini(n);
    vector<pii> vec(n+1);

    FE(i,1,n)
    {
        cini(x);
        vec[i] = {x, i};
    }

    sort(1+all(vec));

    debug(vec);
    vector<ll> pref(n+1,0);
    FE(i,1,n)
        pref[i] = pref[i-1] + vec[i].fi;

    function<int(int)> f = [&](int pos)
    {
        int sm = pref[pos], win = 1;
        // debug(sm);
        FE(i,pos,n-1)
        {
            if(sm < vec[i+1].fi)
            {
                win = 0;
                break;
            }
            else
                sm += vec[i+1].fi;
            // if(sm >= vec[i].fi)
            // {
            //     if(sm + vec[i].fi < vec[i+1].fi)
            //     {
            //         win = 0;
            //         break;
            //     }
            // }
            // else
            // {
            //     win = 0;
            //     break;
            // }
        }
        return (win == 1 ? 1 : 0);
    };

    // debug(f(1));
    int left = 1, right = n, ans;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(f(mid))
        {
            right = mid-1;
            ans = mid;
        }
        else
            left = mid+1;
    }
    debug(ans);
    cout<<n-ans+1<<"\n";
    std::vector<int> vec2;
    FE(i,ans,n)
        vec2.pb(vec[i].se);

    sort(all(vec2));

    FA(p, vec2)
        cout<<p<<" ";
    cout<<"\n";

    return;
}

signed main()
{
    fastIO;
    int t = 1;
    cin>>t;   

    while(t--)
    {
        solve();
    }
    return 0;
}