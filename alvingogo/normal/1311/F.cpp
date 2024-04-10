#include <bits/stdc++.h>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
using namespace std;

int n;
vector<long long> bt[2];

void update(int i,int x,int y){
	for(;x<=n;x+=(x&-x)){
		bt[i][x]+=y;
	}
}
long long query(int i,int x){
	long long ans=0;
	for(;x>0;x-=(x&-x)){
		ans+=bt[i][x];
	}
	return ans;
}
int main(){
	fastio;
	cin >> n;
	vector<pair<long long,int> > v(n+1);
	vector<int> c(n);
	bt[0].resize(n+1);
	bt[1].resize(n+1);
	for(int i=1;i<=n;i++){
		cin >> v[i].fs;
	}
	for(int i=1;i<=n;i++){
		cin >> v[i].sc;
		c[i-1]=v[i].sc;
	}
	sort(c.begin(),c.end());
	c.erase(unique(c.begin(),c.end()),c.end());
	for(int i=1;i<=n;i++){
		v[i].sc=lower_bound(c.begin(),c.end(),v[i].sc)-c.begin()+1;
	}
	long long ans=0;
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){
		int cnt=query(1,v[i].sc);
		ans+=1ll*cnt*v[i].fs-query(0,v[i].sc);
		update(0,v[i].sc,v[i].fs);
		update(1,v[i].sc,1);
	}
	cout << ans << "\n";
	return 0;
}