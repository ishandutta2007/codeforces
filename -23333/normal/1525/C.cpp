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
const int N=5e5;
struct re{
	int a,b,id;
}a[N];
int ans[N],ans2[N];
stack<int> q1,q2,q3,q4;
bool cmp(re x,re y)
{
	return x.a<y.a;
}
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while(T--)
   {
   	int n,m;
   	cin>>n>>m;
   	rep(i,1,n) cin>>a[i].a;
   	rep(i,1,n)
   	{
   		char c;
   		cin>>c;
   		if(c=='R') a[i].b=1; else a[i].b=0;
   		a[i].id=i;
   	}
   	sort(a+1,a+n+1,cmp);
   	rep(i,1,n) ans[i]=-1;
   	rep(i,1,n)
   	  if (a[i].b==1)
   	  {
   	  	if (a[i].a%2==1) q1.push(i);
   	  	else q2.push(i);
   	  } else
   	  {
   	  	if(a[i].a%2==1)
   	  	{
   	  		if(!q1.empty())
   	  		{
   	  			int x=q1.top();
   	  			ans[x]=ans[i]=(a[i].a-a[x].a)/2;
   	  			q1.pop();
   	  		}
   	  	} else
   	  	{
   	  		if(!q2.empty())
   	  		{
   	  			int x=q2.top();
   	  			ans[x]=ans[i]=(a[i].a-a[x].a)/2;
   	  			q2.pop();
   	  		}
   	  	}
   	  }
   	  while (!q1.empty()) q1.pop();
   	  while (!q2.empty()) q2.pop();
   	  dep(i,n,1)
   	    if (a[i].b==1&&ans[i]==-1)
   	    {
   	    	if (a[i].a%2==1)
   	    	{
   	    	  if(!q1.empty())
   	  		  {  
   	  			int x=q1.top();
   	  			ans[x]=ans[i]=(2*m-(a[i].a+a[x].a))/2;
   	  			q1.pop();
   	  		  } else q1.push(i);
   	    	} else
   	    	{
   	    		if(!q2.empty())
   	  		    {  
   	  			  int x=q2.top();
   	  			  ans[x]=ans[i]=(2*m-(a[i].a+a[x].a))/2;
   	  			  q2.pop();
   	  		    } else q2.push(i);
   	    	}
   	    }
   	  while (!q1.empty()) q1.pop();
   	  while (!q2.empty()) q2.pop();
   	  rep(i,1,n)
   	    if (a[i].b==0&&ans[i]==-1)
   	    {
   	    	if (a[i].a%2==1)
   	    	{
   	    	  if(!q1.empty())
   	  		  {  
   	  			int x=q1.top();
   	  			ans[x]=ans[i]=(a[i].a+a[x].a)/2;
   	  			q1.pop();
   	  		  } else q1.push(i);
   	    	} else
   	    	{
   	    		if(!q2.empty())
   	  		    {  
   	  			  int x=q2.top();
   	  			  ans[x]=ans[i]=(a[i].a+a[x].a)/2;
   	  			  q2.pop();
   	  		    } else q2.push(i);
   	    	}
   	    }
   	  while (!q1.empty()) q1.pop();
   	  while (!q2.empty()) q2.pop();
   	  rep(i,1,n)
   	     if (a[i].b==0&&ans[i]==-1) 
			if (a[i].a%2==1) q1.push(i);
			else q2.push(i);
	  dep(i,n,1)
   	     if (a[i].b==1&&ans[i]==-1) 
			if (a[i].a%2==1) q3.push(i);
			else q4.push(i);
	  while (!q1.empty()&&!q3.empty())
	  {
	  	int x=q1.top(),y=q3.top();
	  	ans[x]=ans[y]=(2*m-(a[y].a-a[x].a))/2;
	  	q1.pop(); q3.pop();
	  }
	  while (!q2.empty()&&!q4.empty())
	  {
	  	int x=q2.top(),y=q4.top();
	  	ans[x]=ans[y]=(2*m-(a[y].a-a[x].a))/2;
	  	q2.pop(); q4.pop();
	  }
	  
   	  while (!q1.empty()) q1.pop();
   	  while (!q2.empty()) q2.pop();
   	  while (!q3.empty()) q3.pop();
   	  while (!q4.empty()) q4.pop();
   	  rep(i,1,n) ans2[a[i].id]=ans[i];
   	  rep(i,1,n) cout<<ans2[i]<<" ";
   	  cout<<endl;
   }
   return 0;
}