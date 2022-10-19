#include<bits/stdc++.h>
#define ll long long
#define N 1000015
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
#define int long long
using namespace std;

int notp[N],pri[N],tot,low[N],ans[N],d[N];
bool vis[N];
void getp(int n){
	rep(i,2,n){
		if(!notp[i]) pri[++tot] = i;
		for(int j = i;j <= n;j += i){
			notp[j] = 1;
			if(low[j] == 0){
				low[j] = i;
			}
		}
	}
}
int t,n;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&t); n = 1000000;
 	getp(n);
 //	cout << low[9] << endl;
 	rep(i,2,n){
 		if(low[i]*low[i] == i){
 			d[i]-=2;
 		}else{
 			if(notp[i]){
 				//if(low[i] == 0) cout << i << endl;
 				int p = i/low[i];
 				//cout << p << endl;
 				if(p+(p-1) > low[i]) d[i]--;
 			} 
 		}
 	}
 	//rep(i,1,100) cout << low[i] << ' '; cout << endl;
 	rep(i,1,n) d[i] += d[i-1];
 	rep(i,1,n) ans[i] += i+d[i];
 	// cout << ans[n] << ' ';
 	while(t--){
 		scanf("%lld",&n);
 		//int cnt = 0;
 		// rep(i,1,tot){
 		// 	if(pri[i]*pri[i] <= n) cnt+=2;
 		// 	else if(pri[i] <= n) cnt++;
 		// 	else break;
 		// }
 		printf("%lld\n",ans[n]);
 	}
	return 0;
}