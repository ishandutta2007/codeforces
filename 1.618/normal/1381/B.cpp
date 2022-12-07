#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 2005

using namespace std;
typedef long long ll;

int t, n, p[maxn << 1];
bool f[maxn << 1];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n + n; i++) scanf("%d", &p[i]);
  int i = 1, j = 1;
  vector<int> ws;
  while (i <= n + n) {
    while (j <= n + n && p[j] <= p[i]) j++;
    ws.push_back(j - i);
    i = j;
  }
  memset(f, 0, sizeof(f));
  f[0] = 1;
  for (auto w : ws) {
    
//    cout << w << " ";
    
    for (int j = n; j >= w; j--) {
      f[j] |= f[j - w];
    }
  }

//  cout << endl;
//  system("pause");
  
  puts(f[n] ? "YES" : "NO");
}
int main() {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}