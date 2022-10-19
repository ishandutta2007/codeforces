#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int nxt[26], prv[26], F[26];
int fnd(int x) {
  if(F[x]==x) return x;
  return F[x]=fnd(F[x]);
}
void uni(int a, int b) {
  if(fnd(a)==fnd(b)) return;
  F[fnd(b)]=fnd(a);
}
void solve() {
  int n;
  string s;
  cin >> n >> s;
  rep(i, 26) {
    F[i]=i;
    nxt[i]=prv[i]=-1;
  }
  int ile=0;
  for(auto i : s) {
    int x=i-'a';
    if(prv[x]==-1) {
      if(ile==25) {
        rep(j, 26) if(nxt[j]==-1) {
          nxt[j]=x;
          prv[x]=j;
        }
      } else {
        rep(j, 26) if(nxt[j]==-1 && fnd(x)!=fnd(j)) {
          prv[x]=j;
          nxt[j]=x;
          ++ile;
          uni(x, j);
          break;
        }
      }
    }
    cout << char(prv[x]+'a');
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}