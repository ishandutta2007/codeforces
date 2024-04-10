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
const int mod=1000000007; 
int sz[N],n,delta;
int qpow(int a,int b=mod-2){
  int res=1;
  while(b>0){
    if(b&1)res=1ll*res*a%mod;
    a=1ll*a*a%mod,b>>=1;
  }
  return res;
}
int f(int x){
  return (1ll*delta*qpow(2,x)-delta)%mod; 
}
int main(){
  srand(time(NULL));
  n=read(),delta=rand()+1;
  for(int i=1;i<=n;i++){
    int fa=read();
    if(fa!=-1)sz[fa]++;
  }
  int ans=0;
  for(int i=1;i<=n;i++)ans=(ans+f(sz[i]))%mod;
  ans=(f(n-1)-ans+mod)%mod;
  printf("%d\n",1ll*ans*qpow(delta)%mod); 
  return 0;
}