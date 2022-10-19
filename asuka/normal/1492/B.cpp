#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
int t,n,p[N],a[N],ans[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&p[i]);
		reverse(p+1,p+n+1);
		rep(i,1,n) a[p[i]] = i;
		int l = 1;
		per(i,1,n){
			int pos = a[i];
			if(pos < l) continue;
			rep(j,l,pos) ans[j] = p[pos-j+l];
			l = pos+1;
		}
		rep(i,1,n) printf("%d ",ans[i]); printf("\n");
	}
	return 0;
}