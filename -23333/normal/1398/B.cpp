#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=1e5;
int a[N],b[N]; 
char c[N];
bool cmp(int x,int y)
{
  return x>y;	
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	rep(i,1,t)
	{
		cin>>c;
		int n=strlen(c);
		int cnt=0; 
		if (c[0]=='1') cnt=1,b[1]=1; else cnt=0;
		rep(i,1,n-1)
		{
			if (c[i]!=c[i-1]&&c[i]=='1') cnt++,b[cnt]=1;
			if (c[i]==c[i-1]&&c[i]=='1') b[cnt]++; 
		}
		sort(b+1,b+cnt+1,cmp);
		int ans=0;
		for (int i=1;i<=cnt;i+=2) ans+=b[i];
		cout<<ans<<endl;
    }
	return 0;
}