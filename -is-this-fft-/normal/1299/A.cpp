#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];
int pref [MAX_N];
int suff [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] | arr[i];
  }

  for (int i = n; i >= 1; i--) {
    suff[i] = suff[i + 1] | arr[i];
  }

  pair<int, int> ans = {-1, -1};
  for (int i = 1; i <= n; i++) {
    int oth = pref[i - 1] | suff[i + 1];
    ans = max(ans, make_pair((arr[i] | oth) - oth, i));
  }

  cout << arr[ans.second] << " ";
  for (int i = 1; i <= n; i++) {
    if (i != ans.second) {
      cout << arr[i] << " ";
    }
  }
  cout << endl;
}