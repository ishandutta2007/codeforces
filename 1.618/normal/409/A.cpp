#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;

char s[25], t[25];
int n, val[135], ans, win[3][3];
int main(){
  val['8'] = 0, val['['] = 1, val['('] = 2;
  win[0][1] = win[1][2] = win[2][0] = 1;
  win[1][0] = win[2][1] = win[0][2] = -1;
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1);
  for(int i = 1;i <= n;i += 2){
    ans += win[val[s[i]]][val[t[i]]];
  }
  if(ans > 0) puts("TEAM 1 WINS");
  else if(ans < 0) puts("TEAM 2 WINS");
  else puts("TIE");
  return 0;
}