#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ld = long double;
using ll = long long;

int const sigma = 26;
int frec[1 + sigma];

bool valid(){
  for(int i = 0; i < sigma; i++)
    if(frec[i] < 0)
      return 0;
  return 1;
}

int main()
{
  string s, s2;
  cin >> s >> s2;
  if(s.size() < s2.size()){
    cout << 0;
    return 0;
  }
  for(int i = 0; i < s2.size(); i++)
    frec[s2[i] - 'a']++;
  int l = s2.size();
  for(int i = 0; i < l; i++){
    if(s[i] != '?')
      frec[s[i] - 'a']--;
  }
  int result = valid();
  for(int i = l; i < s.size(); i++){
    if(s[i] != '?')
      frec[s[i] - 'a']--;
    if(s[i - l] != '?')
      frec[s[i - l] - 'a']++;
    result += valid();
  }
  cout << result;
  return 0;
}