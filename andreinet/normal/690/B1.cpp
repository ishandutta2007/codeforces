#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 50;

int N;
int a[N_MAX + 5][N_MAX + 5];
int u = N_MAX + 5, d = -1, l = N_MAX + 5, r = -1;

inline void UpdMax(int &a, int b) { if (b > a) a = b; }
inline void UpdMin(int &a, int b) { if (b < a) a = b; }

int Expected(int x, int y) {
   return (x >= u && x <= d + 1 && y >= l && y <= r + 1) +
          (x >= u && x <= d + 1 && y >= l - 1 && y <= r) +
          (x >= u - 1 && x <= d && y >= l && y <= r + 1) +
          (x >= u - 1 && x <= d && y >= l - 1 && y <= r);
}

int main() {
   ios::sync_with_stdio(false);
   cin >> N;
   for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= N; ++j) {
         char c;
         cin >> c;
         a[i][j] = c - '0';
         if (a[i][j] > 2) {
            UpdMin(u, i);
            UpdMax(d, i);
            UpdMin(l, j);
            UpdMax(r, j);
         }
      }
   
   if (u > d || l > r) {
      cout << "No\n";
      return 0;
   }
   
   for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= N; ++j)
         if (Expected(i, j) != a[i][j]) {
            cout << "No\n";
            return 0;
         }
   cout << "Yes\n";
   return 0;
}