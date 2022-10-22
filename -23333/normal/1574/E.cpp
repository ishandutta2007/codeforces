//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
const int mo=998244353;
ll fsp(int x,int y)
{
	if (y==0) return 1;
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
#define mp make_pair
const int N=1.1e6;
int g1[N][2][3],h1[N],tg1,tg2,ans1=1,ans2=1;
int h[N][3],h2[N],bj[2][3];
map<pair<int,int>,int> M; 
int n,m,k;
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>m>>k;
   rep(i,1,n) ans1=ans1*2%mo,h1[i]=2;
   rep(i,1,m) ans2=ans2*2%mo,h2[i]=2;
   rep(i,1,k)
   {
     int x,y,z;
   	 cin>>x>>y;
   	 z=M[mp(x,y)];
   	 g1[x][y%2][z]--;
   	 if (h1[x]) ans1=ans1*fsp(h1[x],mo-2)%mo;
   	 else tg1--;
   	 int gg;
   	 if (x%2==0&&z) gg=3-z; else gg=z;
   	 h[y][gg]--;
   	 bj[y%2][gg]--;
   	 if (h2[y]) ans2=ans2*fsp(h2[y],mo-2)%mo;
   	 else tg2--;
   	 cin>>z;
   	 if (z==-1) z=0; else if (z==0) z=2; 
   	 M[mp(x,y)]=z;
   	 g1[x][y%2][z]++;
   	 h1[x]=0;
   	 if (!g1[x][0][2]&&!g1[x][1][1]) h1[x]++;
   	 if (!g1[x][0][1]&&!g1[x][1][2]) h1[x]++;
   	 if (h1[x]) ans1=ans1*h1[x]%mo;
   	 else tg1++;
   	 if (x%2==0&&z) gg=3-z; else gg=z;
   	 h[y][gg]++;
   	 bj[y%2][gg]++;
   	 h2[y]=0;
   	 if (!h[y][1]) h2[y]++;
   	 if (!h[y][2]) h2[y]++;
   	 if (h2[y]) ans2=ans2*h2[y]%mo;
   	 else tg2++;
   	 ll now=0;
   	 if (!tg1)
   	 {
   	 	now+=ans1;
   	 }
   	 if (!tg2)
   	 {
   	 	now+=ans2;
   	 	if (!bj[0][1]&&!bj[1][2]) now--;
   	 	if (!bj[0][2]&&!bj[1][1]) now--;
   	 }
   	 now=(now%mo+mo)%mo;
   	 cout<<now<<endl;
   }
   return 0;
}