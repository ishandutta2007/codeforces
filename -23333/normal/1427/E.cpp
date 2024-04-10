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
#define pb push_back
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
	ll a,b,c;
};
const int N=1e4;
ll a[N];
map<ll,bool> M;
vector<re> ans;
ll h[61],xx;
void insert(ll x,ll y)
{
	ll gg=y;
   	vector<re> ve;
   	ll now=0;
   	dep(j,60,0)
	  if ((x>>j)&1) 
	  {
	    if (!h[j])
		{ 
		  h[j]=x;
		  dep(j,60,0) 
		    if ((gg>>j)&1)
		    {
		    	ans.pb((re){now,xx*(1<<j),1});
		    	now+=(xx*(1<<j));
		    }
		  for (auto k:ve)
		    ans.pb(k);
	      break;
	    } else
		{ 
		  ve.pb((re){x,h[j],0});
		  x^=h[j];
	    }
	  }
}
int main()
{
   ios::sync_with_stdio(false);
   ll x;
   cin>>x;
   xx=x;
//   for(int x=1;x<=1000000;x+=2)
//   {
ans.push_back((re){x,x,0});
   	  a[1]=x;
   	  rep(j,2,32) a[j]=x*(1<<(j-1)),insert(a[j],0),ans.push_back((re){a[j-1],a[j-1],1});
   	  rep(j,1,1e7)
   	  {
   	  	ll k=x*(1ll*rand()*rand()%(1<<30)+1);
   	  	insert(k,k/x);
   	  	if (h[0]==1) break;
   	  }
  //    int cnt=5000;
 //  cin>>a[1];
  //    rep(i,1,100) a[i]=x*i;
  //    rep(i,1,100)
//     {
// 	int x=a[i];
// 	rep(j,1,20) a[++cnt]=x*(1<<j);
// }
  // a[1]=x;
 /*  while (cnt<=1000)
   {
   	 int cnt2=0;
   	 while (1)
   	 {
   	   cnt2++;
   	   ll x=a[rand()%cnt+1],y=a[rand()%cnt+1];
   	   if (rand()%4<=2) 
   	   {
		 if ((M[x^y])&&cnt2<5) continue;
		 a[++cnt]=x^y;
		 ans.pb((re){x,y,0});
	   } 
	   else
	   {
	     if ((M[x+y])&&cnt2<5) continue; 
	     a[++cnt]=x+y;
	     ans.pb((re){x,y,1});
	   } 
	   break;
     }
 //    cout<<a[cnt]<<endl;
     M[a[cnt]]=1;
   } */
   cout<<ans.size()<<endl;
   for(auto t:ans)
   {
   	if(t.c==0) cout<<t.a<<" ^ "<<t.b<<endl;
   	else cout<<t.a<<" + "<<t.b<<endl;
   } 
   if (!h[0]) cerr<<x<<" "<<-1<<endl; else if (x%1000==1) cerr<<x<<" "<<0<<endl;
//   me(h); M.clear(); ans.clear();
//   } 
   return 0;
}