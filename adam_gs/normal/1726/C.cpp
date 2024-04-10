#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
int F[LIM], ans;
int fnd(int x) {
  if(F[x]==x) return x;
  return F[x]=fnd(F[x]);
}
void uni(int a, int b) {
  if(fnd(a)==fnd(b)) return;
  F[fnd(b)]=fnd(a);
  --ans;
}
void solve() {
  int n;
  string s;
  cin >> n >> s; n*=2;
  ans=n;
  rep(i, n) F[i]=i;
  stack<int>S;
  rep(i, n) {
    if(s[i]=='(') S.push(i);
    else {
      int p=S.top(); S.pop();
      uni(i, p);
      if(p && s[p-1]==')') uni(p, p-1);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}