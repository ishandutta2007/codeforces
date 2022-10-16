#include "bits/stdc++.h"
using namespace std;

//Utility functions
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define foreach(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) //traverse an STL data structure
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(c) (c).begin(),(c).end() //handy for function like "sort()"
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } //sort array of objects(structs)[Lambda function]
//sort(begin(v), end(v), [] (int a, int b) { return a > b; });
 
//Constants
#define EPS 1e-8
#define INF INT_MAX
#define MOD 998244353 //1000000007
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,0,a.size()-1)
 
//For loops
#define F(i,a,b)    for(int i=a; i<b; i++)
#define FE(i,a,b)   for(int i=a; i<=b; i++)
#define FRE(i,b,a)  for(int i=b; i>=a; i--)
#define FA(n,container)   for(auto n : container)

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
#define vb vector<bool> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
#define ll long long 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Directions
const int fx[4][2]  = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s;
#define cinv(a, n) vi a(n); F(i,0,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n); F(i,0,n) { cin>>a[i]; }
#define cinvs(s, n) vs s(n); F(i,0,n) { cin>>s[i]; }
#define cinvd(a, n) vd a(n); F(i,0,n) { cin>>a[i]; }

int main()
{
    fastIO;
    
    cini(n);
    vector<pii> vec(n);
    srand(time(0)); 
    int alpha = (rand())%n;
    int mini;
    int a, b;
    F(i,0,n)
    {
        cin>>a>>b;
        vec[i] = mp(a,b);
    }

    mini = vec[alpha].fi;
    vi vecd;
    vecd.pb(mini);
    int root = sqrt(mini); 
    FE(i,2,root)
    {
        if(mini%i==0)
        {
            vecd.pb(i);
            if(i!=mini/i)
                vecd.pb(mini/i);
        }
    }

    debug(vecd);

    int t1,t2,mark=0;
    FA(x,vecd)
    {
        mark=0;
        F(i,0,n)
        {   
            t1 = (vec[i].fi)%x , t2 = (vec[i].se)%x ;
            if(t1!=0 && t2!=0)
            {
                mark=1;
                break;
            }
        }
        if(mark)
            continue;
        else
        {
            cout<<x;
            mark=2;
            break;
        }
    }

    vi vecd2;
    if(mark!=2)
    {
        mini = vec[alpha].se;
        
        vecd2.pb(mini);
        int root = sqrt(mini); 
        FE(i,2,root)
        {
            if(mini%i==0)
            {
                vecd2.pb(i);
                if(i!=mini/i)
                    vecd2.pb(mini/i);
            }
        }
        FA(x,vecd2)
        {
            mark=0;
            F(i,0,n)
            {   
                t1 = (vec[i].fi)%x , t2 = (vec[i].se)%x ;
                if(t1!=0 && t2!=0)
                {
                    mark=1;
                    break;
                }
            }
            if(mark)
                continue;
            else
            {
                cout<<x;
                mark=2;
                break;
            }
        }
    }

    if(mark!=2)
    {
        cout <<-1<<endl;
    }

    //if(n==150000 && vec[0].fi == 2 && vec[0].se== 3)
    //{
    //    cout<<alpha<<" "<<vec[alpha].fi<<" "<<vec[alpha].se<<endl;
    //    coutV(vecd);
    //    coutV(vecd2);
    //}

    return 0;
}