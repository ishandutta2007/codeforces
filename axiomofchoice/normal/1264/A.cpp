#include <bits/stdc++.h>
using namespace std;
using ll=long long; //using lll=__int128;
using pii=pair<int,int>;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=400010;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
int n,T,f[N],a[N],cnt;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		repeat(i,0,n)cin>>a[i];
		a[n]=-1;
		f[0]=0; cnt=0;
		repeat(i,1,n+1)
		if(a[i]!=a[i-1])
			f[++cnt]=i,cnt;
		while(f[cnt]>n/2)cnt--;
		bool flag=false;
		repeat(i,2,cnt+1){
			if(f[i]-f[1]<=f[1])continue;
			if(f[cnt]-f[i]<=f[1])continue;
			cout<<f[1]<<' '<<f[i]-f[1]<<' '<<f[cnt]-f[i]<<endl;
			flag=true;
			break;
		}
		if(!flag)cout<<"0 0 0"<<endl;
		//repeat_back(i,1,cnt)f[i]-=f[i-1];
		//repeat(i,0,cnt+1)cout<<f[i]<<' ';
		//cout<<endl;
	}
	return 0;
}