//CF 919C
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
int n,m,k,a[2222][2222];
char ch[2222];
int main()
{
	int i,j,l,ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i=i+1){
		scanf("%s",ch+1);
		l=0;
		for(j=1;j<=m;j=j+1){
			a[i][j]=(ch[j]=='.');
			if(!a[i][j])
				l=j;
			else{
				if(j-l>=k)
					ans++;
			}
		}
	}
	if(k==1)
		ans=0;
	for(j=1;j<=m;j=j+1){
		l=0;
		for(i=1;i<=n;i=i+1)
			if(!a[i][j])
				l=i;
			else{
				if(i-l>=k)
					ans++;
			}
	}
	printf("%d",ans);
	return 0;
}