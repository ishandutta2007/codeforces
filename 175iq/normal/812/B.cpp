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

vviwv(dp, 20, 110, -100);
vi rightmost(20,-1);
vi lftmost(20,-1);
int m, first = -1;
int timer = 0;

int calc(int dir, int level)
{
    //debug(dir, level, ++timer);
    int& ans = dp[dir][level];
    if(ans!=-100)
        return ans;
    
    if(level==first)
    {
        if(dir==1){
            return ans = rightmost[first] ; //(rightmost[1]!=-1 ? rightmost[1] : -1) ;
        }
        else
            return ans = m-lftmost[first]+1 ; //(lftmost[1]!=-1 ? m-lftmost[1]+1:-1) ;
    }
    
    if(rightmost[level]==-1)
        return 1+calc(dir, level-1);

    if(dir == 1)
        return ans = 1 + min(2*rightmost[level] + calc(1, level-1) , 1+m+calc(0, level-1));
    else
    {
        //debug("vevrd");
        return ans = 1 + min(2*(m-lftmost[level]+1) + calc(0, level-1) , 1+m+calc(1, level-1)); 
    }
}

int main()
{
    fastIO;
    int n;
    cin>>n>>m;
    vviwv(mat, 20, 110, -1);
    FE(i,1,n)
    {
        cins(s);
        FE(j,1,m)
            mat[i][j] = s[j+1]-'0';
    }

    FE(i,1,n)
    {   
        FE(j,1,m)
        {
            if(mat[i][j] == 1)
            {
                lftmost[i] = j;   
                if(first==-1)
                    first = i;
                break; 
            }
        }
        FE(j,1,m)
        {
            if(mat[i][j] == 1)
                rightmost[i] = j;   
        }
    }
    
    if(first==-1){
        cout<<0;
        return 0;
    }
    //debug(first);
    //debug(lftmost);
    //debug(rightmost);
    int x = calc(0, 2);
    int y1 = calc(1, 1);
    int y2 = calc(0, 1);
    //int y = calc(1,2); 
    //debug(y1, y2);
    //debug(x);
    //debug();
    //debug();

    if(n==first)
    {
        cout<<rightmost[n];
        return 0;
    }
    if(n>=2){
        // cout<<1+min(m+1+calc(0, n-1), 2*rightmost[n]+calc(1,n-1));
        cout<<calc(1, n);
    }
    else
        cout<<(rightmost[n]!=-1 ? rightmost[n] : 0);

    return 0;
}