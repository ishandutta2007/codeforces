#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int t=t;i>=h;i--)
int n,m,a,b;
bool f[1000];
void dfs(int a,int b)
{
	f[a]=1;
	cout<<a<<" "<<b<<endl;
	int lst=0;
	rep(i,1,b-1) cout<<a<<" "<<i<<endl,lst=i;
	rep(i,b+1,m) cout<<a<<" "<<i<<endl,lst=i;
	rep(i,1,n) 
    if (f[i]==0)
	{ 
	  dfs(i,lst);
	  break;
   }
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>a>>b;
    dfs(a,b);
	return 0;
}