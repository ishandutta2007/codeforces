#include<stdio.h>
#include<string.h>
char p[1001],q[1001];
int n,i,c,zz;
int main(){
	scanf("%s",p);
	n=strlen(p);
	if(p[0]=='-'){
		for(i=1;i<n;i++){
			if(p[i]!='0'&&p[i]!='.')break;
		}
		if(i==n){printf("$0.00\n");return 0;}
		else printf("(");}
	if(p[0]!='-'){
		for(i=n;i>=1;i--)p[i]=p[i-1];
		p[0]=0,n++;
	}
		printf("$");
		for(i=1;i<n;i++){
			if(p[i]=='.')break;}
		if(i==n){
			for(i=1;i<n;i++){
				if(i!=1&&n%3==i%3){printf(",");}
				printf("%c",p[i]);}
		}
		else{
			zz=i;
			for(i=1;i<n;i++){
				if(p[i]=='.')break;
				if(i!=1&&i%3==zz%3){printf(",");}
				printf("%c",p[i]);
			}
		}
		if(i==n){printf(".00");}
		else{
			printf(".");
			if(n==i+1)printf("00");
			else if(n==i+2)printf("%c0",p[n-1]);
			else printf("%c%c",p[i+1],p[i+2]);
		}
		if(p[0]=='-')printf(")\n");
	
}