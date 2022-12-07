#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 505
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,k,a[maxn];
int query1(){
  vector <int> q;
  for(int i = 1;i <= n;i++){
    if(a[i] == -1){
      q.push_back(i);
      if((int)q.size() == k) break;
    }
  }
  printf("? ");
  for(int i = 0;i < k;i++) printf("%d%c",q[i],i == k - 1 ? '\n' : ' ');
  fflush(stdout);
  int pos,val;
  scanf("%d%d",&pos,&val);
  if(pos == -1) return -1;
  a[pos] = val;
  return val;
}
int pos1,pos2;
vector <int> bad;
int query2(int x){
  vector <int> q;
  for(int i = 0;i < k - 1;i++) if(i != x) q.push_back(bad[i]);
  q.push_back(pos1);
  q.push_back(pos2);
  printf("? ");
  for(int i = 0;i < k;i++) printf("%d%c",q[i],i == k - 1 ? '\n' : ' ');
  fflush(stdout);
  int pos,val;
  scanf("%d%d",&pos,&val);
  if(pos == -1) return -1;
  if(pos == pos1) a[bad[x]] = 1000000000;
  else a[bad[x]] = 0;
  return val;
}
void solve(){
  memset(a,-1,sizeof(a));
  scanf("%d%d",&n,&k);
  int mth_val = query1();
  if(mth_val == -1) return;
  for(int i = 2;i <= n - k + 1;i++) if(query1() == -1) return;
  for(int i = 1;i <= n;i++){
    if(a[i] == -1) bad.push_back(i);
    else{
      if(!pos1) pos1 = i;
      else pos2 = i;
    }
  }
  if(a[pos1] > a[pos2]) swap(pos1,pos2);
  for(int i = 0;i < k - 1;i++) if(query2(i) == -1) return;
  sort(a + 1,a + k + 1);
  for(int i = 1;i <= k;i++) if(a[i] == mth_val){
    printf("! %d\n",i);
    fflush(stdout);
  }
}
int main(){
  solve();
  return 0;
}