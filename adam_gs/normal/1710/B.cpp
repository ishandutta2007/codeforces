#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7;
void solve() {
  ll n, m;
  cin >> n >> m;
  pair<pair<ll,ll>,ll>T[n];
  ll sum[n], ilem[n], ans[n];
  rep(i, n) {
    cin >> T[i].st.st >> T[i].st.nd;
    T[i].nd=i;
    sum[i]=ilem[i]=0;
    ans[i]=1;
  }
  sort(T, T+n);
  rep(i, n) {
    ll po=0, ko=i;
    while(po<ko) {
      ll sr=(po+ko)/2;
      if(T[sr].st.st<T[i].st.st-T[i].st.nd) po=sr+1; else ko=sr;
    }
    sum[po]+=T[i].st.nd-T[i].st.st;
    ++ilem[po];
    sum[i]-=T[i].st.nd-T[i].st.st;
    --ilem[i];
    --ilem[i];
    sum[i]+=T[i].st.nd+T[i].st.st;
    po=i; ko=n-1;
    while(po<ko) {
      ll sr=(po+ko)/2;
      if(T[sr].st.st<=T[i].st.st+T[i].st.nd) po=sr+1; else ko=sr;
    }
    if(T[po].st.st>T[i].st.st+T[i].st.nd) {
      sum[po]-=T[i].st.nd+T[i].st.st;
      ++ilem[po];
    }
  }
  rep(i, n) {
    if(i<n-1) {
      ilem[i+1]+=ilem[i];
      sum[i+1]+=sum[i];
    }
    sum[i]+=ilem[i]*T[i].st.st;
    sum[i]=max(sum[i]-m, 0ll);
  }
  ll musi=-INF;
  rep(i, n) {
    if(i) musi+=T[i].st.st-T[i-1].st.st;
    if(sum[i]) musi=max(musi, sum[i]);
    if(T[i].st.nd<musi) ans[T[i].nd]=0;
  }
  musi=-INF;
  for(int i=n-1; i>=0; --i) {
    if(i<n-1) musi+=T[i+1].st.st-T[i].st.st;
    if(sum[i]) musi=max(musi, sum[i]);
    if(T[i].st.nd<musi) ans[T[i].nd]=0;
  }
  rep(i, n) cout << ans[i];
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}