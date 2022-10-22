#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=n;i--)
const int N=5e5;
int a[N];
vector<int> ve[N],ans;
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
	int n;
	cin>>n;
	rep(i,1,n)
	{ 
	  cin>>a[i];
	  ve[a[i]].push_back(i);
    }
    rep(i,0,n) reverse(ve[i].begin(),ve[i].end());
	int now=0,lst=0,wz=0;
	while (now<=n)
	{
		while (!ve[wz].empty()&&ve[wz].back()<=lst) ve[wz].pop_back();
		if (!ve[wz].empty())
		{
			now=max(now,ve[wz].back());
			wz++;
		} else
		{
			if (!wz) now++; lst=now;
			if (now>n) break;
			ans.push_back(wz);
			wz=0;
		}
	}
	cout<<ans.size()<<endl;
	for (auto v:ans) cout<<v<<" ";
	cout<<endl;
	rep(i,0,n) ve[i].clear();
	ans.clear();
    }
	return 0; 
}