#include<bits/stdc++.h>
using namespace std;
int n,m,all;
bool f[5010][5010];//f[i][j]:after erasing strings in j from the section [1,i-1], whether the (i-j) prefix can be the minimum or not
char s[5010];
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	while((2<<m)<=n)m++;all=(1<<m);
	for(int i=0;i<all;i++)f[i][i]=true;//initial state:erasing all i characters in the prefix
	for(int i=1;i<=n-all+1;i++){
		char lim=127;
		for(int j=i;j<i+all;j++)if(f[j-1][j-i])lim=min(lim,s[j]);//find the minimum on the (i+1)-th character
		putchar(lim);
		for(int j=i;j<i+all;j++)f[j][j-i]=(f[j-1][j-i]&&(s[j]==lim));//leave j+1 empty
		for(int j=i;j<i+all;j++)for(int k=0;k<m;k++)if((j-i)&(1<<k))f[j][j-i]|=f[j-(1<<k)][j-i-(1<<k)];//put something on j+1
	}
	return 0;
}