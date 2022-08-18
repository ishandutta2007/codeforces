#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 5;

int arr [MAX_N];
int vis [MAX_N];

void solve () {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    vis[i] = 0;
  }

  vector<int> stk;
  for (int i = 1; true; i = i - arr[i]) {
    if (vis[i]) {
      vector<int> ans;
      for (int j = stk.size() - 1; j >= 0; j--) {
        ans.push_back(stk[j]);
        if (stk[j] == i) break;
      }

      printf("%d\n", (int) ans.size());
      for (int u : ans) {
        printf("%d ", u);
      }
      printf("\n");
      return;
    } else {
      vis[i] = 1;
      stk.push_back(i);
    }
  }
}

int main () {
  int testc;
  scanf("%d", &testc);

  for (int i = 0; i < testc; i++) {
    solve();
  }
}