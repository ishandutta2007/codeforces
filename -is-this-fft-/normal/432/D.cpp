#include <iostream>
#include <string>
#include <vector>

const int MAX_LENGTH = 100005;;

using namespace std;

int zeta [MAX_LENGTH], cum [MAX_LENGTH];

int main () {
  string str;
  cin >> str;

  int left = 0, right = 0;
  zeta[0] = str.size();
  for (int i = 1; i < (int) str.size(); i++) {
    if (i >= right) {
      left = i;
      right = i;
      while (true) {
        if (str[right] == str[right - left]) {
          right++;
        } else {
          break;
        }
      }
      zeta[i] = right - left;
    } else if (zeta[i - left] < right - i) {
      zeta[i] = zeta[i - left];
    } else {
      left = i;
      while (true) {
        if (str[right] == str[right - left]) {
          right++;
        } else {
          break;
        }
      }
      zeta[i] = right - left;
    }
  }

  for (int i = 0; i < (int) str.size(); i++) {
    if (zeta[i] > 0) {
      cum[1]++;
      cum[1 + zeta[i]]--;
    }
  }

  for (int i = 1; i <= (int) str.size(); i++) {
    cum[i] += cum[i - 1];
  }

  vector<pair<int, int> > ans;
  for (int i = 1; i <= (int) str.size(); i++) {
    if (zeta[(int) str.size() - i] == i) {
      ans.push_back(make_pair(i, cum[i]));
    }
  }

  cout << (int) ans.size() << endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}