#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<string.h>
#include<math.h>
#include<cassert>
#include<iomanip>
#include<utility>
#include<bitset>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<functional>
#include<algorithm>
#include<memory.h>
#include<assert.h>
#include<numeric>
#include<limits.h>
using namespace std;
int a[1005][1005],d1[1005][1005],d2[1005][1005],d3[1005][1005],d4[1005][1005],n,m,ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)scanf("%d",a[i]+j);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)d1[i][j]=max(d1[i-1][j],d1[i][j-1])+a[i][j];
	}
	for(int i=n;i;i--){
		for(int j=m;j;j--)d2[i][j]=max(d2[i+1][j],d2[i][j+1])+a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j;j--)d3[i][j]=max(d3[i-1][j],d3[i][j+1])+a[i][j];
	}
	for(int i=n;i;i--){
		for(int j=1;j<=m;j++)d4[i][j]=max(d4[i+1][j],d4[i][j-1])+a[i][j];
	}
	for(int i=2;i<n;i++){
		for(int j=2;j<m;j++){
			ans=max(ans,d1[i][j-1]+d2[i][j+1]+d3[i-1][j]+d4[i+1][j]);
			ans=max(ans,d1[i-1][j]+d2[i+1][j]+d3[i][j+1]+d4[i][j-1]);
		}
	}
	printf("%d\n",ans);
	return 0;
}