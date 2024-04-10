#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int licz(vector<int>A, vector<int>B) {
  vector<int>V, rowne;
  for(auto i : A) V.pb(i);
  for(auto i : B) V.pb(i);
  sort(all(V));
  int ile=0, l=0, k=0, sum=0, ans=0;
  for(auto i : B) {
    while(l<A.size() && A[l]<i) ++l;
    if(l<A.size() && A[l]==i) rowne.pb(1);
    else rowne.pb(0);
  }
  for(auto i : rowne) sum+=i;
  ans=sum;
  l=0;
  for(auto i : V) {
    while(ile<A.size() && A[ile]<=i) ++ile;
    while(l<B.size() && B[l]<i-ile+1) ++l;
    while(k<B.size() && B[k]<=i) {
      sum-=rowne[k];
      ++k;
    }
    ans=max(ans, k-l+sum);
  }
  return ans;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int>A1, A2, B1, B2;
  rep(i, n) {
    int a;
    cin >> a;
    if(a<0) A1.pb(-a);
    else A2.pb(a);
  }
  rep(i, m) {
    int a;
    cin >> a;
    if(a<0) B1.pb(-a);
    else B2.pb(a);
  }
  reverse(all(A1));
  reverse(all(B1));
  int ans=licz(A1, B1)+licz(A2, B2);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}