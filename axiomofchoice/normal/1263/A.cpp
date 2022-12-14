#include <bits/stdc++.h>
using namespace std;
using ll=long long; //using lll=__int128;
using pii=pair<int,int>;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define N 10010
#define inf 1e9
#define qwq {cout<<"qwq"<<endl;}
#define int ll
const int mod=1000000007;
int n,a[3];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--){
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(a[2]>=a[0]+a[1])
			cout<<a[0]+a[1]<<endl;
		else
			cout<<(a[0]+a[1]+a[2])/2<<endl;
	}
	return 0;
}