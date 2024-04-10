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
int t;
int a[3000],b[3000],c[3000],p[3000],n;
int main(){
	cin>>t;
	rep(numx,1,t){
		cin>>n;
		rep(i,1,n)cin>>a[i];
		rep(i,1,n)cin>>b[i];
		rep(i,1,n)cin>>c[i];
		p[1]=a[1];
		rep(i,2,n-1){
			if(a[i]!=p[i-1]){p[i]=a[i];continue;}
			if(b[i]!=p[i-1]){p[i]=b[i];continue;}
		}
		if(a[n]!=p[n-1]&&a[n]!=p[1]){p[n]=a[n];}
		if(b[n]!=p[n-1]&&b[n]!=p[1]){p[n]=b[n];}
		if(c[n]!=p[n-1]&&c[n]!=p[1]){p[n]=c[n];}
		rep(i,1,n)cout<<p[i]<<' ';
		cout<<endl;
	}
	return 0;
}