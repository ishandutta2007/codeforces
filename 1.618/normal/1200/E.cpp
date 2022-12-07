#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 1000005

using namespace std;
typedef long long ll;
typedef unsigned int uint;

const uint B = 131;
const uint mod1 = 1998585857, mod2 = 1234567679;

char s[maxn], t[maxn];
int m, n;
uint h1[maxn], powB1[maxn], ht1, h2[maxn], powB2[maxn], ht2;
void append(char x){
  s[++n] = x;
  h1[n] = ((ll)h1[n - 1] * B + x) % mod1;
  h2[n] = ((ll)h2[n - 1] * B + x) % mod2;
  powB1[n] = (ll)powB1[n - 1] * B % mod1;
  powB2[n] = (ll)powB2[n - 1] * B % mod2;
}
uint get1(int l, int r){
  return (h1[r] - (ll)h1[l - 1] * powB1[r - l + 1] % mod1 + mod1) % mod1;
}
uint get2(int l, int r){
  return (h2[r] - (ll)h2[l - 1] * powB2[r - l + 1] % mod2 + mod2) % mod2;
}
int main(){
  scanf("%d", &m);
  powB1[0] = powB2[0] = 1;
  for(int i = 1;i <= m;i++){
    scanf("%s", t + 1);
    int l = strlen(t + 1);
    ht1 = ht2 = 0;
    int pos = 1;
    for(int j = 1;j <= min(n, l);j++){
      ht1 = ((ll)ht1 * B + t[j]) % mod1;
      ht2 = ((ll)ht2 * B + t[j]) % mod2;
      if(get1(n - j + 1, n) == ht1 && get2(n - j + 1,n) == ht2)
        pos = j + 1;
    }
    for(int j = pos;j <= l;j++) append(t[j]);
  }
  printf("%s", s + 1);
  return 0;
}