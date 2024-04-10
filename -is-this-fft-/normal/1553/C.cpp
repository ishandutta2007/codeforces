#include <iostream>
#include <vector>

using namespace std;

const int N = 10;

bool definite (const vector<int> &rem, const vector<int> &sco) {
  if (sco[0] > sco[1] + rem[1]) {
    return true;
  }

  if (sco[1] > sco[0] + rem[0]) {
    return true;
  }

  return false;
}

int least_time (const string &s, int good_team) {
  vector<int> rem = {N / 2, N / 2};
  vector<int> sco = {0, 0};
  for (int i = 0; i < N; i++) {
    rem[i % 2]--;
    if (s[i] == '1') {
      sco[i % 2]++;
    } else if (s[i] == '?' && i % 2 == good_team) {
      sco[i % 2]++;
    }

    if (definite(rem, sco)) {
      return i + 1;
    }
  }

  return N;
}

void solve () {
  string s;
  cin >> s;

  cout << min(least_time(s, 0), least_time(s, 1)) << '\n';
}


int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}