#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7, INF=1e9+7;
int T[LIM], P[LIM], tr[4*LIM], lazy[4*LIM], N, n, q;
void spl(int v) {
  tr[2*v]+=lazy[v];
  tr[2*v+1]+=lazy[v];
  lazy[2*v]+=lazy[v];
  lazy[2*v+1]+=lazy[v];
  lazy[v]=0;
}
void ustaw(int v, int l, int r, int a, int x) {
  if(a<l || r<a) return;
  if(l==r) {
    tr[v]=x;
    return;
  }
  if(lazy[v]) spl(v);
  int mid=(l+r)/2;
  ustaw(2*v, l, mid, a, x);
  ustaw(2*v+1, mid+1, r, a, x);
  tr[v]=min(tr[2*v], tr[2*v+1]);
}
void upd(int v, int l, int r, int a, int b, int x) {
  if(b<l || a>r) return;
  if(a<=l && r<=b) {
    tr[v]+=x;
    lazy[v]+=x;
    return;
  }
  if(lazy[v]) spl(v);
  int mid=(l+r)/2;
  upd(2*v, l, mid, a, b, x);
  upd(2*v+1, mid+1, r, a, b, x);
  tr[v]=min(tr[2*v], tr[2*v+1]);
}
int znajdz(int v, int l, int r) {
  if(tr[v]>0) return -1;
  if(l==r) return l;
  if(lazy[v]) spl(v);
  int mid=(l+r)/2;
  if(tr[2*v]<=0) return znajdz(2*v, l, mid);
  return znajdz(2*v+1, mid+1, r);
}
int wypisz() {
  rep(i, n) cout << min(P[i], 1);
  cout << '\n';
  return 0;
}
int licz(int szukana) {
  N=1;
  while(N<n) N*=2;
  rep(i, 2*N) {
    tr[i]=INF;
    lazy[i]=0;
  }
  int l=0, ile=0, akt=0;
  rep(i, n) {
    P[i]=0;
    if(ile==q) continue;
    if(T[i]>q-ile) {
      P[i]=1;
      ustaw(1, 0, N-1, i, T[i]-(q-ile));
      ++ile;
    } else P[i]=2;
    ++l; ++akt;
  }
  if(akt==szukana) return wypisz();
  int ans=akt;
  rep(i, n) if(P[i]==1) {
    P[i]=0; --akt; --ile;
    ustaw(1, 0, N-1, i, INF);
    upd(1, 0, N-1, i, n-1, -1);
    int x=znajdz(1, 0, N-1);
    while(x!=-1) {
      P[x]=2; --ile;
      ustaw(1, 0, N-1, x, INF);
      upd(1, 0, N-1, x, n-1, -1);
      x=znajdz(1, 0, N-1);
    }
    while(l<n && ile!=q) {
      if(T[l]>q-ile) {
        P[l]=1;
        ustaw(1, 0, N-1, l, T[l]-(q-ile));
        ++ile;
      } else P[l]=2;
      ++l; ++akt;
    }
    ans=max(ans, akt);
    if(ans==szukana) return wypisz();
  }
  return ans;
}
void solve() {
  cin >> n >> q;
  rep(i, n) cin >> T[i];
  licz(licz(INF));
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}