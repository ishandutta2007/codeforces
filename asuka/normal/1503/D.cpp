#include<bits/stdc++.h>
#define ll long long
#define N 1114514
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
int n,a[N],b[N],c[N],f[N],pre[N],suf[N];
int t1,t2,s1,s2,c1,c2;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&a[i],&b[i]);
		if(a[i] > b[i]) swap(a[i],b[i]),c[a[i]] = 1;
		if(b[i] <= n){puts("-1"); return 0;}
		f[a[i]] = b[i];
	}
	pre[0] = inf;
	rep(i,1,n) pre[i] = min(pre[i-1],f[i]);
	per(i,1,n) suf[i] = max(suf[i+1],f[i]);
	t1 = t2 = inf,s1 = s2 = c1 = c2 = 0;
	int ans = 0;
	rep(i,1,n){
		if(t1 > t2) swap(t1,t2),swap(s1,s2),swap(c1,c2);
		if(f[i] < t1) t1 = f[i],s1++,c1+=c[i];
		else if(f[i] < t2) t2 = f[i],s2++,c2+=c[i];
		else {puts("-1"); return 0;}
		if(pre[i] > suf[i+1]){
			ans += min(c1+s2-c2,c2+s1-c1);
			t1 = t2 = inf,s1 = s2 = c1 = c2 = 0;
		}
	}
	printf("%d\n",ans);
	return 0;
}