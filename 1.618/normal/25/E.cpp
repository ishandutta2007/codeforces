#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 100005

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull B = 23333ull;

bool contain(string s, string t){// t in s?
  if(s.size() < t.size()) return false;
  ll ht = 0, hs = 0, powB = 1;
  for(int i = 0;i < (int)t.size();i++){
    hs = hs * B + s[i];
    ht = ht * B + t[i];
    powB *= B;
  }
  if(hs == ht) return true;
  for(int i = t.size();i < (int)s.size();i++){
    hs = hs * B + s[i];
    hs -= powB * s[i - t.size()];
    if(hs == ht) return true;
  }
  return false;
}
int match(string s, string t){
  ull hs = 0, powB = 1, ht = 0;
  int n = min(s.size(), t.size()), len = 0;
  for(int i = 0;i < n;i++){
    ht = ht * B + t[i];
    hs += s[(int)s.size() - i - 1] * powB;
    powB *= B;
    if(hs == ht) len = i + 1;
  }
  return len;
}
vector <string> s, t;
int main(){
//  cout << contain("abcde", "bcd") << endl;
  s.resize(3);
  cin >> s[0] >> s[1] >> s[2];
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  for(int i = 0;i < (int)s.size();i++){
    bool ok = true;
    for(int j = 0;j < (int)s.size();j++){
      if(i != j && contain(s[j], s[i])) ok = false;
    }
    if(ok) t.push_back(s[i]);
  }
  int ans = 300000;
  do{
    int res = t[0].size();
    for(int i = 1;i < (int)t.size();i++)
      res += t[i].size() - match(t[i - 1], t[i]);
    ans = min(ans, res);
  }while(next_permutation(t.begin(), t.end()));
  printf("%d\n", ans);
  return 0;
}
/*
bcd
abcde
xyzab

8
*/