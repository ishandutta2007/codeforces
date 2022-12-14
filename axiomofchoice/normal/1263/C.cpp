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
vector<int> ans;
void fac(ll n){
	int i=1;
	while(1){
		ans.push_back(i);
		i=n/(n/i)+1;
		if(i==n+1)break;
	}
	ans.push_back(i);
}
int n,k;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--){
		cin>>n;
		ans.clear();
		fac(n);
		cout<<ans.size()<<endl;
		repeat_back(i,0,ans.size())
			cout<<n/ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}