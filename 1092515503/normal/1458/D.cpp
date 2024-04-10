#include<bits/stdc++.h>
using namespace std;
int T,n,sum,val[1000100];
char s[500100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s),n=strlen(s),sum=0;
		for(int i=0;i<n;i++)s[i]=(s[i]=='1'?1:-1);
		for(int i=0;i<n;i++)val[max(sum,sum+s[i])+n]++,sum+=s[i];
		for(int i=0,j=n;i<n;i++){
			if(val[j]>=2)putchar('0'),val[j--]--;
			else if(val[j+1]>=2)putchar('1'),val[++j]--;
			else if(val[j])putchar('0'),val[j--]--;
			else if(val[j+1])putchar('1'),val[++j]--;
			else{puts("FAIL");return 0;} 
		}puts("");
		for(int i=0;i<=2*n;i++)val[i]=0;
	}
	return 0;
}