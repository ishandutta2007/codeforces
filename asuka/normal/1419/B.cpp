#include<bits/stdc++.h>
#define int long long
#define N 1000015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,x,val[N];
int qpow(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = res*a;
		a = a*a;
		b>>=1;
	}
	return res;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>t;n = 31;
 	rep(i,1,n) val[i] = val[i-1]*2+qpow(4,i-1);
 	rep(i,1,n) val[i] += val[i-1];//,cout << val[i] << endl;
 	while(t--){
 		cin>>x;
 		int l = 1,r = n,ans = 0;
 		while(l+3 < r){
 			int mid = (l+r)>>1;
 			if(val[mid] <= x) l = mid;
 			else r = mid;
 		}
 		rep(i,l,r){
 			if(val[i] <= x) ans = max(ans,i);
 		}
 		cout << ans << endl;
 	}
	return 0;
}