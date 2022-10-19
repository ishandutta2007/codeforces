#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
using ll = long long;
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
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define todo(v) v.begin(),v.end()
const ll mod = 1e9+7;
const ll INF  = 8e18;
const double eps = 0.00000001;

int bb(vi& v, int x){
    int lo = 0;
    int hi = v.size();
    while(lo+1 != hi){
        int m = (lo+hi)/2;
        if(v[m] <= x) lo = m;
        else hi = m;
    }
    return lo;
}

void index_compression(vi& a){
    vi b = a;
    sort(todo(b));
    int j = 0;
    F0(i,b.size()) if(i == 0 or b[i] != b[i-1]) b[j] = b[i], j++;
    while(b.size() > j) b.pop_back();
    for(int& x : a) x = bb(b,x);
}

bool ord(pi a, pi b){
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

void delete_nested(vpi& b){
    sort(todo(b),ord);
    int j = 0;
    int r = -1;
    F0(i,b.size()){
        if(b[i].second > r) b[j] = b[i], j++, r = b[i].second;
    }
    while(b.size() > j) b.pop_back();
}

void f(){
    int n,m;
    cin>>n>>m;
    vi a(n);
    F0(i,n) cin>>a[i];
    index_compression(a);
    vpi b(m);
    F0(i,m) cin>>b[i].first>>b[i].second;
    F0(i,m) b[i].first--, b[i].second--;
    delete_nested(b);

    vector<deque<int>> dp(n);
    set<int> coso;
    int l = 0, r = 0;
    int li,ri;
    vector<pair<pi,pi>> c;
    for(auto p : b){
        tie(li,ri) = p;
        while(r <= ri){
            dp[a[r]].push_back(r);
            coso.insert(a[r]);
            r++;
        }
        while(l < li){
            dp[a[l]].pop_front();
            coso.insert(a[l]);
            l++;
        }
        for(auto x : coso){
            int k = dp[x].size();
            if(k >= 2){
                int l1 = dp[x].front();
                int l2 = *(++dp[x].begin());
                int r2 = dp[x].back();
                int r1 = *(--(--dp[x].end()));
                c.pb({{l1,r1},{l2,r2}});
            }
        }
        coso.clear();
    }
    if(c.empty()){
        cout<<"0\n";
        return;
    }
    int res = n-1;
    sort(todo(c));
    l = 0;
    r = -1;
    for(auto p : c) maxi(r,p.first.second);
    mini(res,r-l+1);
    int i = 0;
    int maxl = n-1;
    for(auto p : c) mini(maxl,p.second.first);
    while(l < maxl){
        while(i < c.size() and c[i].first.first == l){
            maxi(r,c[i].second.second);
            i++;
        }
        l++;
        mini(res,r-l+1);
    }
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    F1(x,t) f();
}