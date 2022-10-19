#include<bits/stdc++.h>
using namespace std;
int n,Z[1000010],A,B;
char s[1000010],a[1000010],b[1000010];
int Zalgo(char *t,char *p,int len){
	int S=len*2+1,l=0,r=0;
	if(!len)return 0;
	memcpy(s,p,len),s[len]='$',memcpy(s+len+1,t,len);
//	for(int i=0;i<S;i++)putchar(s[i]);
	for(int i=1;i<S;i++){
		Z[i]=0;
		if(i<=r)Z[i]=min(Z[i-l],r-i);
		while(i+Z[i]<S&&s[Z[i]]==s[Z[i]+i])Z[i]++;
		if(i+Z[i]>r)l=i,r=i+Z[i];
	}
	for(int i=len;i<S;i++)if(Z[i]==S-i)return S-i;
//	puts(" 0");
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",b),B=strlen(b);
		int len=min(A,B),sz=Zalgo(a+A-len,b,len);
		memcpy(a+A,b+sz,B-sz),A+=B-sz;
	}
	printf("%s",a); 
	return 0;
} 
/*
10
aaaaa aaaaaa aaaa aaaaaaa aaaaa aaaaaa aaaa aa aaaa aaaaa
6
sample please amplease ease in out
*/