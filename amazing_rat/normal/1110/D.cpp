#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+5;
int n,m,a[maxn],ans;
int dp[2][10][10];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); int x;
	for (int i=1;i<=n;i++) {
		read(x); a[x]++;
	}
	for (int i=1;i<=m;i++) {
		if (a[i]<6) continue;
		else if (a[i]%3==0) ans+=a[i]/3-2,a[i]=6;
		else if (a[i]%3==1) ans+=a[i]/3-2,a[i]=7;
		else ans+=a[i]/3-2,a[i]=8;
	}
	for (int i=1;i<=m;i++) {
		for (int j=0;j<=a[i-1];j++)
		for (int k=0;k<=a[i];k++) {
			if (i<=2) dp[i&1][j][k]=j/3+k/3;
			else {
				x=min(a[i-2],min(j,k));
				for (int X=0;X<=x;X++) {
					dp[i&1][j][k]=max(dp[i&1][j][k],dp[1-i&1][a[i-2]-X][j-X]+X+(k-X)/3);
				}
			}
		}
	}
	printf("%d\n",ans+dp[m&1][a[m-1]][a[m]]);
	return 0;
}