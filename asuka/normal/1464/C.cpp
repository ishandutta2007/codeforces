#include<bits/stdc++.h>
#define int long long
#define N 300005
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
int n,pd[26],cnt[26];
int T;
char s[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld",&n,&T);
 	scanf("%s",s+1);
 	pd[0] = 1; rep(i,1,25) pd[i] = pd[i-1]*2;
 	T = T - pd[s[n]-'a'] + pd[s[n-1]-'a'];
 	n -= 2;
 	rep(i,1,n) T += pd[s[i]-'a'],cnt[s[i]-'a']++;
 	per(i,0,25){
 		while(cnt[i]>0 && 2*pd[i] <= T){
 			cnt[i]--; T -= 2*pd[i];
 		}
 	}
 	T==0?puts("Yes"):puts("No");
	return 0;
}