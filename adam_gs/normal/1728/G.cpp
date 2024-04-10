#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=3e5+7;
const ll MOD=998244353;
int T[LIM], lewo[LIM], P[20];
ll seg[20][20], inc[1<<16], dziura[20][20][20];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int d, n, m;
  cin >> d >> n >> m;
  rep(i, n) cin >> T[i];
  rep(i, m) cin >> P[i+1];
  sort(T, T+n);
  P[0]=-MOD;
  P[m+1]=MOD;
  sort(P, P+m+2);
  rep(i, m+1) for(int j=i+1; j<=m+1; ++j) {
    seg[i][j]=1;
    rep(l, n) if(P[i]<T[l] && T[l]<P[j]) {
      ll p=min(T[l]-P[i], P[j]-T[l]);
      p=min(p, (long long)(d+1));
      seg[i][j]=(seg[i][j]*p)%MOD;
    }
  }
  rep(i, 1<<m) {
    int akt=0, bi=0;
    inc[i]=1;
    rep(j, m) if(i&(1<<j)) {
      inc[i]=(inc[i]*seg[akt][j+1])%MOD;
      akt=j+1;
      bi^=1;
    }
    inc[i]=(inc[i]*seg[akt][m+1])%MOD;
    if(bi) inc[i]=(MOD-inc[i])%MOD;
  }
  rep(i, m+1) { 
    rep(j, 1<<m) {
      int p1=i, p2=i+1;
      while(p1 && !(j&(1<<(p1-1)))) --p1;
      while(p2<=m && !(j&(1<<(p2-1)))) ++p2;
      dziura[i][p1][p2]=(dziura[i][p1][p2]+inc[j])%MOD;
    }
  }
  rep(i, m) lewo[P[i+1]]=i+1;
  rep(i, d) lewo[i+1]=max(lewo[i+1], lewo[i]);
  int q;
  cin >> q;
  while(q--) {
    int a;
    cin >> a;
    ll ans=0;
    for(int i=lewo[a]; i>=0; --i) for(int j=lewo[a]+1; j<=m+1; ++j) {
      ll dist=min(a-P[i], P[j]-a);
      dist=min(dist, (long long)(d+1));
      ans=(ans+dist*dziura[lewo[a]][i][j])%MOD;
    }
    cout << ans << '\n';
  }
}