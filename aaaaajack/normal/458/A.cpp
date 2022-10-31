#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100100
using namespace std;
char s1[N],s2[N];
int c1[N]={0},c2[N]={0};
int main(){
	scanf("%s %s",s1,s2);
	int i,j,l1=strlen(s1),l2=strlen(s2),tmp;
	for(i=0;s1[i];i++){
		c1[l1-1-i]=s1[i]-'0';
	}
	for(i=0;s2[i];i++){
		c2[l2-1-i]=s2[i]-'0';
	}
	tmp=0;
	for(i=0;i<=l1;i++){
		if(c1[i]) tmp++;
		else{
			for(j=0;j<tmp/2;j++){
				c1[i-j*2]=1;
				c1[i-j*2-1]=0;
				c1[i-j*2-2]=0;
			}
			if(tmp<2) tmp=0;
			else tmp=1;
		}
	}
	tmp=0;
	for(i=0;i<=l2;i++){
		if(c2[i]) tmp++;
		else{
			for(j=0;j<tmp/2;j++){
				c2[i-j*2]=1;
				c2[i-j*2-1]=0;
				c2[i-j*2-2]=0;
			}
			if(tmp<2) tmp=0;
			else tmp=1;
		}
	}
	for(i=max(l1,l2);i>=0;i--){
		if(c1[i]>c2[i]){
			puts(">");
			break;
		}
		else if(c1[i]<c2[i]){
			puts("<");
			break;
		}
	}
	if(i==-1){
		puts("=");
	}
	return 0;
}