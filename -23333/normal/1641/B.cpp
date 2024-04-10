#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e6;
map<int,int> M;
int n;
int a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		M.clear();
		rep(i,1,n)
		{ 
		  cin>>a[i];
		  M[a[i]]++;
	    }
	    bool tt=0;
	    for (auto v:M) if (v.second%2==1) tt=1;
	    if (tt)
	    {
	    	cout<<-1<<endl;
	    	continue;
	    }
	    int lst=0,m=n;
	    rep(i,1,n) b[i]=a[i];
	    vector<int> ans;
	    vector<pair<int,int>> ans2;
	    while (m)
	    {
	      int jl=0;
	      rep(i,2,m)
	      {  
	        if (b[i]==b[1])
			{ 
			  jl=i;
			  break;
		    }
		  }
		  rep(i,2,jl-1) ans2.push_back({b[i],jl+lst+i-2});
		  ans.push_back((jl-1)*2);
		  lst+=2*(jl-1);
		  rep(i,1,jl-2) a[i]=b[jl-i];
		  m-=2;
		  rep(i,jl-1,m) a[i]=b[i+2];
		  rep(i,1,m) b[i]=a[i];
		}
		cout<<ans2.size()<<"\n";
		for (auto v:ans2) cout<<v.second<<" "<<v.first<<"\n";
		cout<<ans.size()<<"\n";
		for (auto v:ans)
		{
			cout<<v<<" ";
		}
		cout<<"\n";
    }  
	return 0; 
}