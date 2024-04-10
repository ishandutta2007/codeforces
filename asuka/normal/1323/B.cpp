#include<bits/stdc++.h>
#define ll long long
#define N 40015
using namespace std;
ll n,m,k,a[N],b[N],ans;
vector<int> x,y;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= n;++i) cin>>a[i];
	for(int i = 1;i <= m;++i) cin>>b[i];
	int len = 0;
	for(int i = 1;i <= n;++i){
		if(a[i]==1) len++;
		else{
			x.push_back(len);
			len = 0;
		}
	}
	x.push_back(len);
	len = 0;
	for(int i = 1;i <= m;++i){
		if(b[i]==1) len++;
		else{
			y.push_back(len);
			len = 0;
		}
	}
	y.push_back(len);
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	for(int i = 1;i <= n;++i){
		if(k%i!=0) continue;
		int u = i,v = k/i;
		ll c1 = 0,c2 = 0;
		for(int j = int(x.size())-1;j >= 0;--j){
			if(x[j] < u) break;
			else c1 += x[j]-u+1;
		}
		for(int j = int(y.size())-1;j >= 0;--j){
			if(y[j] < v) break;
			else c2 += y[j]-v+1;
		}
		ans += c1*c2;
	}
	cout<<ans;
	return 0;
}