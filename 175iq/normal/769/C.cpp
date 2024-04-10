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

int n, m, k;

vviwv(maze, 1010, 1010, -1);
vviwv(dstart, 1010, 1010, -1);

const int fx[4][2] = {{1,0}, {0,-1}, {0,1}, {-1,0}};
char str[4] = {'D','L','R','U'};

inline bool valid(int x, int y)
{
    if(x<1 || x>n || y<1 || y>m || maze[x][y]==0 || maze[x][y]==-1)
        return 0;
    return 1;
}

void bfs(int xx, int yy)
{
    debug(xx, yy);
    queue<pii> q;
    pii start = {xx, yy};

    q.push(start);    
    dstart[xx][yy] = 0;
    
    int cx, cy, nx, ny;
    while(!q.empty())
    {
        pii u = q.front();
        q.pop();
        
        cx = u.fi; 
        cy = u.se; 
        // debug(cx, cy, "cvbwcbvwh");
        FE(i,0,3)
        {
            nx = cx+fx[i][0];
            ny = cy+fx[i][1];
            if(valid(nx, ny) && dstart[nx][ny] == -1)
            {
                dstart[nx][ny] = dstart[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    return;
}

int main()
{
    fastIO;
    cin>>n>>m>>k;
    if(k&1)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }

    int sx, sy;
    FE(i,1,n)
    {
        cins(s);
        FE(j,1,m)
        {
            if(s[j] == 'X')
            {
                sx = i;
                sy = j;
                maze[i][j] = 1;
            }
            maze[i][j] = ((s[j] == '.' || s[j] == 'X')? 1 : 0);
        }
    }

    int cnt = 0;
    FE(i,0,3)
    {
        if(maze[sx+fx[i][0]][sy+fx[i][1]]==1)
            cnt++;
    }
    if(!cnt)
    {
        cout<<"IMPOSSIBLE";
        return 0;        
    }

    bfs(sx, sy);

    string ans;
    int cx = sx, cy = sy, nx, ny, mark = 0;
    FE(cover, 1, k)
    {
        FE(j,0,3)
        {
            nx = cx + fx[j][0];
            ny = cy + fx[j][1];
            mark = 0;
            
            if(valid(nx, ny))
            {
                if(dstart[nx][ny] <= (k-cover))
                {
                    ans.pb(str[j]);
                    mark = 1;
                    cx = nx;
                    cy = ny;
                    break;                    
                }
            }
        }
    }
    cout<<ans;
    return 0;
}