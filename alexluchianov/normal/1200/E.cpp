#include <iostream>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int const nmax = 1000000;
int pre[1 + nmax];

int longestsuff(string s){
  s = "#" + s;
  for(int i = 0; i < s.size(); i++){
    pre[i] = 0;
  }
  int pos = 2, ptr = 0;
  while(pos < s.size()){
    if(s[pos] == s[ptr + 1]){
      pre[pos] = ptr + 1;
      ++ptr;
      pos++;
    } else if(ptr == 0) {
      pre[pos] = 0;
      pos++;
    } else
      ptr = pre[ptr];
  }
  return pre[s.size() - 1];
}

int main()
{
  int n;
  cin >> n;
  string printed;
  string last;
  cin >> printed;
  for(int i = 2;i <= n; i++){
    string s;
    cin >> s;
    int start = printed.size() - s.size();
    string sol = s + "|" + printed.substr(max(0, start), printed.size() - max(0, start));
    for(int j = longestsuff(sol); j < s.size(); j++)
      printed += s[j];
    last = s;
  }
  cout << printed;
  return 0;
}