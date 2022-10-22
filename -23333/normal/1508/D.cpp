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
const int N=5e5;
struct cp {
	ll x,y;
	int id;
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
}p[N];
int fa[N],c[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]); 
}
bool cmpp1(cp x,cp y)
{
	return x.x==y.x?x.y<y.y:x.x<y.x;
}
bool cmpp2(cp x,cp y)
{
    int f1=(x-p[1]).half(),f2=(y-p[1]).half();
    if (f1!=f2) return f1<f2;
	return (x-p[1])*(y-p[1])>=0;
}
struct re{
	int a,b,c;
};
int n;
vector<re> now;
int main()
{
   ios::sync_with_stdio(false);
   cin>>n;
   rep(i,1,n)
   {
   	 cin>>p[i].x>>p[i].y>>c[i];
   	 p[i].id=i;
   }
   rep(i,1,n) fa[i]=i;
   int pp=0;
   rep(i,1,n)
   {
      int f1=find(c[i]),f2=find(i);
      if (f1!=f2)
      {
      	fa[f1]=f2;
      	pp=i;
      }
   }
   if (!pp)
   {
   	 cout<<0<<endl;
   	 return 0;
   }
   if (pp!=1)
   {
   	 swap(p[1],p[pp]);
   }
  // sort(p+2,p+n+1,cmpp1);
   sort(p+2,p+n+1,cmpp2);
   rep(i,1,n) cerr<<p[i].x<<" "<<p[i].y<<endl;
   cerr<<endl; 
   rep(i,2,n)
   {
   	int x=i,y=i%n+1;
   	if (y==1) y=2;
   	int f1=find(p[x].id),f2=find(p[y].id);
   	if (find(f1)!=find(f2)&&(p[x]-p[1])*(p[y]-p[1])>=0)
   	{
   		fa[f1]=f2;
   		swap(c[p[x].id],c[p[y].id]);
		now.push_back((re){p[x].id,p[y].id});
   	}
   }
   int f=pp;
   while(c[f]!=f)
   {
   	 now.push_back((re){f,c[f]});
	 swap(c[c[f]],c[f]);
   }
   cout<<now.size()<<endl;
   for(auto i:now)
   {
   	cout<<i.a<<" "<<i.b<<endl;
   }
   return 0;
}