#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll;
#define int ll
int n,a[N];
signed main(){
	cin>>n;
	repeat(i,0,n)cin>>a[i];
	int ans=0;
	repeat_back(k,-30,30+1){
		int now=-1e9;
		repeat(i,0,n){
			if(now<0)now=a[i];
			else now+=a[i];
			ans=max(ans,now-k);
		}
		repeat(i,0,n)if(a[i]==k)a[i]=-1e9;
	}
	cout<<ans<<endl;
	return 0;
}