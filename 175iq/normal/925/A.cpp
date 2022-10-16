#include "bits/stdc++.h"
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
#define MOD 998244353 //1000000007  

//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,1,a.size()-1)

//For loops
#define F(i,a,b)   for(int i=a; i<b; i++)
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
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
#define ll long long 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
 
int main()
{  
    fastIO;
    cini2(n,m);
    cini3(cs,ce,v);
    cinv(strs,cs);
    cinv(elev,ce);

    cini(q);
    int strsright, strsleft, elevright, elevleft, idx, finans;
    while(q--)
    {
        cini4(x1,y1,x2,y2);
        if(x1==x2){
            cout<<abs(y1-y2)<<endl;
            continue;
        }

        auto it = upper_bound(1+all(strs),y1);
        if(it==strs.end())
            strsright = INF;
        else
        {
            idx = it - strs.begin();
            strsright = abs(strs[idx]-y1);
            strsright += abs(x2-x1);
            strsright += abs(y2-strs[idx]);
        }

        if(it==strs.begin()+1)
            strsleft = INF;
        else
        {
            it--;
            idx = it - strs.begin();
            strsleft = abs(y1-strs[idx]);
            strsleft += abs(x2-x1);
            strsleft += abs(y2-strs[idx]);
        }

        it = upper_bound(1+all(elev),y1);
        if(it==elev.end()){
            elevright = INF;
        }
        else
        {
            idx = it - elev.begin();
            debug(idx);
            elevright = abs(elev[idx]-y1);
            debug(elevright);
            elevright += ((abs(x2-x1)+v-1)/v);
            debug(elevright);
            elevright += abs(y2-elev[idx]);
            debug(elevright);
        }        

        if(it==elev.begin()+1)
            elevleft = INF;
        else
        {
            it--;
            idx = it - elev.begin();
            elevleft = abs(elev[idx]-y1);
            elevleft += ((abs(x2-x1)+v-1)/v) ;
            elevleft += abs(y2-elev[idx]);
        }
        debug(elevleft,elevright,strsleft,strsright);
        finans = min({elevleft,elevright,strsleft,strsright});
        cout<<finans<<endl;
    }

    return 0;
}