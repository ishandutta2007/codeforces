#include <iostream>

using namespace std;
string s2;

int main()
{
  int n , p;
  cin >> n >> p;
  string s;
  cin >> s;
  s = "#" + s;
  for(int i = s.size() - 2 ; 0 <= i ; i--){
    bool ok = 1;
    s2 = s;

    s2[i + 1] = s[i + 1] + 1;

    if(s[i] == s2[i + 1])
      s2[i + 1]++;
    if(s[i - 1] == s2[i + 1])
      s2[i + 1]++;
    if(s[i] == s2[i + 1])
      s2[i + 1]++;

    for(int j = i + 2 ; j <= s.size() - 1 ; j++){
      s2[j] = 'a';

      if(s2[j - 1] == s2[j])
        s2[j]++;
      if(s2[j - 2] == s2[j])
        s2[j]++;
      if(s2[j - 1] == s2[j])
        s2[j]++;
    }

    for(int j = 1 ; j < s2.size() ; j++){
      if('a' + p <= s2[j]){
        ok = 0;
      }
    }
    if(ok == 1) {
      for(int j = 1 ; j < s2.size() ; j++)
        cout << s2[j];
      return 0;
    }
  }
  cout << "NO";
  return 0;
}