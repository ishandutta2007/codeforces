#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5e5;
ll a[N],b[N],n,lim;
#define mid ((h+t)/2)
struct sgt{
	vector<int> ve[N*4];
	void build(int x,int h,int t)
	{
		if (h==t)
		{
			ve[x].clear();
			ve[x].push_back(a[h]); return;
	    }
	    build(x*2,h,mid); build(x*2+1,mid+1,t);
	    ve[x].clear();
	    for(auto v:ve[x*2]) ve[x].push_back(v);
	    for(auto v:ve[x*2+1]) ve[x].push_back(v);
	    sort(ve[x].begin(),ve[x].end());
	    while (ve[x].size()>32) ve[x].pop_back();
	}
	vector<int> q(int x,int h,int t,int h1,int t1)
	{
		if (h1<=h&&t<=t1)
		{
			return ve[x];
		}
		vector<int> ve1,ve2;
		if (h1<=mid) ve1=q(x*2,h,mid,h1,t1);
		if (mid<t1) ve2=q(x*2+1,mid+1,t,h1,t1);
		for (auto v:ve2) ve1.push_back(v);
	    sort(ve1.begin(),ve1.end());
	    while (ve1.size()>32) ve1.pop_back();
		return ve1;
	}
}S;
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while (T--)
    { 
    	cin>>n;
    	rep(i,1,n) cin>>a[i];
    	S.build(1,1,n);
    	int q;
    	cin>>q;
		while (q--)
		{
			int l,r;
			cin>>l>>r;
			int ans=2e9;
			auto v=S.q(1,1,n,l,r);
			for (int i=0;i<v.size();i++)
			  for (int j=0;j<v.size();j++)
			    if (i!=j) 
			    ans=min(ans,v[i]|v[j]);
			cout<<ans<<endl;
	    }
    } 
    
    return 0;
}