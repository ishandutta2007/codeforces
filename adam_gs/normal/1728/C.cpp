#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int operacja(int x) {
  int ans=0;
  while(x) {
    ++ans;
    x/=10;
  }
  return ans;
}
void solve() {
  int n;
  cin >> n;
  multiset<int>A, B;
  int ans=0;
  rep(i, n) {
    int a;
    cin >> a;
    A.insert(a);
  }
  rep(i, n) {
    int a;
    cin >> a;
    B.insert(a);
  }
  while(!A.empty()) {
    auto it1=A.end(), it2=B.end();
    --it1; --it2;
    int x=*it1, y=*it2;
    A.erase(it1);
    B.erase(it2);
    if(x==y) continue;
    if(x>y) x=operacja(x);
    else y=operacja(y);
    A.insert(x);
    B.insert(y);
    ++ans;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int _=1;
  cin >> _;
  while(_--) solve();
}