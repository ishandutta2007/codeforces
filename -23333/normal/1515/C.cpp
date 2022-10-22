#include <bits/stdc++.h>
#define N 200009
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
const int maxn=1000000;
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
}a[N];
struct cmp{
bool operator () (re x,re y)
{
	if (x.a!=y.a) return x.a<y.a;
	return x.b<y.b;
}
};
int p[N];
multiset<re,cmp> S;
map<int,int> gg;
bool cmp1(re x,re y)
{
	return x.a<y.a;
}
map<pair<int,int>,int> M;
int main()
{ 
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while (T--)
   {
   	int n,m,k;
   	cin>>n>>m>>k;
   	rep(i,1,n) cin>>a[i].a,a[i].b=i;
   	sort(a+1,a+n+1,cmp1);
   	rep(i,1,m)
   	{
   	  	S.insert((re){a[i].a,i}); p[a[i].b]=i;
   	}
   	rep(i,m+1,n)
   	{
   		auto it=S.begin();
   		p[a[i].b]=(*it).b;
   		re gg=(re){(*it).a+a[i].a,(*it).b};
   		S.erase(it);
   		S.insert(gg);
   	}
   	S.clear();
   	cout<<"YES"<<endl; 
   	rep(i,1,n) cout<<p[i]<<" ";
   	cout<<endl;
   }
   return 0;
}