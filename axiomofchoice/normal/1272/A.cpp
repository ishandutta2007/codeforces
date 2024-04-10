#include <bits/stdc++.h>
using namespace std;
using ll=long long; //using lll=__int128;
using pii=pair<int,int>;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=1010;
const int inf=1e9;
const int mod=1000000007;
#define int ll

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t,a,b,c;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		int m=min(a,min(b,c)),M=max(a,max(b,c));
		cout<<max(M-m-2,0ll)*2<<endl;
	}
	return 0;
}