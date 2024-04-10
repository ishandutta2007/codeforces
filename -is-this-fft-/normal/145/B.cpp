#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 7;

void failure () {
  cout << -1 << endl;
  exit(0);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int c4, c7, c47, c74;
  cin >> c4 >> c7 >> c47 >> c74;

  vector<int> ans;
  if (c47 == c74) {
    if (c4 > c47 && c7 >= c74) {
      // 4747474
      ans.push_back(4);
      for (int i = 0; i < c74; i++) {
        ans.push_back(7);
        ans.push_back(4);
      }
    } else if (c7 > c74 && c4 >= c47) {
      // 7474747
      ans.push_back(7);
      for (int i = 0; i < c47; i++) {
        ans.push_back(4);
        ans.push_back(7);
      }
    } else {
      failure();
    }
  } else if (c47 == 1 + c74 && c4 >= c47 && c7 >= c47) {
    // 474747
    for (int i = 0; i < c47; i++) {
      ans.push_back(4);
      ans.push_back(7);
    }
  } else if (c74 == 1 + c47 && c4 >= c74 && c4 >= c74) {
    // 747474
    for (int i = 0; i < c74; i++) {
      ans.push_back(7);
      ans.push_back(4);
    }
  } else {
    failure();
  }

  int ext4 = c4, ext7 = c7, fst4 = INF, lst7 = -1;
  for (int i = 0; i < (int) ans.size(); i++) {
    if (ans[i] == 4) {
      ext4--;
      fst4 = min(fst4, i);
    }

    if (ans[i] == 7) {
      ext7--;
      lst7 = max(lst7, i);
    }
  }

  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i];
    if (i == fst4) {
      for (int j = 0; j < ext4; j++) {
        cout << 4;
      }
    }
    if (i == lst7) {
      for (int j = 0; j < ext7; j++) {
        cout << 7;
      }
    }
  }
  cout << endl;
}