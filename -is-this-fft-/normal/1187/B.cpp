#include <iostream>
#include <string>

using namespace std;

const int MAX_L = 200005;
const int MAX_N = 130;

int cnt [MAX_N];
int needed [MAX_N][MAX_L];

void process () {
  string str;
  cin >> str;

  for (int i = 0; i < (int) str.size(); i++) {
    char c = str[i];
    cnt[c]++;
    needed[c][cnt[c]] = i + 1;
  }
}

void solve () {
  for (int i = 0; i < MAX_N; i++) {
    cnt[i] = 0;
  }
  
  string name;
  cin >> name;

  for (char c : name) {
    cnt[c]++;
  }

  int ans = 0;
  for (int i = 0; i < MAX_N; i++) {
    ans = max(ans, needed[i][cnt[i]]);
  }
  cout << ans << '\n';
}

int main () {
  int trash;
  cin >> trash;

  process();

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}