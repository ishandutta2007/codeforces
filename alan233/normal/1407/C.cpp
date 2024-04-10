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
int a[10001],n;
int ask(int x,int y){
  printf("? %d %d\n",x,y);
  fflush(stdout);
  int _;scanf("%d",&_);
  return _;
}
int main(){
  scanf("%d",&n);
  int i,j;
  for(i=2,j=1;i<=n;i++){
    int p1=ask(i,j),p2=ask(j,i);
    if(p1<p2){
      a[j]=p2;
      j=i;
    }else{
      a[i]=p1;
    }
  }
  a[j]=n;
  printf("!");
  for(int i=1;i<=n;i++)printf(" %d",a[i]);
  puts("");
  fflush(stdout);
  return 0;
}