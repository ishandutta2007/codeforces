#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
vector< pair<int,char> > ans;
int n,m,k;
void push(int times,char s){
	int t=min(times,k);
	if(t==0)return;
	k-=t;
	ans.push_back({t,s});
}
void solve(){
	repeat(i,0,n-1)
		push(m-1,'R'),push(m-1,'L'),push(1,'D');
	repeat(i,0,m-1)
		push(1,'R'),push(n-1,'U'),push(n-1,'D');
	push(m-1,'L'),push(n-1,'U');
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	int tot=2*(n*(m-1)+(n-1)*m);
	if(tot<k){cout<<"NO"<<endl; exit(0);}
	solve();
	cout<<"YES"<<endl;
	cout<<ans.size()<<endl;
	for(auto i:ans)
		cout<<i.first<<' '<<i.second<<endl;
	return 0;
}