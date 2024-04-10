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
  
struct veniceSet
{
    multiset<ll> s;
    ll water_level = 0;

    //Here greater the value of water_level, greater the value we subtract 
    //from all val in the multiset.

    void addEle(ll element)
    {
        s.insert(element + water_level);
        return; 
    }

    void removeMin()
    {
        if(s.sz)
            s.erase(s.begin());
        return;
    }

    void removeEle(ll ele)
    {
        if(s.count(ele+water_level))
            s.erase(s.find(ele+water_level));  
        return; 
    }

    // We subtract the water level to get the actual size of the building
    ll getMin()         
    {
        if(s.sz)
            return (*s.begin() - water_level);
        return INF;
    }

    // Give positive val of change if you want to subtract a val from all ele 
    void updateAll(ll change)  
    {
        water_level += change;
        return;
    }

    ll siz()
    {
        return s.sz;
    }
};

int main()
{
    fastIO;
    cini(n);
    cinv(v,n);
    cinv(t,n);

    veniceSet st;

    ll ans = 0;
    FE(i,1,n)
    {
        st.addEle(v[i]);
        st.updateAll(t[i]);
        ans = t[i]*st.siz();
        ll val;
        while(st.getMin()<0)
        {
            val = st.getMin();
            ans -= abs(val);
            st.removeMin();
        }
        cout<<ans<<" ";
    }
    return 0;
}             

        // cins(s);
        // cins(t);

        // int n1 = s.sz;
        // int n2 = t.sz;
        // vvi charmap(26);

        // FE(i,1,n1-1)
        //     charmap[s[i]-'a'].pb(i);

        // //debug(charmap);
        // int steps = 0;
        // int j = 1, ch, sidx = 1, start = 1;
        // while(j<=(n2-1))
        // {
        //     debug(j);
        //     while(1)
        //     {
        //         //sidx = 1;
        //         if(j>(n2-1))
        //             break;
        //         ch = t[j]-'a';
        //         auto it = lower_bound(all(charmap[ch]), sidx);
        //         debug(ch,sidx);
        //         if(it == charmap[ch].end())
        //         {
        //             if(start == 1)
        //             {
        //                 cout<<"-1";
        //                 return 0;
        //             }
        //             else
        //             {
        //                 break;
        //             }
        //         }
        //         else
        //         { 
        //             j++;
        //             start = 0;                
        //             int idxfnd = *it;
        //             debug(idxfnd);
        //             if(idxfnd+1 > (n2-1)){
        //                 start = 1;
        //                 sidx = 1;
        //                 if(j>(n2-1))
        //                     break;
        //                 steps++;
        //                 continue;
        //             }
        //             sidx = idxfnd+1;
        //         }                
        //     }
        //     steps++;
        //     if(j==(n2-1))
        //         break;
        // }
        // cout<<steps<<endl;