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
#define cins(s) string s; cin>>s; s = "#"+s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

const int N = (int) 1e5 + 123;
const int C = 101;
const int P = 11;
 
int n, q, c;
int cnt[P][C][C];
 
int main() {
    scanf("%d%d%d", &n, &q, &c);
    for (int i = 0; i < n; i++) {
        int x, y, s;
        scanf("%d%d%d", &x, &y, &s);
        cnt[s][x][y]++;
    }
    
    for (int p = 0; p <= c; p++) {
        for (int i = 1; i < C; i++) {
            for (int j = 1; j < C; j++) {
                cnt[p][i][j] += cnt[p][i - 1][j] + cnt[p][i][j - 1] - cnt[p][i - 1][j - 1];
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        int t, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        int ans = 0;
        for (int p = 0; p <= c; p++) {
            int brightness = (p + t) % (c + 1);
            int amount = cnt[p][x2][y2] - cnt[p][x1 - 1][y2] - cnt[p][x2][y1 - 1] + cnt[p][x1 - 1][y1 - 1];
            ans += brightness * amount;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}




// #include <iostream>
// #define fr(i,n) for(int i=1; i<=n; i++)
// #define mp make_pair
// #define MXN 1010
 
// using namespace std;
 
// int prev_min_ind[MXN], mincost[MXN], used[MXN];
// int pr,tmincost,n,m,k,w;
// pair<int,int > ans[MXN];
// char lvl[MXN][15][15];
 
// int main() {
//     cin>>n>>m>>k>>w;
 
//     fr(i,k) fr(j,n) cin>>lvl[i][j]; 
 
//     fr(i,k) mincost[i]=n*m, prev_min_ind[i]=0;
//     //1 is considered exclusively so i'm assuming prev sent was 1, note that
//     //this val wouldn't affect answer, you could send any level for first time so 
//     //you could pr any val as far as pr<=k and print this chosen val exclusively 
//     pr=1;
//     //i need atmost k-1 iterations as i have already chosen 1 vertex but still i need to choose k-1 nodes
//     //since in each iteration i'll choose at least(exactly) one node so max iterations = k - 1
//     //this is a very good implementation of prim's algo.
//     fr(i,k-1){
//         used[pr] = 1;
//         int cmincost = 10000, fminind = 0;
//         //search over all vertices which one gives min cost for sending after pr vertex if this is not used already
//         fr(x,k) if(!used[x]){
//             int cst=0;
//             //find cost of lvl x sending after level pr(if it will be sent in future after 1)
//             fr(y,n) for(int c=0; c<m; ++c) if(lvl[pr][y][c] != lvl[x][y][c]) cst += w;
//             //if this cost is less than any other cost, update values
//             if(mincost[x]>cst){ mincost[x] = cst; prev_min_ind[x]=pr; }
//             /**
//              * 
//              *  if choosing this x vertex gives me the lowest cost update current min out of all 
//              *  note that we are updating prev_min_ind array bcoz this min value might have come from some
//              *  prev iteration of i when it was min in that iteration but in this iteration it became min
//              *  so if this is the case prev_min_ind already have proper value, for second case it must have been
//              *  modified in upper if block
//              */
//             if(mincost[x]<cmincost){ cmincost=mincost[x]; fminind=x; }
//         }
//         tmincost += cmincost;
//         pr = fminind;
//         ans[i] = mp(pr, prev_min_ind[pr]);
//     }
//     cout<<tmincost+m*n<<endl;
//     printf("1 0\n");
//     fr(i,k-1) printf("%d %d\n",ans[i].first,ans[i].second);
// }