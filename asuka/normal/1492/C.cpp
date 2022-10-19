#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int n,m,Min[N];
char s[N],t[N];
VI pos[26];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1); scanf("%s",t+1);
	rep(i,1,n) pos[s[i]-'a'].pb(i);
	Min[m] = pos[t[m]-'a'].back();
	Min[m+1] = n+1;
	per(i,1,m-1) {
		Min[i] = *(--lower_bound(pos[t[i]-'a'].begin(),pos[t[i]-'a'].end(),Min[i+1]));
	}
	// rep(i,1,m) printf("%d ",Min[i]); printf("\n");
	int lst = 0,ans = 1;
	rep(i,1,m){
		if(lst){
			int Mx = *(--lower_bound(pos[t[i]-'a'].begin(),pos[t[i]-'a'].end(),Min[i+1]));
			// printf("Min: %d Mx: %d\n",Min[i+1],Mx);
			ans = max(ans,Mx-lst);
		}
		lst = *upper_bound(pos[t[i]-'a'].begin(),pos[t[i]-'a'].end(),lst);
		// printf("%d\n",lst);
	}
	printf("%d\n",ans);
	return 0;
}