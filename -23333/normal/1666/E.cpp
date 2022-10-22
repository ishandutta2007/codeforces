//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=3e5+10;
const int mo=1e9+7;
int n,m;
int a[N],l[N],r[N];
int check2(int x,int y)
{
	int h=0,t=0;
	rep(i,1,m-1)
	{
		h=max(a[i],h+x);
		t=min(a[i+1],t+y);
		if (t<a[i]) return -1;
		if (h>a[i+1]) return 1;
    }
    if (n-h<x) return 1;
    if (n-t>y) return -1;
    return 0;
}
int ans=0;
bool check(int x)
{
	int h=0,t=n;
	while (h<=t)
	{
		int mid=(h+t)/2;
		int tf=check2(max(1,mid-x),mid);
		if (tf==0)
		{
		  ans=mid; 
		  return 1;
	    }
		if (tf==-1) h=mid+1;
		else t=mid-1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	if (m==1)
	{
		cout<<0<<" "<<n<<endl;
		return 0;
	}
	rep(i,1,m) cin>>a[i];
	int h=0,t=n;
	while (h<t)
	{
		int mid=(h+t)/2;
		if (check(mid)) t=mid; else h=mid+1;
	}
	check(h);
	int x=max(1,ans-h),y=ans;
	h=0,t=0;
	rep(i,1,m-1)
	{
		h=max(a[i],h+x);
		t=min(a[i+1],t+y);
		l[i]=h; r[i]=t;
    }
    int now=max(l[m-1],n-y);
    vector<int> ve;
    ve.push_back(n);
    ve.push_back(now);
    dep(i,m-2,1)
    {
    	now=max(l[i],now-y);
    	ve.push_back(now);
    }
    ve.push_back(0);
    reverse(ve.begin(),ve.end());
    for (int i=0;i+1<ve.size();i++) 
      cout<<ve[i]<<" "<<ve[i+1]<<"\n";
//	cout<<h<<endl;
	return 0;
}