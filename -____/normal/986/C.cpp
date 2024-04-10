//CF 986C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 22;
const int W = 1<<N;
int n,m,w,a[W],aa[W],b[W],bb[W],f[W],ans[W];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	w=(1<<n)-1;
	for(i=1;i<=m;i=i+1){
		scanf("%d",&j);
		a[j]=1,aa[j]=1;
		b[w^j]=1,bb[w^j]=1;
	}
	for(j=0;j<n;j=j+1){
		for(i=0;i<=w;i=i+1){
			if(i&(1<<j)){
				aa[i]|=aa[i^(1<<j)];
				bb[i^(1<<j)]|=bb[i];
			}
		}
	}
	for(i=0;i<=w;i=i+1)
		f[i]=i;
	for(j=0;j<n;j=j+1){
		for(i=0;i<=w;i=i+1){
			if((i&(1<<j))&&bb[i]&&aa[i^(1<<j)]){
				f[fnd(i^(1<<j))]=fnd(i);
			}
		}
	}
	for(i=0;i<=w;i=i+1)
		if(a[i])
			f[fnd(i)]=fnd(w^i);
	for(i=0;i<=w;i=i+1)
		if(a[i])
			ans[fnd(i)]=1;
	j=0;
	for(i=0;i<=w;i=i+1)
		j+=ans[i];
	cout<<j;
	return 0;
}