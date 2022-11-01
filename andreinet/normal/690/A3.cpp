#include <bits/stdc++.h>

using namespace std;

void Solve() {
   int N, R, S = 0;
   cin >> N >> R;
   for (int i = 1; i < N; ++i) {
      int x;
      cin >> x;
      S += x;
   }
   S %= N;
   R %= N;
   int ans = (R + N - S) % N;
   if (ans == 0)
      ans = N;
   cout << ans << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--)
      Solve();
   return 0;
}