#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m,r,tmp;
int cnt,ans;
int s[50],t[50];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(r);
	for (int i=1;i<=n;i++) read(s[i]);
	for (int i=1;i<=m;i++) read(t[i]);
	sort(s+1,s+n+1);
	sort(t+1,t+m+1);
	for (int j=0;j<=r;j++) {
		tmp=r-j; cnt=0;
		for (int i=1;i<=n;i++) {
			while (tmp>=s[i]) cnt++,tmp-=s[i];
		}
		ans=max(ans,j+cnt*t[m]);
	}
	printf("%d\n",ans);
	return 0;
}