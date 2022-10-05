#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	pair<int,int> a[3];
	int mxy=-2e9,mny=2e9;
	int mxx=-2e9,mnx=2e9;
	for(auto&[x,y]:a){
		cin>>x>>y;
		mxx=max(mxx,x);
		mnx=min(mnx,x);
		mxy=max(mxy,y);
		mny=min(mny,y);
	}
	sort(a,a+3);
	auto[x,y]=a[1];
	cout<<"3\n";
	cout<<x<<' '<<mny<<' '<<x<<' '<<mxy<<'\n';
	cout<<a[0].first<<' '<<a[0].second<<' '<<x<<' '<<a[0].second<<'\n';
	cout<<a[2].first<<' '<<a[2].second<<' '<<x<<' '<<a[2].second<<'\n';
}