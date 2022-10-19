#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
  string x;
  cin >> x;
  string c=x;
  sort(all(c));
  rep(i, c.size()-1) if(c[i]+1!=c[i+1]) {
    cout << "NO\n";
    return;
  }
  if(c[0]!='a') {
    cout << "NO\n";
    return;
  }
  int p=0, k=0;
  int n=x.size();
  rep(i, n) if(x[i]=='a') p=k=i;
  rep(i, n-1) {
    if(p>0 && x[p-1]=='a'+i+1) --p;
    else if(k<n-1 && x[k+1]=='a'+i+1) ++k;
    else {
      cout << "NO\n";
      return;
    }
  }
    cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}