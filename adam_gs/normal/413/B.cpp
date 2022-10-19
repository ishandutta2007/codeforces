#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int T[20007][11], ile[11], ans[20007];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  rep(i, n) rep(j, m) cin >> T[i][j];
  while(k--) {
    int a, b;
    cin >> a >> b; --a; --b;
    --ans[a];
    ++ile[b];
  }
  rep(i, n) rep(j, m) ans[i]+=T[i][j]*ile[j];
  rep(i, n) cout << ans[i] << " ";
  cout << '\n';
}