#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  bool alla = true;
  for(int i = 0; i < n; i++)
    if(s[i] != 'a')
      alla = false;
  if(alla) {
    s[n - 1] = 'z';
    cout << s << '\n';
  }
  else {
    int i = 0;
    while(s[i] == 'a')
      i++;
    while(i < n && s[i] != 'a') {
      s[i]--;
      i++;
    }
    cout << s << '\n';
  }
  return 0;
}