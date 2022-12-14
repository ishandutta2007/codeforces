#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=400010;
const int inf=1e9;
const int mod=998244353;
//#define int ll
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t,x;
	cin>>t;
	while(t--){
		cin>>x;
		if(x%14>=1 && x%14<=6 && x>14)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	//14*k + 1..6
	return 0;
}