#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int maxdist (char c) {
  return max(abs(c - 'a'), abs(c - 'z'));
}

int main () {
  ios::sync_with_stdio(false);
  
  int length, target;
  string word;

  cin >> length >> target >> word;
  
  string ans = "";
  for (int i = 0; i < length; i++) {
    if (word[i] > 'm') {
      if (target <= maxdist(word[i])) {
	ans += (word[i] - target);
	target = 0;
      } else {
	ans += 'a';
	target -= maxdist(word[i]);
      }
    } else {
      if (target < maxdist(word[i])) {
	ans += (word[i] + target);
	target = 0;
      } else {
	ans += 'z';
	target -= maxdist(word[i]);
      }
    }
  }

  if (target != 0) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}