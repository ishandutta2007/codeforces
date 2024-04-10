
 #include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, p, oidx=0, eidx=0;
int v[N];
vector<int> o[N], e[N]; 

int32_t main()
{
	IOS;
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		if(v[i]%2)
			o[++oidx].push_back(v[i]);
		else
			e[++eidx].push_back(v[i]);
	}
	while(eidx<p)
	{
		if(oidx<=1)
		{
			cout<<"NO";
			return 0;
		}
		e[++eidx].push_back(o[oidx].back());
		o[oidx].pop_back();
		oidx--;
		e[eidx].push_back(o[oidx].back());
		o[oidx].pop_back();
		oidx--;
	}
	if(oidx<k-p)
	{
		cout<<"NO";
		return 0;
	}
	int diff=(oidx - (k-p));
	if(diff%2)
	{
		cout<<"NO";
		return 0;
	}
	while(oidx>k-p)
	{
		e[++eidx].push_back(o[oidx].back());
		o[oidx].pop_back();
		oidx--;
		e[eidx].push_back(o[oidx].back());
		o[oidx].pop_back();
		oidx--;
	}
	while(eidx>p)
	{
		if(oidx>0)
		{
			for(auto &it:e[eidx])
				o[1].push_back(it);
			eidx--;
		}
		else
		{
			for(auto &it:e[eidx])
				e[1].push_back(it);
			eidx--;
		}
	}
	if(eidx==p && oidx==k-p)
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=oidx;i++)
		{
			cout<<o[i].size()<<" ";
			for(auto &it:o[i])
				cout<<it<<" ";
			cout<<endl;
		}
		for(int i=1;i<=eidx;i++)
		{
			cout<<e[i].size()<<" ";
			for(auto &it:e[i])
				cout<<it<<" ";
			cout<<endl;
		}
	}
	else
		cout<<"NO";
	return 0;
}