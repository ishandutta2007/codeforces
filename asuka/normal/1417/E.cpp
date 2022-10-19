#include<bits/stdc++.h>
#define N 300015
#define int long long
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,a[N],b[N],res[32][2];
void solve(int l,int r,int dep){
	if(l>r||dep<0) return;
	// cout <<"dep: " << dep << endl;
	// rep(i,l,r) cout << a[i] << ' ';
	// cout << endl;
	int v = (1<<dep),one,zero,ao,az; one = zero = ao = az = 0;
	rep(i,l,r){
		if(a[i]&v) one++,ao += zero;//yes
		else zero++,az += one;//no
		//cout << a[i] << ' ' << v << ' ' << (a[i]&v) << endl;
		//cout << i << ' ' << one << ' ' << zero << endl;
	}
	// if(az == ao&&az == 0){}
	// else{
	// 	cout << az << ' ' << ao << endl;
	// }
	res[dep][0] += az;res[dep][1] += ao;
	int ll = l,rr = l+one;
	rep(i,l,r){
		if(a[i]&v) b[ll++] = a[i];
		else b[rr++] = a[i];
	}
	rep(i,l,r) a[i] = b[i];
	solve(l,ll-1,dep-1);solve(ll,r,dep-1);
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&n);
 	rep(i,1,n) scanf("%lld",&a[i]);
 	solve(1,n,30);int x,ans;x = ans = 0;
 	rep(i,0,30){
 		if(res[i][0] > res[i][1]) x += (1<<i);
 		ans += min(res[i][0],res[i][1]);
 	}
 	printf("%lld %lld\n",ans,x);
	return 0;
}