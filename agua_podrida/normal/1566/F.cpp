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
#define todo(v) v.begin(),v.end()
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
double PI = acos(-1.0);
#define fora(e,v) for(auto e : v)
const ll mod = 998244353;
const ll INF  = 1e18;
const double eps = 0.000000001;

int n,m;

void filtrar_resueltos(vll& p, vpll& inter){
    sort(todo(p));
    sort(todo(inter));
    vpll res;
    ll l,r;
    for(auto x : inter){
        tie(l,r) = x;
        if(p.back() < l or p[0] > r) res.pb(x);
        else {
            int lo = -1, hi = n;
            while(lo+1 != hi){
                int m = (lo+hi)/2;
                if(p[m] >= l) hi = m;
                else lo = m;
            }
            if(p[hi] > r) res.pb(x);
        }
    }
    inter = res;
}

bool cmp(pll a, pll b){
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

void filtrar_contienen(vpll& inter){
    vpll res;
    sort(todo(inter),cmp);
    ll r = INF;
    F0R(i,inter.size()){
        if(inter[i].second < r){
            r = inter[i].second;
            res.pb(inter[i]);
        }
    }
    reverse(todo(res));
    inter = res;
    m = inter.size();
}

void actualizar(vpll& dp, vll& p, vpll& inter, int k, int& i){
    vll pref(dp.size()), suf(dp.size());
    pref[0] = dp[0].first + 2*dp[0].second;
    F1(j,dp.size()-1) pref[j] = min(pref[j-1],dp[j].first + 2*dp[j].second);
    suf.back() = dp.back().first + dp.back().second;
    F0R(j,dp.size()-1) suf[j] = min(suf[j+1],dp[j].first + dp[j].second);
    vpll dpp;
    int j = i;
    while(j < m and inter[j].first < p[k+1]) j++;
    if(j == i) dpp.pb({suf[0],0});
    else {
        int m = 0;
        int l = i,r = i+1;
        dpp.pb({suf[0],p[k+1] - inter[l].second});
        while(r < j){
            ll posl = inter[l].first;
            ll posr = inter[r].second;
            while(m < dp.size() and dp[m].second < posl-p[k]) m++;
            ll costp = INF;
            if(m < dp.size()) costp = suf[m] + 2*(posl-p[k]);
            if(m > 0) mini(costp,pref[m-1] + posl - p[k]);
            dpp.pb({costp,p[k+1]-posr});
            l++, r++;
        }
        ll posl = inter[l].first;
        while(m < dp.size() and dp[m].second < posl-p[k]) m++;
        ll costp = INF;
        if(m < dp.size()) costp = suf[m] + 2*(posl-p[k]);
        if(m > 0) mini(costp,pref[m-1] + posl - p[k]);
        dpp.pb({costp,0});
        reverse(todo(dpp));
    }
    i = j;
    dp = dpp;
}

void a(){
    cin>>n>>m;
    vll p(n);
    vpll inter(m);
    F0(i,n) cin>>p[i];
    F0(i,m) cin>>inter[i].first>>inter[i].second;
    filtrar_resueltos(p,inter);
    filtrar_contienen(inter);

    if(m == 0) {
        cout<<"0\n";
        return;
    }

    vpll dp;
    if(inter[0].first > p[0]) dp.pb({0,0});
    else dp.pb({0,p[0]-inter[0].second});
    int i = 0;
    while(i < m and inter[i].first < p[0]) i++;
    F0(j,n-1) actualizar(dp,p,inter,j,i);

    ll res = INF;
    if(i == m) for(auto x : dp) mini(res,x.first+x.second);
    else {
        ll der = inter.back().first - p.back();
        for(auto x : dp) mini(res,x.first+x.second+der+min(x.second,der));
    }
    cout<<res<<'\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) a();
    return 0;
}