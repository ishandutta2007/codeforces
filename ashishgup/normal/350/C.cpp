#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
pair<int, int> a[N];
set<pair<int, int> > s;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
		s.insert({abs(a[i].first) + abs(a[i].second), i});
	}
	int ans=0;
	for(auto it:s)
	{
		int idx=it.second;
		int x=a[idx].first;
		int y=a[idx].second;
		int distx=abs(x);
		int disty=abs(y);
		if(distx>0 && disty>0)
			ans+=6;
		else
			ans+=4;
	}
	cout<<ans<<endl;
	for(auto it:s)
	{
		int idx=it.second;
		int x=a[idx].first;
		int y=a[idx].second;
		int distx=abs(x);
		int disty=abs(y);
		if(distx>0)
	 		cout<<"1 "<<distx<<" "<<(x>0?"R":"L")<<endl;	
		if(disty>0)
	 		cout<<"1 "<<disty<<" "<<(y>0?"U":"D")<<endl;	
		cout<<"2"<<endl;
		if(distx>0)
	 		cout<<"1 "<<distx<<" "<<(x>0?"L":"R")<<endl;	
		if(disty>0)
	 		cout<<"1 "<<disty<<" "<<(y>0?"D":"U")<<endl;	
		cout<<"3"<<endl;
	}
	return 0;
}