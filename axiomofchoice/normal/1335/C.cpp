#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
#define int ll
map<int,int> Map;
signed main(){
	int T=read();
	while(T--){
		int n=read(); Map.clear();
		repeat(i,0,n)Map[read()]++;
		int m=0,cnt=0;
		for(auto i:Map){
			cnt++;
			m=max(m,i.second);
		}
		cout<<max(min(cnt-1,m),min(cnt,m-1))<<endl;
	}
	return 0;
}