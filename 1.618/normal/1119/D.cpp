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
const ll infll = 0x3f3f3f3f3f3f3f3fll;
int n,q;
vector <ll> s;
ll sum[maxn];
int main(){
  scanf("%d",&n);
  s.resize(n);
  for(int i = 0;i < n;i++) scanf("%I64d",&s[i]);
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(),s.end()),s.end());
  for(int i = 0;i < (int)s.size() - 1;i++) s[i] = s[i + 1] - s[i] - 1;
  s[s.size() - 1] = infll;
  sort(s.begin(),s.end());
  for(int i = 0;i < (int)s.size();i++) sum[i + 1] = sum[i] + s[i];
  scanf("%d",&q);
  while(q--){
    ll l,r;
    scanf("%I64d%I64d",&l,&r);
    int pos = lower_bound(s.begin(),s.end(),r - l) - s.begin();
    printf("%I64d ",sum[pos] + ll(r - l) * (s.size() - pos) + s.size());
  }
  printf("\n");
  return 0;
}