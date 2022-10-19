#include<bits/stdc++.h>
using namespace std;
const int N=(1<<21)+5;
typedef unsigned long long ull;
int n,lim;
char s[N],t[N];
void FMT(ull*a,int tp){
	for(int i=0;i<n;i++)for(int j=0;j<lim;j++)if(j&(1<<i))a[j]+=tp*a[j^(1<<i)];
}
ull f[N],g[N];
int main(){
	scanf("%d%s%s",&n,s,t),lim=1<<n;
	for(int i=0;i<lim;i++)
		f[i]=(ull)(s[i]-'0')<<(__builtin_popcount(i)<<1),g[i]=(ull)(t[i]-'0')<<(__builtin_popcount(i)<<1);
	FMT(f,1),FMT(g,1);
	for(int i=0;i<lim;i++)f[i]*=g[i];
	FMT(f,-1);
	for(int i=0;i<lim;i++)printf("%d",(f[i]>>(__builtin_popcount(i)<<1))&3);
	return 0;
}