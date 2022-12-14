#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2;
const int mod=998244353;
#define int ll
int a[N],b[N],n,m,ans=1;
map<int,int> mp;
signed main(){
	cin>>n>>m;
	repeat(i,0,n)cin>>a[i];
	repeat(i,0,m)cin>>b[i],mp[b[i]]=0;
	repeat_back(i,0,n-1)a[i]=min(a[i],a[i+1]);
	if(a[0]!=b[0])cout<<0<<endl,exit(0);
	repeat_back(i,0,n){
		if(mp.count(a[i]))
			mp[a[i]]++;
	}
	for(auto it=++mp.begin();it!=mp.end();it++){
		(ans*=it->second)%=mod;
	}
	cout<<ans<<endl;
	return 0;
}