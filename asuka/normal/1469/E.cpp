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
#define all(x) x.begin(),x.end()
using namespace std;
int t,n,k,cnt[N];
set<int> S;
char s[N];
int Mx;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		S.clear();
 		scanf("%d%d",&n,&k); scanf("%s",s+1);
 		per(i,1,20) if((1<<i) > n) Mx = i;
 		rep(i,1,n) cnt[i] = cnt[i-1] + (s[i] == '0');
 		Mx = min(Mx,k);
 		// printf("Mx: %d\n", Mx);
 		rep(i,k-Mx+1,n-Mx+1){
 			int res = 0;
 			int l = i-k+Mx,r = i-1;
 			if(cnt[r]-cnt[l-1] > 0) continue;
 			rep(d,0,Mx-1){
 				res = res*2 + (s[i+d]-'0');
 			}
 			S.insert(res);
 			// printf("res: %d\n",res);
 		}
 		int ans = -1;
 		per(i,0,(1<<Mx)-1){
 			//printf("i: %d %d\n",i,S.find(i) == S.end());
 			if(S.find(i) == S.end()){ ans = i; break;}
 		}
 		// printf("ans::: %d\n",ans);
 		if(ans == -1) puts("NO");
 		else{
 			puts("YES");
 			rep(i,1,k-Mx) printf("0");
 			per(i,0,Mx-1){
 				if((1<<i)&ans) printf("0");
 				else printf("1");
 			}
 			puts("");
 		}
 	}
	return 0;
}