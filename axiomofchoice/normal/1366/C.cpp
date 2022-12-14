#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=210; typedef long long ll;
#define int ll
int T,n,m;
map<int,int> mp[N];
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		repeat(i,2,n+m+1)mp[i].clear();
		repeat(i,1,n+1)
		repeat(j,1,m+1){
			int x; cin>>x;
			if((n+m)%2==0 && i+j==(n+m+2)/2)continue;
			mp[min(i+j,n+m+2-i-j)][x]++;
		}
		int ans=0;
		repeat(i,2,n+m+1){
			int mx=0,sum=0;
			for(auto j:mp[i])mx=max(mx,j.second),sum+=j.second;
			ans+=sum-mx;
		}
		cout<<ans<<endl;
	}
	return 0;
}