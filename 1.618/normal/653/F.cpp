#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 500005

using namespace std;
typedef long long ll;

char s[maxn];
int n, m, k, sa[maxn], rk[maxn << 1], tmp[maxn], id[maxn], cnt[maxn];
int lcp[maxn];
void calc_sa(){
  m = ')';
  for(int i = 1;i <= n;i++) cnt[rk[i] = s[i]]++;
  for(int i = 1;i <= m;i++) cnt[i] += cnt[i - 1];
  for(int i = n;i >= 1;i--) sa[cnt[rk[i]]--] = i;
  m = 0;
  for(int i = 1;i <= n;i++){
    if(rk[sa[i]] == rk[sa[i - 1]]) tmp[sa[i]] = m;
    else tmp[sa[i]] = ++m;
  }
  memcpy(rk, tmp, sizeof(tmp));
  for(int w = 1;m < n;w <<= 1){
    k = 0;
    for(int i = n;i > n - w;i--) id[++k] = i;
    for(int i = 1;i <= n;i++) if(sa[i] > w) id[++k] = sa[i] - w;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1;i <= n;i++) cnt[lcp[i] = rk[id[i]]]++;
    for(int i = 1;i <= m;i++) cnt[i] += cnt[i - 1];
    for(int i = n;i >= 1;i--) sa[cnt[lcp[i]]--] = id[i];
    m = 0;
    for(int i = 1;i <= n;i++){
      if(rk[sa[i]] == rk[sa[i - 1]] && rk[sa[i] + w] == rk[sa[i - 1] + w]){
        tmp[sa[i]] = m;
      }else{
        tmp[sa[i]] = ++m;
      }
    }
    memcpy(rk, tmp, sizeof(tmp));
  }
}
void calc_lcp(){
  k = 0;
  for(int i = 1;i <= n;i++){
    if(k) k--;
    while(s[i + k] == s[sa[rk[i] - 1] + k]) k++;
    lcp[rk[i]] = k;
  }
}
int nxt[19][maxn], stk[maxn], num[maxn];
int main(){
  scanf("%d", &n);
  scanf("%s", s + 1);
  calc_sa();
  calc_lcp();
  k = 0;
  for(int i = n;i >= 1;i--){
    if(s[i] == ')') stk[++k] = i;
    else if(k){
      nxt[0][i] = stk[k--];
      num[i] = num[nxt[0][i] + 1] + 1;
    }
  }
  for(int i = 1;i <= 18;i++){
    for(int j = 1;j <= n;j++){
      if(nxt[i - 1][j]) nxt[i][j] = nxt[i - 1][nxt[i - 1][j] + 1];
    }
  }
  ll ans = 0;
  for(int i = 1;i <= n;i++){
    int j = i;
    for(k = 18;k >= 0;k--)
      if(nxt[k][j] && nxt[k][j] - i + 1 <= lcp[rk[i]]) j = nxt[k][j] + 1;
    ans += num[j];
  }
  printf("%I64d\n", ans);
  return 0;
}