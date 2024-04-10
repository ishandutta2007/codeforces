#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define mod 998244353
#define ull unsigned long long
using namespace std;
ull bs[64];
int f[36][36][1<<16];
int ans[64];
int pc[1<<16];
int main(){
	int n,m;
	cin>>n>>m;
	int md=min(m,(m+4)/2);
	for(int i=1;i<=n;++i){
		ull a;
		scanf("%llu",&a);
		for(int j=m-1;j>=0;--j)if(a&(1ull<<j)){
			if(!bs[j]){
				bs[j]=a;
				break;
			}else{
				a^=bs[j];
			}
		}
	}
	int cn=0;
	for(int i=m-1;i>=0;--i)if(bs[i]){
		++cn;
		for(int j=i-1;j>=0;--j)
			if(bs[i]&(1ull<<j))bs[i]^=bs[j];
	}
	if(cn<=md){
		vector<ull>bp;
		for(int i=0;i<m;++i)if(bs[i])
			bp.emplace_back(bs[i]);
		for(int i=0;i<(1<<cn);++i){
			ull yh=0;
			for(int j=0;j<cn;++j)if(i&(1ull<<j)){
				yh^=bp[j];
			}
			int pc=0;
			for(int j=0;j<m;++j)
				if(yh&(1ull<<j))++pc;
			++ans[pc];
		}
	}else{
		vector<ull>bp;
		int sy=m-cn;
		ull pb=0;
		for(int i=0;i<m;++i)if(!bs[i])pb|=1ull<<i;
		for(int i=0;i<m;++i)if(bs[i]){
			long long pp=pb;
			ull sb=0;
			for(int j=0;j<sy;++j){
				long long ls=pp&-pp;
				if(bs[i]&ls)sb|=1ull<<j;
				pp^=ls;
			}
			bp.emplace_back(sb);
		}
		for(int i=0;i<=cn;++i)f[i][0][0]=1;
		for(int i=1;i<=cn;++i){
			ull zz=bp[i-1];
			for(int j=1;j<=i;++j)
				for(int k=0;k<(1<<sy);++k){
					f[i][j][k]=f[i-1][j][k];
					f[i][j][k]+=f[i-1][j-1][k^zz];
					if(f[i][j][k]>=mod)f[i][j][k]-=mod;
				}
		}
		for(int i=0;i<(1<<sy);++i){
			if(i)pc[i]=pc[i^(i&-i)]+1;
			for(int j=0;j<=cn;++j){
				ans[pc[i]+j]+=f[cn][j][i];
				if(ans[pc[i]+j]>=mod)ans[pc[i]+j]-=mod;
			}
		}
	}
	int cj=1;
	for(int i=1;i<=n-cn;++i){
		cj+=cj;
		if(cj>=mod)cj-=mod;
	}
	for(int i=0;i<=m;++i){
		int aa=1ll*ans[i]*cj%mod;
		printf("%d",aa);
		if(i==m)putchar('\n');
		else putchar(' ');
	}
	return 0;
}