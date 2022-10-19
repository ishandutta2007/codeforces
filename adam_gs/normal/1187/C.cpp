#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e3+7;
int T[LIM];
vector<pair<int,int>>V;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while(m--) {
    int t, l, r;
    cin >> t >> l >> r; --l; --r;
    if(t) {
      while(l<r) {
        T[l]=1;
        ++l;
      }
    } else V.pb({l, r});
  }
  for(auto i : V) {
    bool ok=false;
    while(i.st<i.nd) {
      if(!T[i.st]) ok=true;
      ++i.st;
    }
    if(!ok) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  int x=1000000000;
  cout << x << " ";
  rep(i, n-1) {
    if(!T[i]) --x;
    cout << x << " ";
  }
  cout << '\n';
}