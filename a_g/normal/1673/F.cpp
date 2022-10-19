#include <bits/stdc++.h>
using namespace std;

const int N = 32;
int label[N][N];
pair<int, int> coord[N*N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int z = 0; z < 10; z++) {
    if (z&1) {
      // double vertically
      int m = (1<<(z/2));
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2*m; j++) {
          label[i+m][j] = label[m-1-i][j]+(1<<z);
        }
      }
    }
    else {
      // double horizontally
      int m = (1<<(z/2));
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          label[i][j+m] = label[i][m-1-j]+(1<<z);
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      coord[label[i][j]] = make_pair(i+1, j+1);
      //cout << label[i][j] << ' ';
    }
    //cout << endl;
  }

  int n, k;
  cin >> n >> k;

  int tot = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-1; j++) {
      tot += (label[i][j]^label[i][j+1]);
      cout << (label[i][j]^label[i][j+1]) << ' ';
    }
    cout << endl;
  }
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n; j++) {
      tot += (label[i][j]^label[i+1][j]);
      cout << (label[i][j]^label[i+1][j]) << ' ';
    }
    cout << endl;
  }
  //cout << tot << endl;
  int pr = 0;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    pr ^= x;
    cout << coord[pr].first << " " << coord[pr].second << endl;
  }
}