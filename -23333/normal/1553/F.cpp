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
ll ans=0;
const int N=5e5;
struct sgt{
  ll c1[N],c2[N]; 
  inline void update(ll x,ll k)
  {
    ll i=x; x=max(x,1ll);
    while(x<=3e5)
    {
        c1[x]+=k;
        c2[x]+=i*k;
        x+=x&-x;
    }
    return;
  }
  inline ll sum(ll x)
  {
  	x=min(x,(ll)3e5); x=max(x,0ll);
    ll ans=0;
    ll i=x;
    while(x>0)
    {
        ans+=c1[x]*(i+1);
        ans-=c2[x];
        x-=x&-x;
    }
    return ans;
  }
   inline void change(int x,int y,ll z)
   {
  //     cerr<<x<<" "<<y<<endl;
      update(x,z);
      update(y+1,-z);
   }
   ll query(int x,int y)
   {
      return sum(y)-sum(x-1);
   }
}S1,S2,S3,S4; 
int a[N];
int main()
{
   //freopen("1.out","w",stdout);
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
 //  S.change(1,2);
  // S.change(1,2);
   rep(i,1,n) cin>>a[i];
   ll ans=0;
   int cntt=0;
   rep(i,1,n)
   {
   //	if (i%100==0) cerr<<i<<" "<<cntt<<endl;
  /* 	 ll cnt=0;
   	 for (int j=1;j<=a[i];j=a[i]/(a[i]/j)+1)
	 {
	 	cntt++;
	 	int k=a[i]/(a[i]/j);
	 	ll k1=S1.query(j,k),k2=S2.query(j,k);
	 	ans=ans+k2*a[i]-k1*(a[i]/j);
	 	cnt+=k2;
     }*/
    // ans+=(i-1-cnt)*a[i];
     ans-=S3.query(a[i],a[i])-S4.query(a[i],a[i])*a[i];
     for(int j=0;j*a[i]<=3e5;j++)
     {
     	//cerr<<j<<endl;
     	int k1=max(j*a[i],1),k2=(j+1)*a[i]-1;
     	S3.change(k1,k2,j*a[i]);
	//	cerr<<k1<<" "<<k2<<endl; 
		S4.change(k1,k2,1);
     	ll t1=S1.query(k1,k2),t2=S2.query(k1,k2);
     	ans=ans+t1-t2*j*a[i];
     }
     S1.change(a[i],a[i],a[i]);
     S2.change(a[i],a[i],1);
     cout<<ans<<" ";
   }
   return 0;
}