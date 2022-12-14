#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll;
#define int ll
int T;
signed main(){
	cin>>T;
	while(T--){
		int n,m,x,y;
		cin>>n>>x>>m; y=x;
		while(m--){
			int l,r;
			cin>>l>>r;
			if(max(l,r)<min(x,y)
			|| max(x,y)<min(l,r));
			else{
				x=min(x,l);
				y=max(y,r);
			}
		}
		cout<<y-x+1<<endl;
	}
	return 0;
}