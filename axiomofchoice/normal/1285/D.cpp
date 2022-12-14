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
int t,n,x,a[N];
bool test(int p,int l,int r){
	return (a[l]&(1ll<<p))^(a[r-1]&(1ll<<p));
}
int dfs(int p,int l,int r){//cout<<l<<' '<<r<<endl;
	if(p==-1)return 0;
	//if(l>=r)return 0;
	if(!test(p,l,r))return dfs(p-1,l,r);
	int x=l,y=r-1,m;
	while(x<=y){
		m=(x+y)/2;
		if(a[m]&(1ll<<p))y=m-1;else x=m+1;
	}
	m=x;
	//cout<<"::"<<p<<endl;
	return (1ll<<p)+min(dfs(p-1,l,m),dfs(p-1,m,r));
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n)cin>>a[i];
	sort(a,a+n);
	cout<<dfs(31,0,n)<<endl;
	return 0;
}