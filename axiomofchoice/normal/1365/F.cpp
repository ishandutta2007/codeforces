#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=510; typedef long long ll;
#define int ll
int n,a[N],b[N],T;
map<pair<int,int>,int> mp;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		repeat(i,0,n)cin>>a[i];
		repeat(i,0,n)cin>>b[i];
		int ans=true; mp.clear();
		if(n%2==1 && a[n/2]!=b[n/2])ans=false;
		repeat(i,0,n/2){
			int x,y;
			x=a[i],y=a[n-i-1];
			if(x>y)swap(x,y);
			mp[{x,y}]++;
			x=b[i],y=b[n-i-1];
			if(x>y)swap(x,y);
			mp[{x,y}]--;
		}
		for(auto i:mp)if(i.second!=0)ans=false;
		cout<<(ans?"Yes":"No")<<endl;
	}
	return 0;
}