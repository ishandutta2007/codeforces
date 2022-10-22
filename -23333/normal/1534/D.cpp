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
const int N=3000;
bool p[N];
int a[N];
map<pair<int,int>,bool> M; 
vector<re> ve;
queue<int> q;
int main()
{
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   cout<<"?"<<" "<<1<<endl;
   int cnt1=0,cnt2=0; p[1]=1;
   rep(i,1,n)
	{ 
	  cin>>a[i];
	  if (a[i]%2==0) cnt1++; else cnt2++;
      if (a[i]==1&&M[make_pair(1,i)]==0)
      {
      	M[make_pair(1,i)]=M[make_pair(i,1)]=1;
      	ve.push_back((re){1,i});
      }
    }
   if (cnt1>cnt2)
   {
   	 rep(i,1,n) if (a[i]%2==1) q.push(i);
   } else
   {
   	rep(i,2,n) if(a[i]%2==0) q.push(i); 
   }
   while (!q.empty())
   {
   	int x=q.front(); q.pop();
   	if (p[x]) continue; p[x]=1;
   	cout<<"?"<<" "<<x<<endl;
   	rep(i,1,n)
	{ 
	  cin>>a[i];
      if (a[i]==1&&M[make_pair(x,i)]==0)
      {
      	M[make_pair(x,i)]=M[make_pair(i,x)]=1;
      	ve.push_back((re){x,i});
      }
    }
   }
   cout<<"!"<<endl;
   for(auto v:ve)
   {
   	cout<<v.a<<" "<<v.b<<endl;
   }
   return 0;
}