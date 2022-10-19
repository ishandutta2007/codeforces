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
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
ll mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
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
#define F first
#define S second
#define INF 1e9
#define todo(v) v.begin(),v.end()
#define eps 0.000000001

void a(){
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    F0(i,n) cin>>a[i];
    F0(i,n) cin>>b[i];
    sort(todo(a));
    sort(todo(b));

    F0(i,n) cout<<a[i]<<' ';
    cout<<'\n';
    F0(i,n) cout<<b[i]<<' ';
    cout<<'\n';
}

void b(){
    string s;
    cin>>s;
    int n;
    n = s.size();
    int l = 0;
    int r = n-1;
    vvi res;
    vi abren;
    vi cierran;
    while(true){
        l = 0;
        r = n-1;
        res.pb({});
        abren.clear();
        cierran.clear();
        while(l < r){
            while(l < n and s[l] != '(') l++;
            while(r >= 0 and s[r] != ')') r--;
            if(l > r) break;
            abren.pb(l);
            s[l] = '.';
            cierran.pb(r);
            s[r] = '.';
            l++;
            r--;
        }
        F0(i,abren.size()) res.back().pb(abren[i]);
        reverse(todo(cierran));
        F0(i,cierran.size()) res.back().pb(cierran[i]);

        if(res.back().empty()) {
            res.pop_back();
            break;
        }
    }

    cout<<res.size()<<'\n';
    F0(i,res.size()){
        cout<<res[i].size()<<'\n';
        F0(j,res[i].size()) cout<<res[i][j]+1<<' ';
        cout<<'\n';
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    b();
    return 0;
}