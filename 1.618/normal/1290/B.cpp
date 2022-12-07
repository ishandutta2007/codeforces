#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 200005

using namespace std;
typedef long long ll;

char s[maxn];
int n, q, cnt[27][maxn];
bool query(int l, int r){
  if(l == r) return true;
  if(s[l] != s[r]) return true;
  for(int i = 0;i < 26;i++){
    for(int j = i + 1;j < 26;j++){
      if(cnt[i][r] - cnt[i][l - 1] + cnt[j][r] - cnt[j][l - 1] == r - l + 1)
        return false;
    }
  }
  return true;
}
int main(){
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for(int i = 1;i <= n;i++){
    for(int j = 0;j < 26;j++){
      cnt[j][i] = cnt[j][i - 1] + (s[i] == 'a' + j);
    }
  }
  scanf("%d", &q);
  for(int i = 1;i <= q;i++){
    int l, r;
    scanf("%d%d", &l, &r);
    puts(query(l, r) ? "Yes" : "No");
  }
  return 0;
}