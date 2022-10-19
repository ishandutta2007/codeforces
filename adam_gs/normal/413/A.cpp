#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begini(), a.end()
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, mi, ma;
  cin >> n >> m >> mi >> ma;
  int mi2=100, ma2=1;
  rep(i, m) {
    int a;
    cin >> a;
    mi2=min(mi2, a);
    ma2=max(ma2, a);
  }
  if(mi2<mi || ma2>ma) {
    cout << "Incorrect\n";
    return 0;
  }
  int ile=0;
  if(mi2>mi) ++ile;
  if(ma2<ma) ++ile;
  cout << (ile<=n-m?"Correct":"Incorrect") << '\n';
}