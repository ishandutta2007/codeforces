#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = 100005;

int arr [maxn][15];
int pos [maxn][15];

int main () {
  ios::sync_with_stdio(false);
  
  int length, height;
  cin >> length >> height;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < length; j++) {
      cin >> arr[j][i];

      pos[arr[j][i]][i] = j;
    }
  }

  ll ans = 1, curl = 1;
  vector<int> cur (height);
  for (int j = 0; j < height; j++) {
    cur[j] = pos[arr[0][0]][j];
  }
  
  for (int i = 1; i < length; i++) {
    bool ok = true;
    for (int j = 0; j < height; j++) {
      if (cur[j] + 1 != pos[arr[i][0]][j]) {
        ok = false;
      }
      cur[j] = pos[arr[i][0]][j];
    }

    if (ok) {
      curl++;
    } else {
      curl = 1;
    }

    ans += curl;
  }

  cout << ans << endl;
}