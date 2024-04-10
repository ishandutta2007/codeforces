#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fir first
#define sec second
#define mset(s,t) memset(s,t,sizeof(s))
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int N=100005;
int mu[N],n,q;
vector<int>pr;
bool vis[N];
bitset<7001>a[N],g[7005],ys[7005];
void init(int n){
  mu[1]=1;
  for(int i=2;i<=n;i++){
    if(!vis[i])pr.pb(i),mu[i]=1;
    for(auto v:pr){
      if(i*v>n)break;
      vis[i*v]=1;
      if(i%v==0)break;
      mu[i*v]=mu[i];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j+=i){
      if(mu[j/i])g[i].set(j);
      ys[j].set(i);
    }
  }
}
int main(){
  init(7000);
  n=read(),q=read();
  while(q--){
    int opt=read(),x=read(),y=read();
    if(opt==1){
      a[x]=ys[y];
    }else if(opt==2){
      int z=read();
      a[x]=a[y]^a[z];
    }else if(opt==3){
      int z=read();
      a[x]=a[y]&a[z];
    }else{
      int cnt=(a[x]&g[y]).count();
      putchar(cnt%2?'1':'0');
    }
  }
  return 0;
}