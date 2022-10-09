#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char rev(char s){
  return '0' + (1 - (s - '0'));
}

int main()
{
  string s, s2;
  cin >> s;
  int n = s.size();
  s = "#" + s;
  s2 = s;

  int x = (n - 2) / 2 + (n - 2) % 2, y = n - 2 - x, emp = 0;
  int ones = 0, zeros = 0;
  for(int i = 1;i <= n; i++){
    if(s[i] == '?')
      emp++;
    else if(s[i] == '0')
      zeros++;
    else if(s[i] == '1')
      ones++;
  }

  vector<string> v;
  for(int i = 0; i <= emp; i++){
    int ones2 = ones + i;
    int zeros2 = zeros + (emp - i);

    if(ones2 <= x)
      v.push_back({"00"});
    else if(zeros2 <= y)
      v.push_back({"11"});
    else {
      if(s[n] == '?') {
        if(i < emp)
          v.push_back("10");
        else
          v.push_back("01");
      } else {
        string result;
        result += rev(s[n]);
        result += s[n] ;
        v.push_back(result) ;
      }
    }
  }

  for(int i = 0; i <= emp; i++){
    int ones2 = ones + (emp - i);
    int zeros2 = zeros + i;
    if(ones2 <= x)
      v.push_back({"00"});
    else if(zeros2 <= y)
      v.push_back({"11"});
    else {
      if(s[n] == '?') {
        if(i < emp)
          v.push_back("01");
        else
          v.push_back("10");
      } else {
        string result;
        result += rev(s[n]);
        result += s[n] ;
        v.push_back(result) ;
      }
    }
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << '\n';

  return 0;
}