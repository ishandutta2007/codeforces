// orz jiangly
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100;
int n, f[N][N], x[N][N], y[N][N];
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  memset(f, 0x3f, sizeof(f));
  for(int s = 0; s < N; s++)
    for(int i = 0; i <= s; i++) {
      int j = s - i;
      if(s <= 2) f[i][j] = 0;
      for(int x = 0; x <= i; x++)
        for(int y = 0; y <= j; y++) {
          int v = max(f[x + y][i - x], f[i + j - x - y][x]) + 1;
          if(v < f[i][j]) f[i][j] = v, ::x[i][j] = x, ::y[i][j] = y;
        }
    }
  cin >> n;
  vector<int> T, F;
  for(int i = 1; i <= n; i++) T.push_back(i);
  while(T.size() + F.size() > 2) {
    int x = T.size() / 2, y = F.size() / 2;
    if(T.size() + F.size() < N) x = ::x[T.size()][F.size()], y = ::y[T.size()][F.size()];
    vector<int> T0(T.begin(), T.begin() + x), T1(T.begin() + x, T.end());
    vector<int> F0(F.begin(), F.begin() + y), F1(F.begin() + y, F.end());
    cout << "? " << T0.size() + F0.size() << " ";
    for(int it : T0) cout << it << " ";
    for(int it : F0) cout << it << " ";
    cout << endl;
    string res;
    cin >> res, T.clear(), F.clear();
    if(res == "YES") {
      for(int it : T0) T.push_back(it);
      for(int it : F0) T.push_back(it);
      for(int it : T1) F.push_back(it);
    }
    else {
      for(int it : T1) T.push_back(it);
      for(int it : F1) T.push_back(it);
      for(int it : T0) F.push_back(it);
    }
  }
  for(int it : T) {
    cout << "! " << it << endl;
    string res;
    cin >> res;
    if(res == ":)") exit(0);
  }
  for(int it : F) {
    cout << "! " << it << endl;
    string res;
    cin >> res;
    if(res == ":)") exit(0);
  }
  return 0;
}