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
#define SZ(x) ((int)x.size())
using namespace std;
int n,m,k,a[N],b[N],dp[2][(1<<20)+11],p[N],pp[N],ppp[N];
char s[N],t[N],cur[N];
void upd(int flag,int s,int val){
	if(flag == 0) dp[flag][s] = min(dp[flag][s],val);
	else          dp[flag][s] = max(dp[flag][s],val);
}
int get(char S[]){
	int res = 0;
	rep(i,1,k) res += ((S[i]-'0')<<(i-1));
	return res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",s+1,t+1);
	memset(dp[0],0x3f,sizeof dp[0]);
	memset(dp[1],0xc0,sizeof dp[1]);
	rep(i,1,n) scanf("%d%d",&a[i],&b[i]);
	rep(i,1,k) p[i] = i;
	per(i,1,n){
		rep(j,1,k) cur[j] = t[p[j]];
		upd(1,get(cur),i);
		// printf("t: %s %d\n",cur+1,i);
		rep(j,1,k) pp[j] = j;
		swap(pp[a[i]],pp[b[i]]);
		rep(j,1,k) ppp[j] = pp[p[j]];
		rep(j,1,k) p[j] = ppp[j];
		// rep(j,1,k) printf("%d ",p[j]);
		// printf("\n");
		rep(j,1,k) cur[j] = s[p[j]];
		upd(0,get(cur),i);
		// printf("s: %s %d\n",cur+1,i);
	}
	int all = (1<<k)-1;
	per(s,0,all){
		rep(i,1,k){
			if((1<<(i-1))&s){
				dp[0][s^(1<<(i-1))] = min(dp[0][s^(1<<(i-1))],dp[0][s]);
				dp[1][s^(1<<(i-1))] = max(dp[1][s^(1<<(i-1))],dp[1][s]);
			}
		}
	}
	int p = __builtin_popcount(get(s)),q = __builtin_popcount(get(t));
	int ans = 0,al,ar;
	rep(s,0,all){
		int l = dp[0][s],r = dp[1][s];
		if(r-l+1 >= m){
			int cnt = __builtin_popcount(s);
			if(cnt >= ans) ans = cnt,al = l,ar = r;
		}
	}
	printf("%d\n%d %d\n",ans*2+k-p-q,al,ar);
	return 0;
}