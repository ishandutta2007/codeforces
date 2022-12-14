#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=100010; typedef long long ll; const int inf=~0u>>2; typedef pair<int,int> pii;
#define int ll
int T,n,m;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		if(n>=3)cout<<m*2<<endl;
		else cout<<m*(n-1)<<endl;
	}
	return 0;
}