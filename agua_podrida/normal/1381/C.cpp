#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
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
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 2e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define mod 1000000007

void c(){
    int n,x,y;
    cin>>n>>x>>y;
    vi a(n);
    F0(i,n) cin>>a[i];

    if(x == n){
        cout<<"YES\n";
        F0(i,n) cout<<a[i]<<' ';
        cout<<'\n';
        return;
    }

    priority_queue<pi> q;
    vvi ap(n+2);
    vi b(n);
    F0(i,n) ap[a[i]].pb(i);
    F1(i,n+1) q.push({ap[i].size(),i});
    int noAparece = 1;
    while(!ap[noAparece].empty()) noAparece++;

    int num,cant;
    F0(i,x){
        tie(cant,num) = q.top();
        q.pop();
        b[ap[num].back()] = num;
        ap[num].pop_back();
        q.push({cant-1,num});
    }

    vi dp;
    int masap = q.top().first;
    while(!q.empty()){
        num = q.top().second;
        q.pop();
        for(auto pos : ap[num]) dp.pb(pos);
    }

    F0(i,n-x) {
        if(x == y) break;
        b[dp[i]] = a[dp[(i+masap)%(n-x)]];
        if(a[dp[i]] == b[dp[i]]) b[dp[i]] = noAparece;
        else y--;
    }

    if(x != y){
        cout<<"NO\n";
        return;
    }

    F0(i,n) if(b[i] == 0) b[i] = noAparece;

    cout<<"YES\n";
    F0(i,n) cout<<b[i]<<' ';
    cout<<'\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) c();
}