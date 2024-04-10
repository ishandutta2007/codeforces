// Author: wlzhouzhuan
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N=100005;

char a[N];int n;
vector<int>xay_path[N];int ans;
vector<int>xay5[2];

vector<vector<int>>kind[2][2];
void solve(){
  rep(i,1,ans){
    kind[a[xay_path[i][0]]][a[xay_path[i].back()]].pb(xay_path[i]);
  }
  while(SZ(kind[0][0])&&SZ(kind[1][1])){
    vector<int>new_path;
    for(auto v:kind[0][0].back())new_path.pb(v);
    for(auto v:kind[1][1].back())new_path.pb(v);
    kind[0][0].pop_back(),kind[1][1].pop_back();
    kind[0][1].pb(new_path);
  }
  vector<int>a01,a10;
  for(auto k1:kind[0][1])for(auto k2:k1)a01.pb(k2);
  for(auto k1:kind[1][0])for(auto k2:k1)a10.pb(k2);
  if(SZ(a01)&&SZ(a10)){
    if(a01.back()<a10.back())swap(a01,a10);
    a10.pb(a01.back()),a01.pop_back();
    for(auto v:a10)a01.pb(v);
    a10.clear();
  }else if(SZ(a01)||SZ(a10)){
    if(SZ(a10))a01=a10,a10.clear();
  }
  vector<int>sp;
  if(SZ(kind[0][0]))sp=kind[0][0][0];
  if(SZ(kind[1][1]))sp=kind[1][1][0];
  if(SZ(sp)){
    if(!SZ(a01))a01=sp;
    else{
      if(a[sp.back()]!=a[a01.back()]){
        for(auto v:sp)a01.pb(v);
        sp.clear();
      }else{
        for(auto v:a01)sp.pb(v);
        a01=sp,sp.clear();
      }
    }
  }
  for(auto v:a01)printf("%d ",v);
  puts("");
}
int main() {
  scanf("%s",a+1);  
  n=strlen(a+1);
  rep(i,1,n){
    int type;
    if(a[i]=='L')a[i]=type=0;else a[i]=type=1;
    if(SZ(xay5[type^1])){
      xay_path[xay5[type^1].back()].pb(i);
      xay5[type].pb(xay5[type^1].back());
      xay5[type^1].pop_back();
    }else{
      ++ans;
      xay_path[ans].pb(i);
      xay5[type].pb(ans);
    }
  }
  printf("%d\n",ans-1);
  solve();
  return 0;
}