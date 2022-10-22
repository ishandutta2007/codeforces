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
const int N=100;
int a[N],b[N],n;
int main()
{
	ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n) cin>>a[i];
    int h=1,t=n;
    int o=n%2;
    if (a[n]==n) o=0;
    else if (a[n]==1) o=1;
    if(o==0)
    {
      rep(i,1,n)
        if (a[i]==i) h++; else break;
      dep(i,n,1) if (a[i]==i) t--; else break;
    } else
    {
    	rep(i,1,n)
    	  if (a[i]==n-i+1) h++; else break;
    	dep(i,n,1) if (a[i]==n-i+1) t--; else break;
    	int h1=n-t+1;
    	t=n-h+1; h=h1; 
    }
    bool tt=0;
    rep(i,1,n) if (a[i]!=i) tt=1;
	if (!tt)
	{
		cout<<0<<endl;
		return 0;
	}
	int cnt=0,h3,t3;
    while(1)
	{
		bool tt=0;
	    rep(i,1,n) if (a[i]!=i) tt=1;
	    if (!tt) break;
	    tt=0;
	    rep(i,1,n) if (a[i]!=n-i+1) tt=1;
	    if (!tt)
	    {
	        cnt++;
	        wer(n);wer1(); 
	        rep(i,1,n) wer(1),wer1();
	        break;
	    }
		int pos;
		if (o==0)
		{
			cnt++;
			if (a[t]==h)
			{ 
			  wer(h+(n-t)),wer1();
		    }
			else wer(h+(n-t)+1);wer1();
			rep(i,1,h-1) wer(1),wer1();
			rep(i,h,t) if(a[i]==h) pos=i;
			wer(pos-h+1); wer1();
			if(t-pos>0)wer(t-pos),wer1();
			rep(i,t+1,n) wer(1),wer1();
			reverse(a+h,a+pos+1);
			reverse(a+pos+1,a+t+1);
			reverse(a+1,a+n+1);
			dep(i,n,1)
			  if (a[i]!=n-i+1)
			  {
			  	h=n-i+1; break;
			  }
			rep(i,1,n)
			  if(a[i]!=n-i+1)
			  {
			  	t=n-i+1; break;
			  }
			o^=1;
		} else
		{

	        {
	        	cnt++;
	        	int h1=h,t1=t;
	        	int h=n-t1+1,t=n-h1+1;
			if (a[t]==t1) wer(h+(n-t)),wer1();
			else wer(h+(n-t)+1),wer1();
			rep(i,1,h-1) wer(1),wer1();
			rep(i,h,t) if(a[i]==t1) pos=i;
			wer(pos-h+1); wer1();
			if(t-pos>0)wer(t-pos),wer1();
			rep(i,t+1,n) wer(1),wer1();
			reverse(a+h,a+pos+1);
			reverse(a+pos+1,a+t+1);
			reverse(a+1,a+n+1);
			dep(i,n,1)
			  if (a[i]!=i)
			  {
			  	t3=i; break;
			  }
			rep(i,1,n)
			  if(a[i]!=i)
			  {
			  	h3=i; break;
			  }
			o^=1;
	        }
		}
		if (o==0) h=h3,t=t3;
		wer2();
    }
    cout<<cnt<<endl;
    fwrite(sr,1,C1+1,stdout);
	return 0;
}