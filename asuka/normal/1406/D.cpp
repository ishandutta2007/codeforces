#include<bits/stdc++.h>
#define int long long
#define N 100015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,q,a[N],D[N],l[N],r[N],val[N],pos,neg,ans[N];
void change(int p,int x){
	if(p == 1||p>n) return;
	if(D[p] > 0){
 		if(D[p] + x < 0) pos -= D[p],neg += D[p] + x;
 		else pos += x;
 	}else{
 		if(D[p] + x > 0) neg -= D[p],pos += D[p] + x;
 		else neg += x;
 	}
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin>>n;
 	rep(i,1,n) cin>>a[i];
 	cin>>q;
 	rep(i,1,q) cin>>l[i]>>r[i]>>val[i];
 	pos = neg = 0;
 	rep(i,1,n) D[i] = a[i]-a[i-1];
 	rep(i,2,n) {
 		if(D[i]>0) pos += D[i];
 		else neg += D[i];
 	}
 	rep(i,0,q){
 		if(i != 0) {
 			change(l[i],val[i]);change(r[i]+1,-val[i]);
 			D[l[i]] += val[i];D[r[i]+1] -= val[i];
 		}
 		ans[i] = (int)floor(1.0*(D[1]+pos+1)/2);
 	}
 	// reverse(a+1,a+n+1);
 	// rep(i,1,n) l[i] = n-l[i]+1,r[i] = n-r[i]+1;
 	// pos = neg = 0;
 	// rep(i,1,n) D[i] = a[i]-a[i-1];
 	// rep(i,2,n) {
 	// 	if(D[i]>0) pos += D[i];
 	// 	else neg += D[i];
 	// }
 	// rep(i,0,q){
 	// 	if(i != 0) {
 	// 		change(l[i],val[i]);change(r[i]+1,-val[i]);
 	// 		D[l[i]] += val[i];D[r[i]+1] -= val[i];
 	// 	}
 	// 	ans[i] = max(ans[i],(int)floor(1.0*(D[1]+pos+1)/2));
 	// }
 	rep(i,0,q) cout << ans[i] << endl;
	return 0;
}