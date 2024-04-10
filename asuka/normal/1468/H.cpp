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
int T,n,k,m;
int t[N],suf[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&m);
		rep(i,1,n) t[i] = 1;
		rep(i,1,m){
			int x; scanf("%d",&x); t[x] = 0;
		}
		suf[n+1] = 0;
		per(i,1,n) suf[i] = suf[i+1]+t[i];
		int sum = 0,flag = (n==m);
		rep(i,1,n){
			sum += t[i];
			int l = sum,r = suf[i+1];
			if(t[i] == 0) flag |= (min(l,r) >= (k-1)/2);
		}
		flag &= ((n-m)%(k-1) == 0);
		puts(flag?"YES":"NO");
	}
	return 0;
}