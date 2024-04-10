#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e6;
int a[N],b[N],r1[N],r2[N];
int n,m,k;
#define mid ((h+t)/2)
struct sgt{
	int v1[N*4],v2[N*4];
	void g(int x,int h,int t,int pos,int k)
	{
		if (h==t) { v1[x]=k; v2[x]=k; return;}
		if (pos<=mid) g(x*2,h,mid,pos,k);
		else g(x*2+1,mid+1,t,pos,k);
		v1[x]=max(v1[x*2],v1[x*2+1]);
		v2[x]=min(v2[x*2],v2[x*2+1]); 
	}
	int q1(int x,int h,int t,int h1,int t1)
	{
		if (h1<=h&&t<=t1) return v1[x];
		int ans=0;
		if (h1<=mid) ans=q1(x*2,h,mid,h1,t1);
		if (mid<t1) ans=max(ans,q1(x*2+1,mid+1,t,h1,t1));
		return ans;
	}
	
	int q2(int x,int h,int t,int h1,int t1)
	{
		if (h1<=h&&t<=t1) return v2[x];
		int ans=1e9;
		if (h1<=mid) ans=q2(x*2,h,mid,h1,t1);
		if (mid<t1) ans=min(ans,q2(x*2+1,mid+1,t,h1,t1));
		return ans;
	}
}S;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		rep(i,1,n)
		{ 
		  cin>>a[i];
		  S.g(1,1,n,i,a[i]);
	    }
		int top=0;
		b[0]=n+1;
		dep(i,n,1)
		{
			while (top&&a[i]>a[b[top]]) top--;
			r1[i]=b[top]; b[++top]=i;
		}
		// r1:  
		top=0;
		dep(i,n,1)
		{
			while (top&&a[i]<a[b[top]]) top--;
			r2[i]=b[top]; b[++top]=i;
		}
		int now=1,cnt=0;
		while (now!=n)
		{
			int mn=1e9,mx=0;
			int ans=now+1;
			rep(j,now+1,r1[now]-1)
			{
				mn=min(mn,a[j]);
				if (a[j]==mn) ans=max(ans,j);
				if (j+1<=r1[now]-1&&S.q2(1,1,n,j+1,r1[now]-1)>mn) break;
		    }
		    rep(j,now+1,r2[now]-1)
		    {
		    	mx=max(mx,a[j]);
		    	if (a[j]==mx) ans=max(ans,j);
		    	if (j+1<=r2[now]-1&&S.q1(1,1,n,j+1,r2[now]-1)<mx) break;
		    }
		    now=ans; cnt++;
//		    cerr<<now<<endl;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
1
10
7 4 8 1 6 10 3 5 2 9
*/