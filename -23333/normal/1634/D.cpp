#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long 
int n,m;
const int N=1e6;
ll a[N];
int q(int x,int y,int z)
{
	cout<<"?"<<" "<<x<<" "<<y<<" "<<z<<endl;
	int k;
	cin>>k;
	return k;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		 cin>>n;
		 int x=1,y=2,z=3;
		 int ans=q(1,2,3);
		 rep(i,4,n)
		 {
		 	int ans1=q(x,y,i);
		 	int ans2=q(x,z,i);
		 	if (ans1>=ans2&&ans1>ans)
		 	{
		 		z=i;
		 	} else
		 	if (ans2>=ans1&&ans2>ans)
		 	{
		 		y=i;
		 	}
		 	ans=max({ans,ans1,ans2});
	     }
	     int jl=0;
	     rep(i,1,n) if (i!=x&&i!=y&&i!=z) jl=i;
	     int g0=q(x,y,jl);
	     int g1=q(x,z,jl);
	     int g2=q(y,z,jl);
	     vector<int> ve;
	     if (g0!=ans) ve.push_back(z);
	     if (g1!=ans) ve.push_back(y);
	     if (g2!=ans) ve.push_back(x);
	     if (ve.size()==1) ve.push_back(ve[0]%n+1);
	     cout<<"! "<<ve[0]<<" "<<ve[1]<<endl;
	}
	return 0;
}