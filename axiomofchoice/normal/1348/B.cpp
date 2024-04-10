#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
#define int ll
set<int> s;
void solve(){
	int n,k,x; cin>>n>>k; s.clear();
	repeat(i,0,n)cin>>x,s.insert(x);
	if((int)s.size()>k){cout<<-1<<endl; return;}
	for(int i=1;(int)s.size()<k;i++)s.insert(i);
	cout<<n*k<<endl;
	repeat(i,0,n)
	for(auto j:s)
		cout<<j<<' ';
	cout<<endl;
}
signed main(){
	int T; cin>>T;
	while(T--)solve();
	return 0;
}