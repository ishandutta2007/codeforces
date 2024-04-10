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

const int fx[4][2]  = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

void solve()
{
    cini2(n,m);
    int g = 0;
    vector<vector<char> > maze1(55, std::vector<char> (55,'.'));
    vector<vector<char> > maze(55, std::vector<char> (55,'.'));
    FE(i,1,n)
    {
        cins(s);
        FE(j,1,m)
        {
            maze1[i][j] = s[j];
            if(maze1[i][j] == 'G')
                g++;
        }
    }

    maze = maze1;

    FE(i,1,n)
        FE(j,1,m)
        {
            if(maze1[i][j] == 'B')
            {
                if(maze[i+1][j] != 'G')
                    maze[i+1][j] = '#';
                else
                {
                    cout<<"No"<<"\n";
                    return ;
                }

                if(maze1[i-1][j] != 'G')
                    maze[i-1][j] = '#';
                else
                {
                    cout<<"No"<<"\n";
                    return ;
                }

                if(maze1[i][j+1] != 'G')
                    maze[i][j+1] = '#';
                else
                {
                    cout<<"No"<<"\n";
                    return ;
                }

                if(maze1[i][j-1] != 'G')
                    maze[i][j-1] = '#';
                else
                {
                    cout<<"No"<<"\n";
                    return ;
                }
            }
        }

    if(maze[n][m] == '#' && g>0)
    {
        cout<<"No"<<"\n";
        return ;        
    }

    debug(maze[1]);

    vviwv(visited, 55, 55, 0);
    int cnt = 0;

    function<void()> bfs = [&]()
    {
        queue<pii> q;
        
        pii start = {n,m};
        q.push(start);
        visited[n][m] = 1;

        int x, y, nx, ny;
        while(!q.empty())
        {
            pii u = q.front();
            q.pop();

            x = u.fi;
            y = u.se;

            FE(i,0,3)
            {
                nx = x + fx[i][0];
                ny = y + fx[i][1];
                debug(nx, ny);
                if(nx<1 || nx>n || ny<1 || ny>m || maze[nx][ny]=='#')
                    continue;

                if(!visited[nx][ny])
                {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                    if(maze[nx][ny] == 'G')
                        cnt++;
                }             
            }
        }
        return;
    };

    bfs();

    if(cnt==g)
        cout<<"Yes"<<"\n";
    else
        cout<<"No"<<"\n";
}

int main()
{
    fastIO;
    cini(t);
    while(t--)
        solve();
    return 0;
}