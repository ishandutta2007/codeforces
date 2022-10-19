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
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 1000000007

void a(){
    int n,x,y;
    cin>>n>>x>>y;
    int res = 0;
    while(n*y > (x+res)*100) res++;
    cout<<res<<'\n';
}

bool esAum(string a){
    int n = a.size();
    F0(i,n) {
        if(a[i] == '#') return true;
        if(a[i] != ' ') return false;
    }
    return false;
}

string comprimir(string a){
    int n = a.size();
    string res;
    F0(i,n) if(a[i] != ' ') res.pb(a[i]);
    return res;
}

void agregar(string& res, string a){
    int n = a.size();
    F0(i,n) if(a[i] != ' ') res.pb(a[i]);
}

void b(){
    vector<string> input;
    string s;
    while(getline(cin,s)) input.pb(s);
    vector<string> res;
    F0(i,input.size()){
        if(esAum(input[i])) res.pb(input[i]);
        else if(res.empty() or esAum(res.back())) res.pb(comprimir(input[i]));
        else agregar(res.back(),input[i]);
    }
    F0(i,res.size()) cout<<res[i]<<'\n';
}

void c(){
    int n;
    double a,d;
    cin>>n>>a>>d;
    double maximo = 0.0;
    double t,v;
    F0(i,n){
        cin>>t>>v;
        double ti;
        if(v*v/2/a > d) ti = t + sqrt(2*d/a);
        else ti = t + v/a + (d-v*v/2/a) / v;
        maxi(maximo,ti);
        cout<<setprecision(9)<<fixed<<max(ti,maximo)<<'\n';
    }
}

void d(){
    int n,l,k;
    cin>>n>>l>>k;
    vd p(n);
    vi a(n);
    F0(i,n) cin>>p[i];
    F0(i,n) p[i] /= 100.0;
    F0(i,n) cin>>a[i];

    vvd dp(n+1,vd(n+1,0.0));
    dp[0][min(k,n)] = 1.0;
    F0(i,n){
        if(a[i] == -1) continue;
        F0R(pr,n+1){
            dp[pr][n] *= 1.0-p[i];
            if(pr > 0) REP(esp,max(0,n-a[i]),n) dp[pr][n] += dp[pr-1][esp] * p[i];
            F0R(esp,n){
                dp[pr][esp] *= 1.0-p[i];
                if(pr > 0 and esp-a[i] >= 0) dp[pr][esp] += dp[pr-1][esp-a[i]] * p[i];
            }
        }
    }

    F0(i,n){
        if(a[i] >= 1) continue;
        F0R(pr,n+1){
            F0(esp,n+1){
                dp[pr][esp] *= 1.0-p[i];
                if(pr > 0 and esp < n) dp[pr][esp] += dp[pr-1][esp+1] * p[i];
            }
        }
    }

    double res = 0.0;
    REP(pr,l,n) F0(esp,n+1) res += dp[pr][esp];

    cout<<setprecision(9)<<fixed<<res<<'\n';
}

int main() {
    //freopen("../input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    d();
    return 0;
}