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

void flip(char& c){
    if(c == '1') c = '0';
    else c = '1';
}

void a(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    F0(i,n) cin>>a[i];

    vi x,y;
    F0(i,n-2) {
        F0(j,m){
            if(a[i][j] == '0') continue;
            if(j+1 < m and a[i][j+1] == '1'){
                x.pb(i); y.pb(j);
                x.pb(i); y.pb(j+1);
                x.pb(i+1); y.pb(j);
                a[i][j] = '0';
                a[i][j+1] = '0';
                flip(a[i+1][j]);
            }
            else {
                x.pb(i); y.pb(j);
                a[i][j] = '0';
                x.pb(i+1); y.pb(j);
                flip(a[i+1][j]);
                if(j+1 < m) {
                    x.pb(i+1); y.pb(j+1);
                    flip(a[i+1][j+1]);
                }
                else {
                    x.pb(i+1); y.pb(j-1);
                    flip(a[i+1][j-1]);
                }
            }
        }
    }

    F0(j,m-1){
        if(a[n-1][j] == '0' and a[n-2][j] == '0') continue;
        if(a[n-1][j] == '0'){
            x.pb(n-2); y.pb(j);
            flip(a[n-2][j]);
            x.pb(n-2); y.pb(j+1);
            flip(a[n-2][j+1]);
            x.pb(n-1); y.pb(j+1);
            flip(a[n-1][j+1]);
        }
        else {
            x.pb(n-1); y.pb(j);
            flip(a[n-1][j]);
            if(a[n-2][j] == '1') {
                x.pb(n-2); y.pb(j);
                flip(a[n-2][j]);
            }
            else {
                x.pb(n-2); y.pb(j+1);
                flip(a[n-2][j+1]);
            }
            x.pb(n-1); y.pb(j+1);
            flip(a[n-1][j+1]);
        }
    }

    if(a[n-1][m-1] == '1' or a[n-2][m-1] == '1'){
        int j = m-1;
        if(a[n-2][m-1] == '0'){
            x.pb(n-1); y.pb(j);
            x.pb(n-1); y.pb(j-1);
            x.pb(n-2); y.pb(j);

            x.pb(n-1); y.pb(j);
            x.pb(n-1); y.pb(j-1);
            x.pb(n-2); y.pb(j-1);

            x.pb(n-1); y.pb(j);
            x.pb(n-2); y.pb(j);
            x.pb(n-2); y.pb(j-1);
        }
        else if(a[n-1][m-1] == '0'){
            x.pb(n-2); y.pb(j);
            x.pb(n-1); y.pb(j-1);
            x.pb(n-1); y.pb(j);

            x.pb(n-2); y.pb(j);
            x.pb(n-1); y.pb(j-1);
            x.pb(n-2); y.pb(j-1);

            x.pb(n-2); y.pb(j);
            x.pb(n-1); y.pb(j);
            x.pb(n-2); y.pb(j-1);
        }
        else {
            x.pb(n-2); y.pb(j);
            x.pb(n-1); y.pb(j-1);
            x.pb(n-2); y.pb(j-1);

            x.pb(n-1); y.pb(j);
            x.pb(n-1); y.pb(j-1);
            x.pb(n-2); y.pb(j-1);
        }
    }

    cout<<x.size()/3<<'\n';
    int i = 0;
    while(i < x.size()){
        cout<<x[i]+1<<' '<<y[i]+1<<' ';
        i++;
        cout<<x[i]+1<<' '<<y[i]+1<<' ';
        i++;
        cout<<x[i]+1<<' '<<y[i]+1<<'\n';
        i++;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) a();
    return 0;
}