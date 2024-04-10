#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 200005

using namespace std;
typedef long long ll;

char t[maxn];
int n, q;
vector <int> pos0;
namespace SA{
  int s[maxn];
  int l, m, k, sa[maxn], rk[maxn << 1], tmp[maxn], cnt[maxn], id[maxn];
  int lcp[18][maxn];
  void append(char c) {
    s[++l] = c;
  }
  void calc_sa() {
    for(int i = 1;i <= l;i++) cnt[rk[i] = s[i]]++;
    for(int i = 1;i <= 2;i++) cnt[i] += cnt[i - 1];
    for(int i = l;i >= 1;i--) sa[cnt[rk[i]]--] = i;
    m = 0;
    for(int i = 1;i <= l;i++){
      if(rk[sa[i]] == rk[sa[i - 1]]) tmp[sa[i]] = m;
      else tmp[sa[i]] = ++m;
    }
    memcpy(rk,tmp,sizeof(tmp));
    for(int w = 1;m < l;w <<= 1){
      k = 0;
      for(int i = l;i > l - w;i--) id[++k] = i;
      for(int i = 1;i <= l;i++) if(sa[i] > w) id[++k] = sa[i] - w;
      memset(cnt,0,sizeof(cnt));
      for(int i = 1;i <= l;i++) cnt[rk[i]]++;
      for(int i = 1;i <= m;i++) cnt[i] += cnt[i - 1];
      for(int i = l;i >= 1;i--) sa[cnt[rk[id[i]]]--] = id[i];
      m = 0;
      for(int i = 1;i <= l;i++){
        if(rk[sa[i]] == rk[sa[i - 1]] && rk[sa[i] + w] == rk[sa[i - 1] + w]){
          tmp[sa[i]] = m;
        }else{
          tmp[sa[i]] = ++m;
        }
      }
      memcpy(rk,tmp,sizeof(tmp));
    }
  }
  void calc_lcp(){
    k = 0;
    for(int i = 1;i <= l;i++){
      if(k) k--;
      while(s[i + k] == s[sa[rk[i] - 1] + k]) k++;
      lcp[0][rk[i]] = k;
    }
    for (int i = 1; i <= 17; i++) {
      for (int j = 1; j + (1 << i) - 1 <= l; j++) {
        lcp[i][j] = min(lcp[i - 1][j], lcp[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  void work(){ calc_sa(); calc_lcp(); }
  int LCP(int x, int y) {
    if(x == y) return l - x + 1;
    x = rk[x], y = rk[y];
    if (x > y) swap(x, y);
    ++x;
    if (x == y) return lcp[0][x];
    int ro = 31 - __builtin_clz(y - x);
    return min(lcp[ro][x], lcp[ro][y - (1 << ro) + 1]);
  }
  bool same(int l1, int r1, int l2, int r2) {
    if(r1 - l1 != r2 - l2) return false;
    return LCP(l1, l2) >= r1 - l1 + 1;
  }
}
bool solve(int l1, int l2, int len) {
  int r1 = l1 + len - 1, r2 = l2 + len - 1, pos0_l1, pos0_r1, pos0_l2, pos0_r2;
  pos0_l1 = lower_bound(pos0.begin(), pos0.end(), l1) - pos0.begin() + 1;
  pos0_r1 = upper_bound(pos0.begin(), pos0.end(), r1) - pos0.begin();
  pos0_l2 = lower_bound(pos0.begin(), pos0.end(), l2) - pos0.begin() + 1;
  pos0_r2 = upper_bound(pos0.begin(), pos0.end(), r2) - pos0.begin();
  if((pos0_r1 - pos0_l1) ^ (pos0_r2 - pos0_l2)) return false;
  if(pos0_l1 > pos0_r1) return true;
  if(((pos0[pos0_l1 - 1] - l1) ^ (pos0[pos0_l2 - 1] - l2)) & 1) return false;
  if(pos0_l1 == pos0_r1) return true;
  return SA::same(pos0_l1, pos0_r1 - 1, pos0_l2, pos0_r2 - 1);
}
int main() {
  scanf("%d", &n);
  scanf("%s", t + 1);
  for (int i = 1; i <= n; i++) {
    if (t[i] == '0') pos0.push_back(i);
  }
  for (int i = 0; i < (int)pos0.size() - 1; i++) {
    SA::append(((pos0[i + 1] - pos0[i]) & 1) + 1);
  }
  SA::work();
  scanf("%d", &q);
  while (q--) {
    int l1, l2, len;
    scanf("%d%d%d", &l1, &l2, &len);
    puts(solve(l1, l2, len) ? "Yes" : "No");
  }
  return 0;
}