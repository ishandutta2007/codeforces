#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=110; typedef long long ll;
//#define int ll
int T,n,m;
string s[N];
string ans;
bool ok(){
	repeat(i,0,n){
		int cnt=0;
		repeat(j,0,m)cnt+=(ans[j]!=s[i][j]);
		if(cnt>1)return 0;
	}
	return 1;
}
void solve(){
	cin>>n>>m;
	repeat(i,0,n)cin>>s[i];
	ans=s[0];
	repeat(i,0,n)
	repeat(j,0,m){
		int t=ans[j];
		ans[j]=s[i][j];
		if(ok()){cout<<ans<<endl; return;}
		ans[j]=t;
	}
	cout<<-1<<endl;
}
signed main(){
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}