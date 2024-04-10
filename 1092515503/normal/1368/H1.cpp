#include<bits/stdc++.h>
using namespace std;
int n,m,q,f[100100][2],res=0x3f3f3f3f;
char s[2][100100],t[2][100100];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s%s%s%s",s[0],s[1],t[0],t[1]);
	f[0][0]=f[0][1]=0;
	for(int i=0;i<n;i++)f[0][s[0][i]=='R']++;
	f[0][t[0][0]=='R']++;
	f[0][t[1][0]=='R']++;
	for(int i=1;i<m;i++){
		f[i][0]=min(f[i-1][0],f[i-1][1]+n);
		f[i][1]=min(f[i-1][1],f[i-1][0]+n);
		f[i][t[0][i]=='R']++;
		f[i][t[1][i]=='R']++;
	}
	for(int i=0;i<n;i++)f[m-1][s[1][i]=='R']++;
	res=min(res,min(f[m-1][0],f[m-1][1]));
	
	f[0][0]=f[0][1]=0;
	for(int i=0;i<m;i++)f[0][t[0][i]=='R']++;
	f[0][s[0][0]=='R']++;
	f[0][s[1][0]=='R']++;
	for(int i=1;i<n;i++){
		f[i][0]=min(f[i-1][0],f[i-1][1]+m);
		f[i][1]=min(f[i-1][1],f[i-1][0]+m);
		f[i][s[0][i]=='R']++;
		f[i][s[1][i]=='R']++;
	}
	for(int i=0;i<m;i++)f[n-1][t[1][i]=='R']++;
	res=min(res,min(f[n-1][0],f[n-1][1]));
	printf("%d\n",res);
	return 0;
}