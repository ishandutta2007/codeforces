#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
  int n, lst, ans=0;
  cin >> n >> lst; --n;
  while(n--) {
    int a;
    cin >> a;
    if(lst+1<a) ++ans;
    if(lst+2<a) ++ans;
    if(lst+3<a) ++ans;
    lst=a;
  }
  cout << (ans<=2?"YES":"NO") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int _;
  cin >> _;
  while(_--) solve();
}