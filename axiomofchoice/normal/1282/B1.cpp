#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //typedef __int128 lll;
typedef pair<int,int> pii;
typedef long long lf;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define qwq {cout<<"qwq"<<endl;}
const int N=200010;
const int inf=1e9;
const int mod=1000000007;
#define int ll
ll t,n,p,k;
ll a[N];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>p>>k;
		ll ans=0;
		repeat(i,0,n){
			cin>>a[i];
		}
		sort(a,a+n);
		repeat(i,0,n){
			if(i>=k)a[i]+=a[i-k];
			if(a[i]<=p)
				ans=i+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}