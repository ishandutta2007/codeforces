#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,a[100100],buc[100100],lim,res;
vector<int>v;
void pa(int x){
	v.clear();
	int i=1;
	for(;i*i<=x;i++)if(!(x%i))v.push_back(i);
	for(i--,i-=(i*i==x);i;i--)if(!(x%i))v.push_back(x/i);
}
int ksm(int x,int y){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1),lim=a[n];
	for(int i=1,j=1;i<=lim;i++){
		pa(i);
		while(j<=n&&a[j]<i)j++;
		buc[i]=n-j+1;
		int now=1;
		for(int k=1;k<v.size();k++)now=1ll*now*ksm(k,buc[v[k-1]]-buc[v[k]])%mod;
		now=1ll*now*(ksm(v.size(),buc[i])+mod-ksm(v.size()-1,buc[i]))%mod;
		(res+=now)%=mod;
	}
//	for(int i=1;i<=lim;i++)printf("%d ",buc[i]);puts("");
	printf("%d\n",res);
	return 0;
}
/*
4
1 4 3 2
2
6 3
1
100
3
2 3 3
*/