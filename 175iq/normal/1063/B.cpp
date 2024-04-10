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
#define INF INT_MAX
 
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
    
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int N = 2e3+10;
vviwv(board, N, N, -1);
vviwv(d, N, N, INF);

int n,m; 
struct node
{
    int x, y, cl, cr;
    node(){}
    node(int xx, int yy, int cll, int crr)
    {
        x = xx, y = yy, cl = cll,  cr = crr;
    }
};

inline bool isvalid(int x, int y)
{
    debug(x,y);
    return ( x>=1 && x<=n && y>=1 && y<=m && board[x][y]==1);
} 

int main()
{
    fastIO;
    cin>>n>>m;
    cini2(xx,yy);
    cini2(l,r);

    FE(i,1,n)
    {
        cins(s);
        debug(s);
        FE(j,1,m)
            board[i][j] = (s[j] == '.' ? 1 : 0) ; 
    }   
    debug(board[1]);    

    int ans = 0;
    deque<node> q;
    d[xx][yy] = 0;
    node strt = node(xx, yy, l, r);
    q.push_back(strt);

    node cur;
    int xcur, ycur, clcur, crcur;
    while(!q.empty())
    {   
        cur = q.front();
        q.pop_front();
        xcur  = cur.x;
        ycur  = cur.y;
        clcur = cur.cl;
        crcur = cur.cr;
        debug(xcur, ycur);

        if(isvalid(xcur, ycur-1) && clcur)
        {
            if(d[xcur][ycur-1] > d[xcur][ycur] + 1)
            {
                d[xcur][ycur-1] = d[xcur][ycur] + 1;
                node x = node(xcur, ycur-1, clcur-1, crcur);
                q.push_back(x);
            }            
        }

        if(isvalid(xcur, ycur+1) && crcur)
        {
            if(d[xcur][ycur+1] > d[xcur][ycur] + 1)
            {
                d[xcur][ycur+1] = d[xcur][ycur] + 1;
                node x = node(xcur, ycur+1, clcur, crcur-1);
                q.push_back(x);
            }
        }

        if(isvalid(xcur-1, ycur))
        {
            if(d[xcur-1][ycur] > d[xcur][ycur])
            {
                d[xcur-1][ycur] = d[xcur][ycur];
                node x = node(xcur-1, ycur, clcur, crcur);
                q.push_front(x);
            }
        }

        if(isvalid(xcur+1, ycur))
        {
            if(d[xcur+1][ycur] > d[xcur][ycur])
            {
                d[xcur+1][ycur] = d[xcur][ycur];
                node x = node(xcur+1, ycur, clcur, crcur);
                q.push_front(x);
            }
        }
    }

    FE(i,1,n)
        FE(j,1,m)
            ans += (d[i][j] == INF ? 0 : 1);

    cout<<ans;    
    return 0;
}