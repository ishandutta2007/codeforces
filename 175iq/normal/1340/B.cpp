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

vector<string> mp(12);

void init()
{
    mp[0] = "1110111";
    mp[1] = "0010010";
    mp[2] = "1011101";
    mp[3] = "1011011";
    mp[4] = "0111010";
    mp[5] = "1101011";
    mp[6] = "1101111";
    mp[7] = "1010010";
    mp[8] = "1111111";
    mp[9] = "1111011";
    return;    
}

int convert(string& s, int to)
{
    // debug(s, to);
    string sto = mp[to];
    // debug(sto);
    int c = 0;
    FE(i,0,6)
    {
        if(s[i] == '1' && sto[i] == '0')
            return -1;
        else if(s[i] == '0' && sto[i] == '1')
            c++;
    }   
    return c;
}

int main()
{               
    fastIO;
    init();
    // string ss = "0000000"; 
    // cout<<convert(ss ,1);

    cini2(n,K);
    vector<string> arr(n+1);
    FE(i,1,n)
        cin>>arr[i];

    vviwv(dp, 2010, 2010, -1);
    function<int(int, int)> calc = [&](int pos, int k)
    {
        // debug(pos, k);
        if(k<0)
            return 0;
        if(pos == n+1)
        {
            if(k==0)
                return 1;
            else
                return 0;
        }

        string curstr = arr[pos];
        int curcost;

        int& ans = dp[pos][k];
        if(ans!=-1)
            return ans;
        
        if(pos == n)
        {
            FE(to, 0, 9)
            {
                curcost = convert(curstr, to);
                // debug(to, curcost);
                if(curcost!=-1 && curcost == k)
                    return ans = 1;
            }
            return ans = 0;
        }


        int mark = 0;
        FE(to, 0, 9)
        {
            curcost = convert(curstr, to);
            if(curcost!=-1)
            {
                if(calc(pos+1, k-curcost)){
                    // debug(pos,k,"enbvbf");
                    dp[pos][k]  = 1;
                    mark = 1;
                }
            }
        }
        debug(pos, k, ans);
        return dp[pos][k] = mark;
    };

    if(!calc(1,K))
    {
        cout<<-1;
        return 0;
    }
    else
    {
        // FE(i,1,2)
        // {
        //     FE(k,1,5)
        //         cout<<dp[i][k]<<" ";
        //     cout<<"\n";
        // }
        string ans ;
        int curcost; 
        int kk = K;
        FE(i,1,n)
        {
            FRE(to, 9, 0)
            {
                curcost = convert(arr[i], to);
                debug(i, to , curcost);
                if(curcost!=-1)
                {
                    if(calc(i+1, kk - curcost))
                    {
                        ans += (char)(to + '0');
                        kk -= curcost;
                        break;
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}