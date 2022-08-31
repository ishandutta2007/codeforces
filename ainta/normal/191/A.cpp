#include<stdio.h>
#include<string.h>
int n,i,j,k,m,D[26][26],R,D2[26][26],r[500001];
char a[20],p[500001][2];
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",a);
		m=strlen(a);r[i]=m;
		p[i][0]=a[0]-'a',p[i][1]=a[m-1]-'a';
		for(j=0;j<m;j++)a[j]=0;}
	D[p[0][0]][p[0][1]]=r[0],D2[p[0][0]][p[0][1]]=r[0];
	for(i=1;i<n;i++){
		for(j=0;j<26;j++)if(D[j][j]>R)R=D[j][j];
		for(j=0;j<26;j++){
			if(D[j][p[i][0]]!=0&&D[j][p[i][0]]+r[i]>D2[j][p[i][1]])D2[j][p[i][1]]=D[j][p[i][0]]+r[i];}
		if(D2[p[i][0]][p[i][1]]<r[i])D2[p[i][0]][p[i][1]]=r[i];
		for(j=0;j<26;j++)D[j][p[i][1]]=D2[j][p[i][1]];
	}
	for(i=0;i<26;i++)if(D[i][i]>R)R=D[i][i];
	printf("%d\n",R);
}