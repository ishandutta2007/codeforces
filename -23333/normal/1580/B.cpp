#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
//#include <immintrin.h>
//#include <emmintrin.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int

//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//mt19937 myrand(seed);
//uniform_int_distribution<ll>dist(1,10000000);
//dist(myrand);
inline ll rd(){
	ll x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
	return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T>void maxa(T &x,T y)
{
	if (y>x) x=y;
}
template<class T>void mina(T &x,T y)
{
	if (y<x) x=y;
}
template<class T>void read(T &x)
{
	int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
	while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
}
const int mo=1e9+7;
ll fsp(int x,int y)
{
	if (y==1) return x;
	ll ans=fsp(x,y/2);
	ans=ans*ans%mo;
	if (y%2==1) ans=ans*x%mo;
	return ans;
}
struct cp {
	ll x,y;
	cp operator +(cp B)
	{
		return (cp){x+B.x,y+B.y};
	}
	cp operator -(cp B)
	{
		return (cp){x-B.x,y-B.y};
	}
	ll operator *(cp B)
	{
		return x*B.y-y*B.x;
    }
    int half() { return y < 0 || (y == 0 && x < 0); }
};
struct re{
	int a,b,c;
};
ll dp[110][110][110];
bool t[110][110][110];
int C[110][110],jc[110];
   int n,m,k,p;
ll dfs(int i,int j,int k)
{
	if(n==0){
		if(k==0) return dp[n][m][k]=1;
		else return dp[n][m][k]=0;
	}
	if(m==0){
		if(k==0) return dp[n][m][k]=1;
		else return dp[n][m][k]=0;
	}
	if(m==1){
		if(k==1) return dp[n][m][k]=jc[n];
		else return dp[n][m][k]=0;
	}
	if (i<=1||t[i][j][k]) return dp[i][j][k];
	if (j<0) return 0;
	if (k==0&&(j>i||j==0)) return jc[i];
	if (j+k>i+1) return 0;
	t[i][j][k]=1;
	if (j!=1)
       	 {
           rep(i1,0,i-1)
           rep(k1,0,k)
           {
             if (p>5000) dp[i][j][k]+=dfs(i1,j-1,k1)*dfs(i-i1-1,j-1,k-k1)%p*C[i-1][i1]%p;
             else dp[i][j][k]+=dfs(i1,j-1,k1)*dfs(i-i1-1,j-1,k-k1)*C[i-1][i1];
           } 
		 }else
         {
           rep(i1,0,i-1)
           rep(k1,0,k-1)	
           {
             if (p>5000) dp[i][j][k]+=dfs(i1,j-1,k1)*dfs(i-i1-1,j-1,k-k1-1)%p*C[i-1][i1]%p;
             else dp[i][j][k]+=dfs(i1,j-1,k1)*dfs(i-i1-1,j-1,k-k1-1)*C[i-1][i1];
           }
	     }
         dp[i][j][k]%=p;
    return dp[i][j][k];
}
int main()
{
   ios::sync_with_stdio(false);

   cin>>n>>m>>k>>p;
   rep(i,0,100)
   {
   	 C[i][0]=1;
     rep(j,1,i)
       C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
   }
   jc[0]=1;
   rep(i,1,100) jc[i]=1ll*jc[i-1]*i%p;
   rep(i,0,n) dp[0][i][0]=1;
   rep(i,1,n) dp[i][0][0]=jc[i];
   rep(i,1,1)
     rep(j,1,n)
       rep(k,0,n)
       {
       	 if (j!=1)
       	 {
           rep(i1,0,i-1)
           rep(k1,0,k)
           {
             dp[i][j][k]+=dp[i1][j-1][k1]*dp[i-i1-1][j-1][k-k1]%p*C[i-1][i1]%p;
           } 
		 }else
         {
           rep(i1,0,i-1)
           rep(k1,0,k-1)	
           {
             dp[i][j][k]+=dp[i1][j-1][k1]*dp[i-i1-1][j-1][k-k1-1]%p*C[i-1][i1]%p;
           }
	     }
         dp[i][j][k]%=p; 
       }
   cout<<dfs(n,m,k)<<endl;
   return 0;
}