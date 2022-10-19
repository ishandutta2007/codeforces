#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int mod=998244353;
int T,n,two,zero,fac[100100],inv[100100];
char s[100100];
vector<int>v;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int main(){
	fac[0]=1;for(int i=1;i<=N;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[N]=ksm(fac[N]);for(int i=N;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s),v.clear(),two=0;
		for(int l=0,r;l<n;l=r){
			while(l<n&&s[l]=='0')v.push_back(0),l++;
			r=l;
			while(r<n&&s[r]=='1')r++;
			two+=(r-l)>>1;
			if((r-l)&1)v.push_back(1);
		}
//		for(auto i:v)printf("%d ",i);puts("");
		if(v.empty()){puts("1");continue;}
		zero=v.size()+1;
		for(int i=0;i<v.size();i++)if(v[i]==1)zero--;
//		printf("%d %d\n",zero,two);
		printf("%d\n",1ll*fac[zero+two-1]*inv[zero-1]%mod*inv[two]%mod);
	}
	return 0;
}
/*
6
4
0110
6
011011
5
01010
20
10001111110110111000
1002220202100
*/