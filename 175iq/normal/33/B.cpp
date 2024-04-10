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
#define INF 1e8
 
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
        
int N = 30;        
vvi gr(N);
vviwv(d, 30, 30, INF);

int main()
{
    fastIO;
    cins(s);
    cins(t);

    int n1 = s.sz-1;
    int n2 = t.sz-1;
    if(n1!= n2)
    {
        cout<<-1;
        return 0;
    }

    cini(n);
    char from, to;
    int w;
    FE(i,1,n)
    {
        cin>>from>>to>>w;
        // debug(from-'a'+1, to-'a'+1);
        d[from-'a'+1][to-'a'+1] = min(w, d[from-'a'+1][to-'a'+1]);
    }

    FE(i,1,26)
        d[i][i] = 0;

    FE(k,1,26)
        FE(i,1,26)
            FE(j,1,26)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);            

    // FE(i,1,26)
    // {
    //     FE(j,1,26){
    //         cout<<d[i][j]<<" ";
    //     }
    //     cout<<"\n";        
    // }

    int si, ti;
    vi ans(n1+1,-1);
    int wtemp;
    ll finans = 0;
    FE(i, 1, n1)
    {
        wtemp = 2e9;
        si = s[i]-'a'+1;
        ti = t[i]-'a'+1;
        FE(to, 1, 26)
        {
            if(i==2)    
            {
                debug(to,d[si][to] + d[ti][to]);
            }

            if( wtemp > d[si][to] + d[ti][to])
            {
                wtemp  = d[si][to] + d[ti][to];
                ans[i] = to; 
            }
        }
        if(wtemp >= 1e8)
        {
            debug(i, wtemp, ans[i]);
            cout<<-1;
            return 0;
        }
        else
            finans += wtemp;
    }

    cout<<finans<<"\n";
    FE(i,1,n1)
    {
        if(ans[i]==-1)
            cout<<s[i];
        else
            cout<<(char)('a'+ans[i]-1);
    }
    return 0;
}