#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
int tr[8*LIM], N;
int nwd(int a, int b) {
  if(!a) return b;
  return nwd(b%a, a);
}
int cnt(int l, int r) {
  l+=N; r+=N;
  int ans=nwd(tr[l], tr[r]);
  while(l/2!=r/2) {
    if(l%2==0) ans=nwd(ans, tr[l+1]);
    if(r%2==1) ans=nwd(ans, tr[r-1]);
    l/=2; r/=2;
  }
  return ans;
}
void solve() {
  int n;
  cin >> n;
  N=1;
  while(N<2*n) N*=2;
  rep(i, 2*N) tr[i]=0;
  int T[2*n];
  int jakie=0;
  rep(i, n) {
    cin >> T[i];
    T[n+i]=T[i];
    jakie=nwd(jakie, T[i]);
    tr[N+i]=T[i];
    tr[N+n+i]=T[i];
  }
  for(int i=N-1; i; --i) tr[i]=nwd(tr[2*i], tr[2*i+1]);
  int ma=0;
  rep(i, n) {
    int p=i, k=2*n-1;
    while(p<k) {
      int sr=(p+k)/2;
      if(cnt(i, sr)>jakie) p=sr+1; else k=sr;
    }
    ma=max(ma, p-i);
  }
  cout << ma << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}