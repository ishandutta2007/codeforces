#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for(int i=h;i<=t;i++)
#define dep(i,t,h) for(int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define mep(x,y) memcpy(x,y,sizeof(y))
#define mid ((h+t)>>1)
#define ull unsigned int
namespace IO{
    char ss[1<<24],*A=ss,*B=ss;
    IL char gc()
    {
        return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
    }
    template<class T> void read(T &x)
    {
        rint f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
        while (c=gc(),c>47&&c<58) x=(x<<3)+(x<<1)+(c^48); x*=f; 
    }
    char sr[1<<24],z[20]; ll Z,C1=-1;
    template<class T>void wer(T x)
    {
        if (x<0) sr[++C1]='-',x=-x;
        while (z[++Z]=x%10+48,x/=10);
        while (sr[++C1]=z[Z],--Z);
    }
    IL void wer1()
    {
        sr[++C1]=' ';
    }
    IL void wer2()
    {
        sr[++C1]='\n';
    }
    template<class T>IL void maxa(T &x,T y) {if (x<y) x=y;}
    template<class T>IL void mina(T &x,T y) {if (x>y) x=y;} 
    template<class T>IL T MAX(T x,T y){return x>y?x:y;}
    template<class T>IL T MIN(T x,T y){return x<y?x:y;}
};
using namespace IO;
const int N=1000;
int n,v[N];
queue<int> q;
int main()
{
	read(n);
	int cnt=0,ans=0;
    rep(i,1,n)
    {
	  read(v[i]);
	  if (v[i]==1) cnt++,q.push(i);
	  ans+=v[i];
    }
    if (n==2&&v[1]==1&&v[2]==1)
    {
    	cout<<"YES"<<" "<<1<<endl;
    	cout<<1<<endl;
    	cout<<1<<" "<<2<<endl;
    	exit(0);
    }
	if (ans<2*(n-1))
	{
		cout<<"NO"<<endl;
	} else
	{
		cout<<"YES"<<" "<<MIN(n-cnt+1,n-1)<<endl;
		cout<<n-1<<endl;
		int lst=0;
		rep(i,1,n)
		  if (v[i]>1)
		  {
		  	while (q.size()>1&&((v[i]>2)||(v[i]==2&&lst==0)))
		  	{
		  		int k=q.front(); q.pop();
		  		cout<<k<<" "<<i<<endl;
		  		v[i]--;
		  	}
		  	if (lst!=0) cout<<lst<<" "<<i<<endl;
		  	lst=i;
		  }
		while (!q.empty())
		{
			int k=q.front(); q.pop();
			cout<<k<<" "<<lst<<endl;
		}
	}
	return 0;
}