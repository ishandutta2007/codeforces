#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int T,n,m;
const int N=3e5;
vector<int> a[N],b[N]; 
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		rep(i,1,n) a[i].resize(m+5),b[i].resize(m+5);
		rep(i,1,n)
		  rep(j,1,m) cin>>a[i][j];
		int gg1=1,gg2=1;
		bool tt=1;
		rep(i,1,n)
		{
			rep(j,1,m) b[i][j]=a[i][j];
		    sort(b[i].begin()+1,b[i].begin()+m+1);
		    vector<int> ve;
		    rep(j,1,m)
		      if (b[i][j]!=a[i][j]) ve.push_back(j);
		    if (ve.size()==2)
		    {
		    	gg1=ve[0]; gg2=ve[1];
		    }
		    if (ve.size()>2) tt=0;
		}
		if (tt)
		{
			rep(i,1,n) swap(a[i][gg1],a[i][gg2]);
		    rep(i,1,n)
		      rep(j,2,m)
		        if (a[i][j]<a[i][j-1]) tt=0;
		    if (tt)
		    {
		      cout<<gg1<<" "<<gg2<<endl;	
		    } else cout<<-1<<endl;
		} else cout<<-1<<endl;
	}
	return 0;
}