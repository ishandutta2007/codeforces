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
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n,l;
		cin>>n>>l;
		rep(i,1,n) cin>>a[i];
		int h=1,t=n;
		double h1=0,t1=l,tim=0;
		int now1=1,now2=1;
		while (h<=t)
		{
			double p1=(a[h]-h1)/now1;
			double p2=(t1-a[t])/now2;
			if(p1==p2)
			{
				now1++;
				now2++;
				h1=a[h]; t1=a[t];
				h++; t--;
			} else
			if (p1<p2)
			{
				now1++;
				h1=a[h];
				h++;
				t1-=now2*p1;
			} else
			{
				now2++;
				t1=a[t];
				t--;
				h1+=now1*p2;
			}
			tim+=min(p1,p2);
		}
		tim+=(t1-h1)/(now1+now2);
		printf("%.10f\n",tim); 
	}
	return 0;
}