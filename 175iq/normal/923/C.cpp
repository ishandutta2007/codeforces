#include <bits/stdc++.h>
using namespace std;
  
//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 
   
//For loops
#define FE(i,a,b)  for(int i=a; i<=b; i++)
#define FRE(i,b,a) for(int i=b; i>=a; i--)
#define FA(x,cont) for(auto& x : cont)
 
//For debug 
// ----------------------------- (Debug) ------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; }; sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0); sim > char dud(...);
struct debug {
#ifdef LOCAL
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i));}
sim, class b dor(pair < b, c > d) {ris << "(" << d.first << ", " << d.second << ")";}
sim dor(rge<c> d) {*this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]";}
#else
sim dor(const c&) { ris; }
#endif
};
vector<char*> tokenizer(const char* args) {
    char *token = new char[111]; strcpy(token, args); token = strtok(token, ", ");
    vector<char*> v({token});
    while((token = strtok(NULL,", "))) v.push_back(token);
    return reverse(v.begin(), v.end()), v;
}
void debugg(vector<char*>) { cerr << ""; }
template <typename Head, typename... Tail>
void debugg(vector<char*> args, Head H, Tail... T) {
    debug() << " [" << args.back() << ": " << H << "] ";
    args.pop_back(); debugg(args, T...);
}
#define harg(...) #__VA_ARGS__
#ifdef LOCAL
#define debug(...) { debugg(tokenizer(harg(LINE, __VA_ARGS__)),__LINE__, __VA_ARGS__); cerr << endl;}
#else
#define debug(...) { }
#endif
/// -----------------------------------------------------------------------
 
///------------------For Online test------------------ ///
#define dbg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__<<" ";((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl; }(__VA_ARGS__);
///------------------For Online test------------------ ///
 
//Definitions 
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define pii pair<int,int>   
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cins(s) string s; cin>>s; s = "#" + s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
 
// #define int ll
#define INFI (int)2e9
#define INFL (ll)1e18
 
class Trie
{    
    public:

    int BIT;
    vector<vector<int> > trie;
    vector<vector<int>> prefix_cnt; // Stores how many strings pass through a particular node.
    int node_cnt = 0; // 1 node already for root
    int root = 0;

    Trie(int nnodes, int nbits)
    {
        BIT = nbits;

        // prefix_cnt[cur][next_bit] stores how many from cure node in the direction of next_bit
        prefix_cnt.assign((nnodes+10)*nbits,  vector<int>(2) );  

        trie.assign((nnodes+10)*nbits, vector<int>(2));
    }

    int new_node()
    {
        node_cnt++;
        // debug(node_cnt);
        return node_cnt;
    }

    void insert(int num)
    {
        int cur = root, h = 0;
        FRE(i, BIT-1, 0)
        {
            int next_bit = (num & (1<<i)) ? 1 : 0;
            prefix_cnt[cur][next_bit]++;
            
            if(trie[cur][next_bit] == 0)
                trie[cur][next_bit] = new_node();
                    
            cur = trie[cur][next_bit];
        }
        return;
    }

    int search(int num)
    {
        int cur = root;
        FRE(i, BIT-1, 0)
        {
            int next_bit = (num & (1<<i)) ? 1 : 0;

            if(trie[cur][next_bit] == 0 || prefix_cnt[cur][next_bit] == 0)
                return 0;
            
            cur = trie[cur][next_bit];
        }
        return 1;
    }    

    void del(int num)
    {
        //Assumes that the number num is present in the trie.
        int cur = root;

        FRE(i, BIT-1, 0)
        {
            int next_bit = (num & (1<<i)) ? 1 : 0;
            prefix_cnt[cur][next_bit]--;
                
            cur = trie[cur][next_bit];
        }
        return;
    }   

    int find_min_xor(int val)
    {
        int cur = root;
        int num = 0;
        FRE(i,BIT-1,0)
        {
            int next_bit = (val & (1<<i)) ? 1 : 0;

            if(!trie[cur][next_bit] or !prefix_cnt[cur][next_bit])
            {
                num += (1<<i);
                cur = trie[cur][1-next_bit];
            }
            else if(prefix_cnt[cur][next_bit])
            {   
                cur = trie[cur][next_bit];
            }
        }
        return num;
    } 
};

void solve()
{
    cini(n);
    cinv(a, n);
    cinv(p, n);

    Trie tr = Trie(n, 30);
    // debug(tr.cnt_end_onnode);
    // debug(tr.prefix_cnt);
    FE(i,1,n)
        tr.insert(p[i]);

    // debug(tr.search(17));
    // tr.del(17);
    // debug(tr.search(17));

    // debug(tr.search(2));
    // tr.del(2);
    // debug(tr.search(2));

    // debug(tr.search(7));
    // tr.del(7);
    // debug(tr.search(7));

    FE(i,1,n)
    {
        int num = tr.find_min_xor(a[i]);
        cout<<(num)<<" ";
        debug(num^a[i]);
        debug(tr.search(num^a[i]));
        tr.del(num^a[i]);
        debug(tr.search(num^a[i]));
    }

    return; 
}
 
signed main()
{
    fastIO; 
    
    int T = 1;
    // cin>>T;
    
    FE(i,1,T)
        solve();
    
    return 0;
}