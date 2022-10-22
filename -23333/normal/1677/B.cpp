#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
ll T,n,m;
const int N=1e6+10;
char s[N];
int a[N],b[N],h[N],ans[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		int l=n*m,cnt=0;
		cin>>(s+1);
		rep(i,0,l) a[i]=h[i]=b[i]=0; 
		rep(i,1,l)
		{
			if (s[i]=='1') a[i]=a[i-1]+1; else a[i]=a[i-1];
			int k=max(0ll,i-m);
			if (a[i]-a[k]>0) b[i]++;
			if (i>=m) b[i]+=b[i-m];
			if (s[i]=='1'&&h[i%m]==0)
			{
				h[i%m]=1; cnt++;
			}
			cout<<cnt+b[i]<<" ";
		}
		cout<<endl; 
	}
	return 0;
}
/*
1
4 2
11001101
*/