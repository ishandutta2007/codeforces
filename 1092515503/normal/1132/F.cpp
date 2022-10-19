#include<bits/stdc++.h>
using namespace std;
int f[511][511],n;//f[i][j]:the maximum of merging times while solve section [i,j]
char s[511],c;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		c=getchar();
		while(c>'z'||c<'a')c=getchar();
//		printf("%c",c);
		if(s[i-1]==c)i--,n--;
		else s[i]=c;
	}
	for(int i=n-2;i>=1;i--)for(int j=i+2;j<=n;j++){
		f[i][j]=f[i+1][j];
		for(int k=i+2;k<=j;k++)if(s[i]==s[k])f[i][j]=max(f[i][j],1+f[i+1][k-1]+f[k][j]);
	}
	printf("%d\n",n-f[1][n]);
	return 0;
}