#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
const int N=1e6+3;
int f[N],g[N],s[N];
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		for(j=i;j<=n;j+=i)++g[j];
		f[i]=(s[i-1]+g[i])%P;
		s[i]=(s[i-1]+f[i])%P;
	}
	cout<<f[n];
	return 0;
}