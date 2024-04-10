#include <iostream>

using namespace std;

string s;

int is_abc (int pos) {
  if (s[pos] == 'a') {
    return pos + 2 < (int) s.size() && s[pos + 1] == 'b' && s[pos + 2] == 'c';
  }

  if (s[pos] == 'b') {
    return pos + 1 < (int) s.size() && 0 <= pos - 1 && s[pos - 1] == 'a' && s[pos + 1] == 'c';
  }

  return 0 <= pos - 2 && s[pos - 2] == 'a' && s[pos - 1] == 'b';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, qc;
  cin >> n >> qc;
  cin >> s;

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += is_abc(i);
  }
  cnt /= 3;

  for (int i = 0; i < qc; i++) {
    int pos;
    char c;
    cin >> pos >> c;
    pos--;

    cnt -= is_abc(pos);
    s[pos] = c;
    cnt += is_abc(pos);

    cout << cnt << '\n';
  }
}