#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=1e6+10;
char s[N];
vector<int> a[N];
vector<int> ve[2];
int h[N*4];
int n,m;
int main()
{
    
    
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		rep(i,1,n)
		{
			cin>>(s+1);
			a[i].push_back(0);
			rep(j,1,m)
			  if (s[j]=='0') a[i].push_back(0);
			  else a[i].push_back(1);
		}
		int ans=0;
		rep(k,2,n+m)
		{
		  rep(i,max(k-m,1),min(n,k-1))
		  {
		  	int j=k-i;
		  	while (!ve[(i+j)%2].empty()&&ve[(i+j)%2].back()>=i-j+n+m) ve[(i+j)%2].pop_back();
		  	if (h[i-j+n+m]) ve[(i+j)%2].push_back(i-j+n+m); 
		    if (i<=n&&j<=m&&a[i][j]==1)
		    {
		    //	cerr<<i<<" "<<j<<endl;
		    	if (!ve[(i+j)%2].empty())
		    	{
		    		int x=ve[(i+j)%2].back();
		    		h[x]=0;
		    		ve[(i+j)%2].pop_back();
		    	} else ans++;
		    	h[i-j+n+m]=1;
		    	ve[(i+j)%2].push_back(i-j+n+m); 
		    }
		  }
	    }
		cout<<ans<<"\n";
		rep(i,1,n) a[i].clear();
		rep(i,1,2*(n+m)) h[i]=0;
		ve[0].clear(); ve[1].clear();
	}
	return 0; 
}