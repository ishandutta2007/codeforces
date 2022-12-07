#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define mp make_pair
#define maxn 1005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int query(int x,int y,int xx,int yy){
  printf("? %d %d %d %d\n",x,y,xx,yy);
  fflush(stdout);
  int res;
  scanf("%d",&res);
  if(res == -1) exit(0);
  return res;
}
void print(int x,int y,int xx,int yy){
  printf("! %d %d %d %d\n",x,y,xx,yy);
  fflush(stdout);
}
vector <P> ans;
void row_check(int r){
  int lb = 1,rb = n;
  while(lb < rb){
    int mid = (lb + rb) >> 1;
    if(query(r,lb,r,mid) & 1) rb = mid;
    else lb = mid + 1;
  }
  ans.push_back(mp(r,lb));
}
bool try_row(){
  vector <int> odd;
  for(int i = 1;i < n;i++){
    int x = query(i,1,i,n);
    if(x & 1) odd.push_back(i);
  }
  if(!odd.size()) return false;
  if((int)odd.size() == 1) odd.push_back(n);
  row_check(odd[0]);
  row_check(odd[1]);
  return true;
}
void col_check(int c){
  int lb = 1,rb = n;
  while(lb < rb){
    int mid = (lb + rb) >> 1;
    if(query(lb,c,mid,c) & 1) rb = mid;
    else lb = mid + 1;
  }
  ans.push_back(mp(lb,c));
}
void try_col(){
  vector <int> odd;
  for(int i = 1;i < n;i++){
    int x = query(1,i,n,i);
    if(x & 1) odd.push_back(i);
  }
  if((int)odd.size() == 1) odd.push_back(n);
  col_check(odd[0]);
  col_check(odd[1]);
}
int main(){
  scanf("%d",&n);
  if(!try_row()) try_col();
  print(ans[0].first,ans[0].second,ans[1].first,ans[1].second);
  return 0;
}