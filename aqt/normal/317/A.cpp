#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int x,y,m;cin>>x>>y>>m;
	if(x>=m||y>=m){
		cout<<0<<"\n";
		return 0;
	}
	if(x<=0&&y<=0){
		cout<<-1<<"\n";
		return 0;
	}
	int ans=0;
	//fix the negative number x
	if(x<0||y<0){
		if(y<x)swap(x,y);
		int ad=abs(x)/y;
		x+=y*ad;
		ans+=ad;
	}
	while(x<m&&y<m){
		if(x<y)x=x+y;
		else y=x+y;
		ans++;
		//cerr<<x<<" "<<y<<"\n";
	}
	cout<<ans<<"\n";
}