#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
#define int ll
string s;
void solve(){
	int n,k; cin>>n>>k;
	cin>>s; sort(s.begin(),s.end());
	if(s[k-1]!=s[0] || k==n){
		putchar(s[k-1]);
		puts("");
		return;
	}
	if(s[n-1]==s[k]){
		putchar(s[0]);
		repeat(i,0,(n-1)/k)
			putchar(s[k]);
		puts("");
		return;
	}
	puts(s.c_str()+k-1);
}
signed main(){
	int T; cin>>T;
	while(T--)solve();
	return 0;
}