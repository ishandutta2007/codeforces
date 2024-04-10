#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=100010; typedef long long ll; const int inf=~0u>>2; typedef pair<int,int> pii;
#define int ll
int T,n,k;
int a[N],b[N];
signed main(){
	cin>>T;
	while(T--){
		ll sum=0;
		cin>>n>>k;
		repeat(i,0,n)cin>>a[i],sum+=a[i];
		repeat(i,0,n)cin>>b[i];
		sort(a,a+n);
		sort(b,b+n,greater<int>());
		repeat(i,0,k){
			if(a[i]>=b[i])break;
			sum+=b[i]-a[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}