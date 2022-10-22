#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=3e5;
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		map<int,int> M;
		int mx=0,mn=1e9;
		rep(i,1,n) {cin>>a[i],M[a[i]]++;mx=max(mx,a[i]);mn=min(mn,a[i]);}
		int ans=0,gg=0;;
		for (auto v:M)
		{
			if (v.second>=2) ans+=2; else  ans+=1,gg=1;
		}
		if (gg) ans++;
		cout<<ans/2<<endl;
	}
	return 0;
}