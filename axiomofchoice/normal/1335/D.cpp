#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
#define int ll
string s;
signed main(){
	int T; cin>>T;
	while(T--){
		repeat(i,0,9){
			cin>>s;
			s[s.find('1')]='2';
			cout<<s<<endl;
		}
	}
	return 0;
}