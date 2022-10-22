#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=5e6;
int n,m;
int a[N],c[N],p[N],ans[N];
vector<int>b[N];
bool cmp(int x,int y)
{
	return c[x]>c[y];
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		rep(i,1,n) c[i]=0,b[i].clear();
		rep(i,1,n) cin>>a[i],c[a[i]]++,b[a[i]].push_back(i);
		rep(i,1,n) p[i]=i;
		sort(p+1,p+n+1,cmp);
		vector<int> ve1,ve2;
		rep(i,2,n+1)
		{
		  int g=i;if (i==n+1) g=1;
		  for (auto v:b[p[g]]) ve1.push_back(p[g]);
 	    }
 	    rep(i,1,n) 
		  for (auto v:b[p[i]]) ve2.push_back(v);
		rep(i,1,n)
		{
		 // cout<<ve1[i-1]<<" "<<ve2[i-1]<<endl; 
		  ans[ve2[i-1]]=ve1[i-1];
	    }
		rep(i,1,n) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}