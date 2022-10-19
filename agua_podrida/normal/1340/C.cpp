#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

int n,m;
ll g,r;

void bfs01(vvll& dp, vi& d){
    deque<pair<ll,pi>> q;
    q.push_front(mp(0,mp(0,0)));
    ll dis;
    int i,j;
    while(!q.empty()){
        dis = q.front().F;
        i = q.front().S.F;
        j = q.front().S.S;
        q.pop_front();
        if(dp[i][j] != -1) continue;
        dp[i][j] = dis;
        if(i > 0 and j+d[i]-d[i-1] <= g) q.push_front(mp(dis,mp(i-1,j+d[i]-d[i-1])));
        if(i+1 < m and j+d[i+1]-d[i] <= g) q.push_front(mp(dis,mp(i+1,j+d[i+1]-d[i])));
        if(j == g) q.push_back(mp(dis+1,mp(i,0)));
    }
}

void c(){
    cin>>n>>m;
    vi d(m);
    F0(i,m) cin>>d[i];
    sort(todo(d));
    cin>>g>>r;
    vvll dp(m,vll(g+1,-1));
    bfs01(dp,d);
    ll res = INF;
    F0(j,g+1){
        if(dp[m-1][j] == -1) continue;
        mini(res,dp[m-1][j]*(g+r)+j);
    }
    if(res == INF) res = -1;
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}