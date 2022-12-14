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
int t,n,x,f,a[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int s=0,sum=0,m=0;
		repeat(i,0,n)cin>>a[i],s+=a[i];
		int l=0;
		repeat(i,0,n-1){
			sum+=a[i];
			if(sum<0)sum=0;
			m=max(m,sum);
		}
		sum=0,l=1;
		repeat(i,1,n){
			sum+=a[i];
			if(sum<0)sum=0;
			m=max(m,sum);
		}
		if(m>=s)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}