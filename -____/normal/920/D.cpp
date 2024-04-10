//CF 920D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 5005;
const int inf = 1e9;
void dao(int x,int y,int z){
	if(x)
		printf("%d %d %d\n",x,y,z);
}
int n,k,v,a[N],b[N];
bool f[N][N],g[N][N];
int main()
{
	int i,j,t,r,s=0;
	scanf("%d%d%d",&n,&k,&v);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i),s+=a[i];
	if(s<v){
		printf("NO\n");
		return 0;
	}
	if(v%k==0){
		printf("YES\n");
		for(i=2;i<=n;i=i+1)
			if(a[i])
				dao((a[i]-1)/k+1,i,1);
		dao(v/k,1,2);
		return 0;
	}
	f[0][0]=1;
	for(i=1;i<=n;i=i+1)
		for(j=0;j<k;j=j+1){
			if(f[i-1][j])
				f[i][j]=1,g[i][j]=0;
			if(f[i-1][(j-a[i]%k+k)%k])
				f[i][j]=1,g[i][j]=1;
		}
	if(!f[n][v%k]){
		printf("NO\n");
		return 0;
	}
	j=v%k;
	for(i=n;i>=1;i=i-1){
		if(g[i][j])
			b[i]=1,t=i,j=(j-a[i]%k+k)%k;
		else
			b[i]=0,r=i;
	}
	printf("YES\n");
	s=a[t];
	for(i=1;i<=n;i=i+1)
		if(a[i]&&b[i]&&i!=t)
			dao((a[i]-1)/k+1,i,t),r=i,s+=a[i];
	for(i=1;i<=n;i=i+1)
		if(a[i]&&!b[i]&&i!=r)
			dao((a[i]-1)/k+1,i,r);
	if(s>=v)
		dao((s-v)/k,t,r);
	else
		dao((v-s)/k,r,t);
	return 0;
}