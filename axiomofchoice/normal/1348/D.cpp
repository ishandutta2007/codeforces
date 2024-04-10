#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
#define int ll
vector<int> a;
void solve(){
	int n; cin>>n; a.clear();
	for(int i=1;;i<<=1){
		if(n<=i){a.push_back(n); break;}
		a.push_back(i);
		n-=i;
	}
	int sz=a.size();
	if(a[sz-1]<a[sz-2]){
		int sum=a[sz-1]+a[sz-2];
		a[sz-2]=sum/2;
		a[sz-1]=(sum+1)/2;
	}
	cout<<sz-1<<endl;
	repeat(i,0,sz-1)
		cout<<a[i+1]-a[i]<<' ';
	cout<<endl;
}
signed main(){
	int T; cin>>T;
	while(T--)solve();
	return 0;
}