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
#define INF 2e9
 
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

#define BIT 30

vviwv(trie, 200005*BIT, 2, 0); 
vi prefix_cnt(200005*BIT, 0); // Stores how many strings pass through a particular node.
int node_cnt = 0; // 1 node already for root

void solve()
{    
    int root = 0;

    function<int()> new_node = [&]()
    {
        node_cnt++;
        return node_cnt;
    };

    function<void(int)> insert = [&](int num)
    {
        int cur = root, h = 0, next_bit;
        FRE(i, BIT-1, 0)
        {
            next_bit = (num & (1<<i)) ? 1 : 0;

            if(trie[cur][next_bit] == 0)
                trie[cur][next_bit] = new_node();
            
            cur = trie[cur][next_bit];

            prefix_cnt[cur]++;
        }
    };

    function<int(int)> search = [&](int num)
    {
        int ans = 0;
        int cur = root, next_bit, req_bit;
        FRE(i, BIT-1, 0)
        {
            next_bit = (num & (1<<i)) ? 1 : 0;
            req_bit  = 1-next_bit; 

            if(trie[cur][req_bit] == 0 || prefix_cnt[trie[cur][req_bit]] <= 0)
            {
                cur = trie[cur][1-req_bit];
            }
            else
            {
                ans += (1<<i);
                cur = trie[cur][req_bit];                
            }
        }
        return ans;
    };    

    function<void(int)> del = [&](int num)
    {
        //Assumes that the number num is present in the trie.
        int cur = root, next_bit;

        FRE(i, BIT-1, 0)
        {
            next_bit = (num & (1<<i)) ? 1 : 0;
            
            cur = trie[cur][next_bit];
            prefix_cnt[cur]--;
        }

        return;
    };    

    insert(0);

    cini(q);
    while(q--)
    {
        char ch;
        int x;
        cin>>ch>>x;

        if(ch == '+')
            insert(x);
        else if(ch == '-')
            del(x);
        else if(ch == '?')
            cout<<search(x)<<"\n";
    }

    return;
}

signed main()
{
    fastIO;
    int t = 1;
    // cin>>t; 

    FE(i, 1, t)
        solve();

    return 0;
}