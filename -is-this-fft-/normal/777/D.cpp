#include <iostream>
#include <string>

const int MAX_STR = 500005;

using namespace std;

string hashtags [MAX_STR];

int cutoff (string before, string after) {
  for (int i = 0; i < min((int) before.size(), (int) after.size()); i++) {
    if (before[i] > after[i]) {
      return i;
    } else if (before[i] < after[i]) {
      return (int) before.size();
    }
  }

  if ((int) before.size() > (int) after.size()) {
    return (int) after.size();
  } else {
    return (int) before.size();
  }
}

int main () {
  int strc;
  cin >> strc;

  for (int i = 0; i < strc; i++) {
    cin >> hashtags[i];
  }
  
  for (int i = strc - 2; i >= 0; i--) {
    int cut = cutoff(hashtags[i], hashtags[i + 1]);
    hashtags[i] = hashtags[i].substr(0, cut);
  }

  for (int i = 0; i < strc; i++) {
    cout << hashtags[i] << '\n';
  }
}