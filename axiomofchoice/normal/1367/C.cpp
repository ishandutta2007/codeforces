#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
#define int ll
int n,k; string s;
signed main(){
	int T; cin>>T;
	while(T--){
		cin>>n>>k>>s;
		int table=-1,ans=0;
		repeat(i,0,n)if(s[i]=='1')s[max(i-k,0ll)]='1';
		repeat(i,0,n){
			if(s[i]=='0'){
				if(table<i){
					table=i+k;
					ans++;
				}
			}
			else table=i+k;
		}
		cout<<ans<<endl;
	}
	return 0;
}