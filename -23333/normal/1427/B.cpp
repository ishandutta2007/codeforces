#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define IL inline
#define rint register int
#define ll long long 
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
const int N=2e6;
char  c[N];
int f[N],n,m;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		cin>>c;
		int cnt=-1,lst=0;
		int pp=0;
		rep(i,1,n)
		  if (c[i-1]=='W')
		  {
		    if (i>1&&c[i-2]=='W') pp+=2; else pp+=1; 
		    if (i-lst>0)
			{ 
			  cnt++;
		      if (cnt>0)
		      {
		        f[cnt]=i-lst;
		      }
		    }
		    lst=i+1;
		  } 
		if (cnt>=0)
		{ 
		  sort(f+1,f+cnt+1);
		int mm=m;
		rep(i,1,cnt) if (mm>=f[i]) pp++,mm-=f[i];
		pp+=m*2;
		pp=min(pp,2*n-1);
		cout<<pp<<endl;
		} else
		{
			cout<<max(min(2*n-1,2*m-1),0)<<endl;
	    }
    }
	return 0;
}