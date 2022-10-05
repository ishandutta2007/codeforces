#include<bits/stdc++.h>
using namespace std;
const int P=1e6+3,N=2007;
int f[N][N];
char s[N];
bool b[N];
int main(){
	int n=1,i,j,l;
	scanf("%s",s),l=strlen(s);
	if(!isdigit(s[l-1]))return puts("0"),0;
	if(!isdigit(s[0])){
		if(s[0]=='*'||s[0]=='/')return puts("0"),0;
		b[++n]=1;
	}
	for(i=1;i<l;++i)if(!isdigit(s[i])){
		++n;
		if(!isdigit(s[i-1])){
			if(s[i]=='*'||s[i]=='/')return puts("0"),0;
			b[n]=1;
		}
	}
	reverse(b+2,b+n+1),f[1][1]=1;
	for(i=2;i<=n;++i)for(j=1;j<=i;++j){
		if(b[i])f[i][j]=(f[i-1][j-1]+f[i][j-1])%P;
		else f[i][j]=(f[i-1][j]+f[i][j-1])%P;
	}
	printf("%d",f[n][n]);
	return 0;
}