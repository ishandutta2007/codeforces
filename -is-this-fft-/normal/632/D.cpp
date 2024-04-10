#include <iostream>

const int MAX_LCM = 1000005;

using namespace std;

int cnt [MAX_LCM], maxlen [MAX_LCM], arr [MAX_LCM];

int main () {
  ios::sync_with_stdio(false);

  int length, max_ans;
  cin >> length >> max_ans;

  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
    if (arr[i] <= max_ans) {
      cnt[arr[i]]++;
    }
  }

  for (int i = 1; i <= max_ans; i++) {
    for (int j = i; j <= max_ans; j += i) {
      maxlen[j] += cnt[i];
    }
  }

  int ans = 0;
  for (int i = 1; i <= max_ans; i++) {
    if (maxlen[i] > maxlen[ans]) {
      ans = i;
    }
  }

  if (ans == 0) {
    cout << 1 << " " << 0 << endl;
  } else {
    cout << ans << " " << maxlen[ans] << endl;
    for (int i = 1; i <= length; i++) {
      if (arr[i] <= ans && ans % arr[i] == 0) {
	cout << i << " ";
      }
    }
    cout << endl;
  }
}