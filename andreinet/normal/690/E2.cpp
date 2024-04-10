#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 600;
const int K_MAX = 16;

int H, W, K;
int a[N_MAX + 5][N_MAX + 5];
int b[K_MAX + 5][2][N_MAX + 5];
int c[K_MAX + 5][K_MAX + 5];
pair<int, int> d[(1 << K_MAX) + 5][K_MAX + 5];
int lol[K_MAX + 5];

inline int Abs(int x) { return x < 0 ? -x : x; }

void Solve() {
   cin >> H >> W >> K;
   for (int i = 1; i <= H; ++i)
      for (int j = 1; j <= W; ++j)
         cin >> a[i][j];
   for (int i = 0; i < K; ++i) {
      int u = H / K * i + 1;
      int d = H / K * (i + 1);
      for (int j = 3; j <= W - 2; ++j) {
         b[i][0][j] = (2 * a[u][j] + a[u][j - 1] + a[u][j + 1] + a[u + 1][j]) / 4;
         b[i][1][j] = (2 * a[d][j] + a[d][j - 1] + a[d][j + 1] + a[d - 1][j]) / 4;
      }
   }
   for (int i = 0; i < K; ++i)
      for (int j = 0; j < K; ++j) {
         c[i][j] = 0;
         for (int k = 3; k <= W - 2; ++k) {
            int df = Abs(b[i][1][k] - b[j][0][k]);
            c[i][j] += df * df / 100;
         }
      }
   
   memset(d, 0x3f, sizeof d);
   for (int i = 0; i < K; ++i)
      d[1 << i][i] = make_pair(0, 0);
   
   for (int cnf = 3; cnf < (1 << K); ++cnf)
      for (int last = 0; last < K; ++last)
         if (cnf >> last & 1) {
            if (d[cnf][last].first == 0)
               continue;
            int prv = cnf ^ 1 << last;
            for (int prvl = 0; prvl < K; ++prvl)
               if (prv >> prvl & 1) {
                  if (d[prv][prvl].first + c[prvl][last] < d[cnf][last].first)
                     d[cnf][last] = make_pair(d[prv][prvl].first + c[prvl][last], prvl);
               }
         }
   
   int cnfall = (1 << K) - 1, best = 0;
   for (int i = 1; i < K; ++i)
      if (d[cnfall][i] < d[cnfall][best])
         best = i;
   stack<int> q;
   for (int i = 0; i < K; ++i) {
      q.push(best);
      int aux = cnfall;
      cnfall ^= 1 << best;
      best = d[aux][best].second;
   }
   for (int i = 0; i < K; ++i) {
      lol[q.top() + 1] = i + 1;
      q.pop();
   }
   for (int i = 1; i <= K; ++i)
      cout << lol[i] << " ";
  /* for (int i = 0; i < K; ++i)
      for (int j = 0; j < K; ++j)
         if (i != j)
            cout << i + 1 << " " << j + 1 << ": " << c[i][j] << "\n";*/
   cout << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--)
      Solve();
   return 0;
}