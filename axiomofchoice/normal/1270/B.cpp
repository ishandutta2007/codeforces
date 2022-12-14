#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=200010;
const int inf=1e9;
const int mod=1e9+7;
#define int ll
int t,n,a[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		repeat(i,0,n)cin>>a[i];
		int f=false;
		repeat(i,0,n-1)
		if(abs(a[i]-a[i+1])>=2){
			cout<<"YES"<<endl<<i+1<<' '<<i+2<<endl;
			f=true;
			break;
		}
		if(!f)cout<<"NO"<<endl;
	}
	return 0;
}