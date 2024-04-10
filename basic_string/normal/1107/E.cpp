#include<bits/stdc++.h>
using namespace std;
const int N=109;
int a[N];
long long f[N][N][N];
char s[N];
long long wk(int l,int r,int k){
	if(l>r)return 0;
	if(f[l][r][k])return f[l][r][k];
	if(l==r)return a[k+1];
	int i;
	long long w=wk(l,r-1,0)+a[k+1];
	for(i=l;i<r;++i)if(s[i]==s[r])w=max(w,wk(l,i,k+1)+wk(i+1,r-1,0));
	return f[l][r][k]=w; 
}
int main(){
	int n,i;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	printf("%lld",wk(1,n,0)); 
	return 0;
}