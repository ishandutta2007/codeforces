#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=2e5+7;
ll T[LIM];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  ld akt=0, ans=0;
  rep(i, n) cin >> T[i];
  rep(i, k) akt+=T[i];
  rep(i, n-k+1) {
    ans+=akt;
    akt-=T[i];
    akt+=T[i+k];
  }
  cout << fixed << setprecision(6) << ans/(n-k+1) << '\n';
}