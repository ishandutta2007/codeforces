#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7, INF=1e9+7;
string T[2];
int tr[4*LIM][2][2], ans[2][2], tmp[2][2], N=1;
void cnt(int l, int r) {
  l+=N; r+=N;
  vector<int>A, B;
  A.pb(l);
  if(l!=r) B.pb(r);
  while(l/2!=r/2) {
    if(l%2==0) A.pb(l+1);
    if(r%2==1) B.pb(r-1);
    l/=2; r/=2;
  }
  reverse(all(B));
  for(auto i : B) A.pb(i);
  ans[0][0]=ans[1][1]=-1;
  ans[0][1]=ans[1][0]=INF;
  for(auto i : A) {
    rep(j, 2) rep(l, 2) tmp[j][l]=INF;
    rep(j, 2) rep(l, 2) rep(k, 2) tmp[j][l]=min(tmp[j][l], ans[j][k]+tr[i][k][l]+1);
    rep(j, 2) rep(l, 2) ans[j][l]=tmp[j][l];
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m >> T[0] >> T[1];
  while(N<n) N*=2;
  rep(i, 2*N) rep(j, 2) rep(l, 2) tr[i][j][l]=INF;
  rep(i, n) {
    if(T[0][i]=='.') tr[N+i][0][0]=0;
    if(T[1][i]=='.') tr[N+i][1][1]=0;
    if(T[0][i]=='.' && T[1][i]=='.') tr[N+i][0][1]=tr[N+i][1][0]=1;
  }
  for(int i=N-1; i; --i) {
    rep(j, 2) rep(l, 2) tmp[j][l]=INF;
    rep(j, 2) rep(l, 2) rep(k, 2) tmp[j][l]=min(tmp[j][l], tr[2*i][j][k]+tr[2*i+1][k][l]+1);
    rep(j, 2) rep(l, 2) tr[i][j][l]=tmp[j][l];
  }
  while(m--) {
    int l, r;
    cin >> l >> r; --l; --r;
    if(l%n>r%n) swap(l, r);
    cnt(l%n, r%n);
    cout << (ans[l/n][r/n]==INF?-1:ans[l/n][r/n]) << '\n';
  }
}