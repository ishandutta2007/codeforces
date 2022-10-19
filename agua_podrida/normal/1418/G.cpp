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

vector<int, int> &
getVector(const unordered_map<ll, int> &trad, vector<map<int, int>> &g, int dst, int &prox, ll res, int v, int i);

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
#define PI acos(-1.0)

vi suma(vi& a, vi& b){
    vi res(a.size());
    F0(i,res.size()){
        res[i] = (a[i]+b[i]) % 3;
    }
    return res;
}

void g(){
    int n;
    cin>>n;
    vi a(n);
    F0(i,n) cin>>a[i];
    F0(i,n) a[i]--;
    int m = 30;
    vvi b(n,vi(m));
    F0(i,n) F0(j,m) b[i][j] = rand()%3;

    map<vi,int> s;
    vvi acum(n+1,vi(m));
    s[acum[0]]++;
    ll res = 0;
    int l = 0;
    vvi ap(n);
    F0(i,n){
        acum[i+1] = suma(acum[i],b[a[i]]);
        ap[a[i]].pb(i);
        if(ap[a[i]].size() > 3){
            int api = ap[a[i]].size();
            while(l <= ap[a[i]][api-4]){
                s[acum[l]]--;
                l++;
            }
        }
        res += (ll) s[acum[i+1]];
        s[acum[i+1]]++;
    }
    cout<<res<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    g();
    return 0;
}