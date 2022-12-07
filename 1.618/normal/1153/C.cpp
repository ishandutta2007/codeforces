#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 300005
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n,f[maxn];
char s[maxn],t[maxn];
int main(){
  scanf("%d",&n);
  scanf("%s",s + 1);
  if(n & 1){
    puts(":(");
    return 0;
  }
  int cntl = (n >> 1), cntr = (n >> 1), sum = 0;
  for(int i = 1;i <= n;i++){
    if(s[i] == '(') cntl--;
    else if(s[i] == ')') cntr--;
  }
  if(cntl < 0 || cntr < 0){
    puts(":(");
    return 0;
  }
  for(int i = 1;i <= n;i++){
    if(s[i] == '('){
      t[i] = '(';
      sum++;
    }else if(s[i] == ')'){
      t[i] = ')';
      sum--;
    }else{
      if(cntl){
        t[i] = '(';
        cntl--;
        sum++;
      }else{
        t[i] = ')';
        cntr--;
        sum--;
      }
    }
    if(sum < 0 || (i < n && sum == 0)){
      puts(":(");
      return 0;
    }
  }
  printf("%s",t + 1);
  return 0;
}