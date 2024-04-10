#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int plusdiagonal[4000];
int minusdiagonal[4000];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ans += plusdiagonal[x+y];
    ans += minusdiagonal[x-y+2000];
    plusdiagonal[x+y]++;
    minusdiagonal[x-y+2000]++;
  }
  cout << ans << endl;
}