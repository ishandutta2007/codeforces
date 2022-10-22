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
const int N=6e5;
int sum[N],a[N];
vector<int> ve[N];
int now[N*2],cnt;
int main()
{
	int n,c;
	read(n); read(c);
	rep(i,1,n) read(a[i]),ve[a[i]].push_back(i);
	rep(i,1,n)
	{ 
	  sum[i]=sum[i-1];
	  if (a[i]==c) sum[i]++;
    }
    int ans=0;
    rep(i,1,5e5)
    {
    	cnt=0;
    	if (ve[i].size()==0) continue;
    	if (i==c) continue;
    	now[++cnt]=1;
    	for (int j=1;j<ve[i].size();j++)
    	{
    		now[++cnt]=-(sum[ve[i][j]-1]-sum[ve[i][j-1]]);
    		now[++cnt]=1;
    	}
    	int ans2=0;
    	rep(j,1,cnt)
    	{
    	  ans2+=now[j];
    	  if (ans2<0) ans2=0;
    	  maxa(ans,ans2);
        }
    }
    cout<<ans+sum[n]<<endl;
	return 0;
}