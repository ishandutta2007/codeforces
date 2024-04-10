#include <bits/stdc++.h>

using namespace std;

const int M = 55;

int n, a[M][M];
int cnt[M];
int p[M];
bool used[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      --a[i][j];
    }
}

void kill() {
  for (int i = 0; i < n; ++i) {
    fill(cnt, cnt + M, 0);
    for (int j = 0; j < n; ++j)
      if (i != j)
        cnt[a[i][j]]++;
    
    for (int j = 0; j < n; ++j) {
      if (cnt[j] == n - j - 1 && !used[j]) {
        p[i] = j;
        used[j] = true;
        break;
      }
    }
  }

  for (int i = 0; i < n; ++i)
    cout << p[i] + 1 << " ";
}


int main() {
  ios_base::sync_with_stdio(false);
  read();
  kill();
}