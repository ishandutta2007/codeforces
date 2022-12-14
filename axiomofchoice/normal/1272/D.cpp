#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef double lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=200010;
const int inf=1e9;
const int mod=1000000007;
//#define int ll
int a[N],s[N];
int T,n;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	repeat(i,0,n)cin>>a[i];
	s[0]=1;
	repeat(i,0,n-1)
	if(a[i]<a[i+1])
		s[i+1]=s[i]+1;
	else s[i+1]=1;
	repeat_back(i,0,n-1)
	if(a[i]<a[i+1])
		s[i]=s[i+1];
	int ans=s[0];
	//repeat(i,0,n)cout<<s[i]<<' ';cout<<endl;
	repeat(i,1,n-1){
		ans=max(ans,s[i]);
		if(a[i-1]>=a[i] || a[i]>=a[i+1])
		if(a[i-1]<a[i+1])
			ans=max(ans,s[i-1]+s[i+1]-1);
		//cout<<i<<' '<<s[i-1]<<' '<<s[i+1]<<endl;
	}
	cout<<ans<<endl;
    return 0;
}