#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const int maxn=(2e5)+10;
int n,l,r,d[3];
ll dp[maxn][3];
int f(int a,int x) {
	if (a<x) return 0;
	if (x==0) return a/3;
	return (a-x)/3+1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(l); read(r);
	for (int i=0;i<3;i++) d[i]=f(r,i)-f(l-1,i);
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<3;j++)
			for (int k=0;k<3;k++)
				dp[i][j]=(dp[i][j]+dp[i-1][k]*d[(j-k+3)%3])%mod;
	printf("%lld\n",dp[n][0]);
	return 0;
}