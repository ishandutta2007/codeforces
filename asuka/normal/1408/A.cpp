#include<bits/stdc++.h>
#define ll long long
#define N 105
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
int t,n,a[N],b[N],c[N],ans[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>t;
 	while(t--){
 		cin>>n;
 		rep(i,1,n) cin>>a[i];
 		rep(i,1,n) cin>>b[i];
 		rep(i,1,n) cin>>c[i];
 		ans[1] = a[1];
 		rep(i,2,n-1) {
 			if(a[i]!=ans[i-1]) ans[i] = a[i];
 			else if(b[i]!=ans[i-1]) ans[i] = b[i];
 			else if(c[i]!=ans[i-1]) ans[i] = c[i];
 		}
 		if(a[n]!=ans[n-1]&&a[n]!=ans[1]) ans[n] = a[n];
 		else if(b[n]!=ans[n-1]&&b[n]!=ans[1]) ans[n] = b[n];
 		else if(c[n]!=ans[n-1]&&c[n]!=ans[1]) ans[n] = c[n];
 		rep(i,1,n) cout << ans[i] << ' ';
 		cout << endl;
 	}
	return 0;
}