#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
const int LEN = 100000;

struct fastio{
  int it,len;
  char s[LEN + 5];
  fastio(){
    it = len = 0;
  }
  char get(){
    if(it < len) return s[it++];
    it = 0, len = fread(s,1,LEN,stdin);
    return len ? s[it++] : EOF;
  }
  bool notend(){
    char c;
    for(c = get();c == ' ' || c == '\n';c = get());
    if(it) it--;
    return c != EOF;
  }
  void put(char c){
    if(it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush(){
    fwrite(s,1,it,stdout);
  }
}buff,bufo;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll(){
  char c; ll res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline void putint(int x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[15];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline void putll(ll x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[25];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline char get_char(){
  char c;
  for(c = buff.get();c == ' ' || c == '\n';c = buff.get());
  return c;
}
#define mp make_pair
typedef pair<int,int> P;
const int dx[] = {-1,-1,-1,0,1,1,1,0};
const int dy[] = {-1,0,1,1,1,0,-1,-1};
const int inf = 0x3f3f3f3f;
int n,m;
vector < vector<char> > grid,ans;
vector < vector<int> > maxt,dis;
// maxt[i][j] = real value + 1.
bool check(int t){
  queue <P> que;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      if(maxt[i][j] - 1 >= t){
        ans[i][j] = 'X';
        dis[i][j] = 0;
        que.push(mp(i,j));
      }else{
        ans[i][j] = '.';
        dis[i][j] = inf;
      }
    }
  }
  
//  for(int i = 1;i <= n;i++){
//    for(int j = 1;j <= m;j++){
//      cout << ans[i][j];
//    }
//    cout << endl;
//  }
//  system("pause");
  
  while(!que.empty()){
    P p = que.front(); que.pop();
    int x = p.first, y = p.second;
    for(int d = 0;d < 8;d++){
      int cx = x + dx[d], cy = y + dy[d];
      if(grid[cx][cy] == 'X' && dis[cx][cy] == inf){
        dis[cx][cy] = dis[x][y] + 1;
        que.push(mp(cx,cy));
      }
    }
  }
  
//  for(int i = 1;i <= n;i++){
//    for(int j = 1;j <= m;j++){
//      printf("%10d ",dis[i][j]);
//    }
//    printf("\n");
//  }
//  system("pause");
  
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      if(grid[i][j] == '.') continue;
      if(dis[i][j] > t) return false;
    }
  }
  return true;
}
int main(){
  n = getint(), m = getint();
  grid.resize(n + 2), maxt.resize(n + 2),
  dis.resize(n + 2), ans.resize(n + 2);
  for(int i = 1;i <= n;i++){
    grid[i].resize(m + 2), maxt[i].resize(m + 2),
    dis[i].resize(m + 2), ans[i].resize(m + 2);
    for(int j = 1;j <= m;j++) grid[i][j] = get_char();
  }
  grid[0].resize(m + 2), grid[n + 1].resize(m + 2);
  for(int i = 0;i <= n + 1;i++) grid[i][0] = grid[i][m + 1] = '.';
  for(int j = 0;j <= m + 1;j++) grid[0][j] = grid[n + 1][j] = '.';
  queue <P> que;
  
//  cout << "ok" << endl;
  
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      if(grid[i][j] == '.') continue;
      for(int d = 0;d < 8;d++){
        int cx = i + dx[d], cy = j + dy[d];
        if(grid[cx][cy] == '.'){
          maxt[i][j] = 1;
          que.push(mp(i,j));
        }
      }
    }
  }
  while(!que.empty()){
    P p = que.front(); que.pop();
    int x = p.first, y = p.second;
    for(int d = 0;d < 8;d++){
      int cx = x + dx[d], cy = y + dy[d];
      if(grid[cx][cy] == 'X' && !maxt[cx][cy]){
        maxt[cx][cy] = maxt[x][y] + 1;
        que.push(mp(cx,cy));
      }
    }
  }
  
//  for(int i = 1;i <= n;i++){
//    for(int j = 1;j <= m;j++){
//      cout << maxt[i][j] << " ";
//    }
//    cout << endl;
//  }
//  system("pause");
//  check(2);
  
  int lb = 0, rb = (min(n,m) + 1) / 2;
  while(lb < rb){
    int mid = (lb + rb + 1) >> 1;
    if(check(mid)) lb = mid;
    else rb = mid - 1;
  }
  putint(lb,'\n');
  check(lb);
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      bufo.put(ans[i][j]);
      if(j == m) bufo.put('\n');
    }
  }
  bufo.flush();
  return 0;
}