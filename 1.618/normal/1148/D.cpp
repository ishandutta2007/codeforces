#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define mp make_pair
#define maxn 300005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
struct node{
  int a,b,id;
  node(int a = 0,int b = 0,int id = 0): a(a), b(b), id(id) {}
  bool operator < (const node &x){
    return b > x.b;
  }
};
vector <node> up, down;
int n,n1,n2;
int main(){
  n = getint();
  for(int i = 1;i <= n;i++){
    int a = getint(), b = getint();
    if(a < b) up.push_back(node(a,b,i));
    else down.push_back(node(a,b,i));
  }
  n1 = up.size(), n2 = down.size();
  if(n1 >= n2){
    sort(up.begin(),up.end());
    printf("%d\n",n1);
    for(int i = 0;i < (int)up.size();i++){
      printf("%d ",up[i].id);
    }
    printf("\n");
  }else{
    printf("%d\n",n2);
    sort(down.begin(),down.end());
    for(int i = (int)down.size() - 1;i >= 0;i--){
      printf("%d ",down[i].id);
    }
    printf("\n");
  }
  return 0;
}