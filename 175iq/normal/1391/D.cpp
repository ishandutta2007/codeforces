#include <bits/stdc++.h>
using namespace std;
 
//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 
 
//Constants
#define EPS 1e-8
#define INF 0x3f3f3f3f
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,1,a.size()-1)
 
//For loops
#define FE(i,a,b)  for(int i=a; i<=b; i++)
#define FRE(i,b,a) for(int i=b; i>=a; i--)
#define FA(x,cont) for(auto& x : cont)
 
//For debug `
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
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
#define ll long long 
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

vviwv(grid, 5, 1e6+10, -1);
vviwv(can2, 10, 10, 0);
vviwv(can3, 10, 10, 0);
vviwv(dp2, 1e6+10, 10, INF);
vviwv(dp3, 1e6+10, 10, INF);

void calc2(int m)
{
    int actualmask;

    FE(msk,0,3)
        dp2[0][msk] = 0;

    FE(i,1,m)
    {   
        actualmask = 2*grid[1][i] + grid[2][i];
        FE(currmask, 0, 3)
        {
            FE(prevmask, 0, 3)
            {
                if(!can2[prevmask][currmask])
                    continue;
                dp2[i][currmask] = min( dp2[i][currmask], __builtin_popcount(actualmask^currmask) +  dp2[i-1][prevmask]);                    
            } 
        }            
    }
    int ans = INF;
    FE(currmask, 0, 3)
        ans = min(ans, dp2[m][currmask]);
    cout<<ans;
    return;
}

void calc3(int m)
{
    int actualmask;

    FE(msk,0,7)
        dp3[0][msk] = 0;

    FE(i,1,m)
    {   
        actualmask = 4*grid[1][i] + 2*grid[2][i] + grid[3][i];
        FE(currmask, 0, 7)
        {
            FE(prevmask, 0, 7)
            {
                if(!can3[prevmask][currmask])
                    continue;
                dp3[i][currmask] = min( dp3[i][currmask], __builtin_popcount(actualmask^currmask) + dp3[i-1][prevmask]);                    
            } 
        }            
    }
    int ans = INF;
    FE(currmask, 0, 7)
        ans = min(ans, dp3[m][currmask]);
    cout<<ans;
    return;
}

int main()
{
    fastIO;
    cini2(n,m);

    if(n==1){
        cout<<0;
        return 0;
    }
    if(n>=4)
    {
        cout<<-1;    
        return 0;
    }

    FE(i,1,n)
    {
        cins(s);
        debug(s);
        FE(j,1,m)
            grid[i][j] = s[j]-'0';
    }

    if(n == 2)
    {
        can2[1][0] = 1;
        can2[2][0] = 1;

        can2[0][1] = 1; 
        can2[3][1] = 1; 

        can2[0][2] = 1; 
        can2[3][2] = 1; 

        can2[1][3] = 1; 
        can2[2][3] = 1; 
        calc2(m);
        return 0;
    }

    if(n==3)
    {
        can3[2][0] = 1;
        can3[5][0] = 1;        

        can3[3][1] = 1;        
        can3[4][1] = 1;        

        can3[0][2] = 1;        
        can3[7][2] = 1;        

        can3[1][3] = 1;        
        can3[6][3] = 1;        

        can3[1][4] = 1;        
        can3[6][4] = 1;        

        can3[0][5] = 1;        
        can3[7][5] = 1;        

        can3[3][6] = 1;        
        can3[4][6] = 1;        

        can3[2][7] = 1;        
        can3[5][7] = 1;        
        calc3(m);
    }

    return 0;
}