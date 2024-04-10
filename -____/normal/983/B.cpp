//CF 983B
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
void cmax(int& x,int y){
	if(x<y)
		x=y;
}
int n,a[N][N];
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",&a[i][i]);
	for(j=1;j<n;j=j+1)
		for(i=1;i+j<=n;i=i+1)
			a[i][i+j]=a[i][i+j-1]^a[i+1][i+j];
	for(j=1;j<n;j=j+1)
		for(i=1;i+j<=n;i=i+1)
			cmax(a[i][i+j],a[i][i+j-1]),cmax(a[i][i+j],a[i+1][i+j]);
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&i,&j);
		printf("%d\n",a[i][j]);
	}
	return 0;
}