#include <bits/stdc++.h>
using namespace std;
#define lll __int128
typedef long long ll;
typedef pair<int,int> pii;
typedef double lf; const lf err=1e-7;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
#define orz(x) {cout<<#x": "<<x<<endl;}
const int N=123456;
const int inf=1e9;
const int mod=1e9+7;
#define int ll
int l=0,r=0,n,tn;
set<int> s;
int a[110];
ll ans;
void dfs(int x,int now){//cout<<2<<endl; 
	if(x==n){
		ans=min(ans,max(tn/now,now));
		return;
	}
	if(now>ans)return;
	dfs(x+1,now);
	dfs(x+1,now*a[x]);
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n; tn=n;
	repeat(i,2,sqrt(n)+2)
	if(n%i==0){
		int p=1;
		while(n%i==0)n/=i,p*=i;
		s.insert(p);
	}
	if(n>1)cout<<tn/n<<' '<<n<<endl,exit(0);
	n=0;
	for(auto i:s)a[n++]=i;
	//repeat(i,0,n)cout<<a[i]<<endl;
	//cout<<n<<endl;
	ans=1e18;
	dfs(0,1);
	cout<<ans<<' '<<tn/ans<<endl;
	return 0;
}