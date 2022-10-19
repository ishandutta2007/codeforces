#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vbool;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int i = 1; i <= n; i++)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second


struct segTree{
  ll size;
  vll values;

  void init(ll n){
    size = 1;
    while(size < n) size *= 2;
    values.resize(2*size, 0);
  }

  void set(ll i, ll v, ll x, ll lx, ll rx){
    if(rx-lx == 1){
      values[x] = v;
      return;
    }
    ll m = (lx + rx)/2;
    if(i < m){
      set(i, v, 2*x+1, lx, m);
    }
    else{
      set(i, v, 2*x+2, m, rx);
    }
    values[x] = max(values[2*x+1], values[2*x+2]);
  }

  void set(ll i, ll v){
    set(i, v, 0, 0, size);
  }

  ll query(ll l, ll r, ll x, ll lx, ll rx){
    if(lx >= r || l >= rx) return 0;
    if(lx >= l && rx <= r) return values[x];
    ll m = (lx + rx)/2;
    ll s1 = query(l, r, 2*x+1, lx, m);
    ll s2 = query(l, r, 2*x+2, m, rx);
    return max(s1, s2);
  }

  ll query(ll l, ll r){
    return query(l, r, 0, 0, size);
  }
};

int main(){
  int t;
  cin>>t;
  while(t--){
    int n; cin>>n;
    vll a(n+1);
    ll maxi = 0;
    F1(i,n) {
      cin>>a[i];
      maxi = max(maxi, a[i]);
    }
    segTree st;
    st.init(maxi+2);
    vvll soyElProxA(n+1);
    vll pila;
    pila.pb(0);
    F1(i,n){
      while(pila.size()>0 && a[pila.back()] <= a[i]){
        soyElProxA[i].pb(pila.back());
        pila.pop_back();
      }
      pila.pb(i);
    }
    vll dp(n+1);
    F1(i,n){
      dp[i] = st.query(0,a[i]+1)+1;
      st.set(a[i], dp[i]);
      F0(j, soyElProxA[i].size()){
        dp[soyElProxA[i][j]]++;
        st.set(a[soyElProxA[i][j]], dp[soyElProxA[i][j]]);
      }
    }
    cout<<st.query(0,maxi+2)<<'\n';
  }
}