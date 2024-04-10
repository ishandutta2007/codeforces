/*
swaping:
single swap:OK
double swap:FAIL [can be replaced by a deletion and an insert]
swap then replace:FAIL [if R+S>=I+D, then pick I+D; otherwise R<=S must hold, then just replace twice]
delete,swap,insert:OK,
*/
#include<bits/stdc++.h>
using namespace std;
int I,D,R,S,n,m;
char s[4010],t[4010];
int f[4010][4010],a[4010][26],b[4010][26];
void chmn(int&x,int y){if(x>y)x=y;}
int main(){
	scanf("%d%d%d%d%s%s",&I,&D,&R,&S,s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	memset(f,0x3f,sizeof(f));
	for(int i=2;i<=n;i++){for(int j=0;j<26;j++)a[i][j]=a[i-1][j];a[i][s[i-1]-'a']=i-1;}
	for(int i=2;i<=m;i++){for(int j=0;j<26;j++)b[i][j]=b[i-1][j];b[i][t[i-1]-'a']=i-1;}
	for(int i=0;i<=n;i++)f[i][0]=i*D;
	for(int i=0;i<=m;i++)f[0][i]=i*I;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		chmn(f[i][j],f[i-1][j]+D);
		chmn(f[i][j],f[i][j-1]+I);
		chmn(f[i][j],f[i-1][j-1]+((s[i]!=t[j])?R:0));
		int x=a[i][t[j]-'a'],y=b[j][s[i]-'a'];
		if(x&&y)chmn(f[i][j],f[x-1][y-1]+D*(i-x-1)+I*(j-y-1)+S);
	}
	printf("%d\n",f[n][m]);
	return 0;
}