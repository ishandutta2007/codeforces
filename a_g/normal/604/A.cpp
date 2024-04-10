#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[5];
int w[5];
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < 5; i++) cin >> m[i];
  for (int i = 0; i < 5; i++) cin >> w[i];
  int hs, hu;
  cin >> hs >> hu;
  int ans = 100*hs-50*hu;
  for (int i = 0; i < 5; i++) {
    int x = 500*(i+1);
    ans += max(3*x/10, (250-m[i])*(x/250)-50*w[i]);
  }
  cout << ans << endl;
}