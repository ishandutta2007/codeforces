#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int k;
const char vowels[] = {'a','e','i','o','u','a','e','i','o'};
char s[6][6];
int main(){
  k = getint();
  for(int i = 0;i < 5;i++){
    for(int j = 0;j < 5;j++){
      s[i][j] = vowels[i + j];
    }
  }
  for(int i = 5;i * i <= k;i++){
    if(k % i == 0){
      int j = k / i;
      if(j >= 5){
        for(int k = 0;k < i;k++){
          for(int l = 0;l < j;l++){
            printf("%c",s[k % 5][l % 5]);
          }
//          printf("\n");
        }
        printf("\n");
        return 0;
      }
    }
  }
  puts("-1");
  return 0;
}