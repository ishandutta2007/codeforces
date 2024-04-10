#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 5;

bool r_neq [MAX_N][MAX_N];
bool d_neq [MAX_N][MAX_N];

int ans [MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n, m, K;
  cin >> n >> m >> K;

  for (int i = 0; i < n; i++) {
    string R;
    cin >> R;

    for (int j = 0; j < m - 1; j++) {
      r_neq[i][j] = R[j] != 'E';
    }

    if (i != n - 1) {
      string D;
      cin >> D;

      for (int j = 0; j < m; j++) {
        d_neq[i][j] = D[j] != 'E';
      }
    }
  }

  if (K == 1) {
    // what's wrong with people who do this?
    int ne = 0, tot = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m - 1; j++) {
        tot++;
        ne += r_neq[i][j];
      }

      if (i != n - 1) {
        for (int j = 0; j < m; j++) {
          tot++;
          ne += d_neq[i][j];
        }
      }
    }

    if (ne * 4 > tot) {
      cout << "NO" << endl;
      return 0;
    }

    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << 1 << " ";
      }
      cout << '\n';
    }
    return 0;
  }

  if (n <= m) {
    for (int i = 0; i < n; i++) {
      ans[i][0] = 0;
      for (int j = 1; j < m; j++) {
        ans[i][j] = ans[i][j - 1] ^ r_neq[i][j - 1];
      }

      if (i != 0) {
        int fails = 0;
        for (int j = 0; j < m; j++) {
          fails += ans[i - 1][j] ^ ans[i][j] ^ d_neq[i - 1][j];
        }

        if (m - fails < fails) {
          for (int j = 0; j < m; j++) {
            ans[i][j] = !ans[i][j];
          }
        }
      }
    }
  } else {
    for (int j = 0; j < m; j++) {
      ans[0][j] = 0;
      for (int i = 1; i < n; i++) {
        ans[i][j] = ans[i - 1][j] ^ d_neq[i - 1][j];
      }

      if (j != 0) {
        int fails = 0;
        for (int i = 0; i < n; i++) {
          fails += ans[i][j - 1] ^ ans[i][j] ^ r_neq[i][j - 1];
        }

        if (n - fails < fails) {
          for (int i = 0; i < n; i++) {
            ans[i][j] = !ans[i][j];
          }
        }
      }
    }
  }
  
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << 1 + ans[i][j] << " ";
    }
    cout << '\n';
  }
}