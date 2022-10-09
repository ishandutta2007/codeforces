#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

bool ispal(string s){
  int i = 0, j = s.size() - 1;
  while(i < j){
    if(s[i] != s[j])
      return 0;
    i++;
    j--;
  }
  return 1 ;
}

int main()
{
  string s;
  cin >> s;
  bool ok = 1;
  for(int i = 1 ; i < s.size() / 2 ; i++){
    if(s[i] != s[i - 1]) {
      ok = 0;
    }
  }
  if(ok == 1)
    cout << "Impossible";
  else {
    for(int i = 1 ; i < s.size() ; i++){
      string s2 = s.substr(i, s.size() - i) +  s.substr(0, i);
      if(s != s2)
        if(ispal(s2) == 1) {
          cout << 1;
          return 0;
        }
    }
    cout << 2;
  }
  return 0;
}