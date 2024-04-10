#include<bits/stdc++.h>
#define ll long long
#define N 12015
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
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int sft = 6000;
int n,f[N],g[N],a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n) if(a[i] == 0) a[i] = -1;
	memset(f,inf,sizeof f);
	f[0+sft] = 0;
	rep(i,1,n-1){
		memset(g,inf,sizeof g);
		// printf("i: %d\n",i);
		// rep(j,-i,i) printf("%d %d\n",j,f[j+sft]);
		rep(j,-i,i){
			if(a[i] == -1){
				g[j+sft] = min(g[j+sft],f[j+sft] + abs(j));
				g[j-1+sft] = min(g[j-1+sft],f[j+sft] + abs(j-1));
			}else if(a[i] == 1) g[j+1+sft] = f[j+sft] + abs(j+1);
		}
		swap(f,g);
	}
	int ans = inf;
	if(a[n] == -1) ans = min({ans,f[1+sft],f[0+sft]});
	else ans = min(ans,f[-1+sft]);
	printf("%d\n",ans);
	return 0;
}