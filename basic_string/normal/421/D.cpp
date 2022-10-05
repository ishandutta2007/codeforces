#include<bits/stdc++.h>
using namespace std;
enum{N=300009};
int x[N],y[N],a[N],a2[N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,p,i;
	map<pair<int,int>,int>mp;
	long long ans=0;
	cin>>n>>p;
	for(i=1;i<=n;++i){
		cin>>x[i]>>y[i],++a[x[i]],++a[y[i]];
		if(x[i]<y[i])mp[{x[i],y[i]}]++;
		else mp[{y[i],x[i]}]++;
	}
	memcpy(a2,a,sizeof a),sort(a+1,a+n+1);
	for(i=1;i<=n;++i){
		int j=lower_bound(a+1,a+n+1,p-a[i])-a;
		j=max(j,i+1);
		ans+=n-j+1;
	}
	for(auto o:mp)if(a2[o.first.first]+a2[o.first.second]>=p&&
	a2[o.first.first]+a2[o.first.second]-o.second<p)--ans;
	cout<<ans;
	return 0;
}