#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
const int N=1000010;
vector<int> a[2];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=read();
	while(t--){
		a[0].clear();
		a[1].clear();
		int n=read();
		repeat(i,1,n+1){
			int x=read()%2;
			a[x].push_back(i);
		}
		if(!a[0].empty())cout<<1<<endl<<a[0][0]<<endl;
		else if(a[1].size()>1)cout<<2<<endl<<a[1][0]<<' '<<a[1][1]<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}