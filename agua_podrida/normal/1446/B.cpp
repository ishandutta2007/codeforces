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
typedef pair<double,double> pd;
typedef vector<pd> vpd;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
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
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

/*
vi a;
priority_queue<int> s;
int res[(int) 1e5+1];
vi coso[(int) 1e5+1];
vvi g;
priority_queue<int> q;

void dfs(int nodo){
    for(auto c : coso[nodo]) s.push(c);
    vi borro;
    while(!s.empty() and (s.top() > a[nodo] or (!q.empty() and s.top() == q.top()))) {
        if(!q.empty() and s.top() == q.top()) q.pop();
        else borro.pb(s.top());
        s.pop();
    }
    res[nodo] = s.size() - q.size();
    for(auto hijo : g[nodo]){
        dfs(hijo);
    }
    for(auto b : borro) s.push(b);
    for(auto c : coso[nodo]) {
        q.push(c);
    }
}

void e(){
    int n,m;
    cin>>n>>m;
    a.resize(n+1);
    int n2 = 1;
    while((1<<n2) < n) n2++;
    vvi padre(n2,vi(n+1));
    g.resize(n+1);
    F1(i,n){
        cin>>a[i];
        cin>>padre[0][i];
        if(i != 1) g[padre[0][i]].pb(i);
    }

    F1(j,n2-1){
        F1(i,n) padre[j][i] = padre[j-1][padre[j-1][i]];
    }

    int o,l,r;
    F0(i,m){
        cin>>o>>l>>r;
        int j = n2-1;
        while(o != 1 and a[padre[0][o]] <= r){
            while(a[padre[j][o]] > r) j--;
            o = padre[j][o];
        }
        coso[o].pb(l);
    }

    dfs(1);

    F1(i,n) {
        cout<<res[i];
        if(i < n) cout<<' ';
        else cout<<'\n';
    }
}*/

void a(){
    int n;
    ll w;
    cin>>n>>w;
    vpll a(n);
    F0(i,n) cin>>a[i].first;
    F0(i,n) a[i].second = i+1;
    sort(todo(a));
    while(!a.empty() and a.back().first > w) a.pop_back();
    int i = 0;
    while(i < a.size() and a[i].first < (w+1)/2) i++;
    if(i < a.size()) {
        cout<<"1\n"<<a[i].second<<'\n';
        return;
    }
    reverse(todo(a));
    ll suma = 0;
    vll res;
    F0(i,a.size()){
        suma += a[i].first;
        res.pb(a[i].second);
        if(suma >= (w+1)/2){
            sort(todo(res));
            cout<<res.size()<<'\n';
            F0(j,res.size()) cout<<res[j]<<' ';
            cout<<'\n';
            return;
        }
    }
    cout<<"-1\n";
}

void b(){
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vvi dp(n+1,vi(m+1));
    F0(i,n){
        F0(j,m){
            if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j]+2;
            else {
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]) - 1;
                maxi(dp[i+1][j+1],0);
            }
        }
    }
    int res = 0;
    F1(i,n) F1(j,m) maxi(res,dp[i][j]) ;
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    b();
    return 0;
}