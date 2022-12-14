#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=510; typedef long long ll;
#define int ll
int n,a[N],ans;
signed main(){
	cin>>n;
	repeat(i,0,n)cin>>a[i];
	repeat(i,0,n)
	repeat(j,i,n)
	repeat(k,j,n)
		ans=max(ans,a[i]|a[j]|a[k]);
	cout<<ans<<endl;
	return 0;
}