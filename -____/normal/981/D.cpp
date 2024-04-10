//CF 981D
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
const int N = 59;
int n,k,f[N][N];
LL a[N],s[N],b[N][N];
int chk(LL t){
	int i,j,l;
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=k;j=j+1)
			for(l=1;l<=i;l=l+1)
				if((b[l][i]&t)==t)
					f[i][j]|=f[l-1][j-1];
	return f[n][k];
}
int main()
{
	int i,j;
	LL t=0;
	cin>>n>>k;
	for(i=1;i<=n;i=i+1)
		cin>>a[i],s[i]=s[i-1]+a[i];
	for(i=1;i<=n;i=i+1)
		for(j=i;j<=n;j=j+1)
			b[i][j]=s[j]-s[i-1];
	for(i=60;i>=0;i=i-1){
		if(chk(t|((LL)1<<i)))
			t|=((LL)1<<i);
	}
	cout<<t;
	return 0;
}