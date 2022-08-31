#include<stdio.h>
#include<string.h>
int Q,n,i,prv,j,C,c,O;
char p[100],res[100];
int main()
{
	scanf("%d",&Q);
	while(Q--){
		O=-1;
		scanf("%s",p);
		n=strlen(p);
		prv=-1;
		c=0;
		C=0;
		for(i=0;i<n;i++){
			if(p[i]==':'){
				if(i!=0){
					C++;
					for(j=0;j<5-(i-prv);j++)res[c++]='0';
					for(j=prv+1;j<=i;j++)res[c++]=p[j];
				}
				if(p[i+1]==':'){
					O=c;
					prv=i+1;
					i++;
					continue;
				}
				prv=i;
			}
		}
		if(prv!=-1&&prv!=n-1){
			C++;
			for(j=0;j<5-(i-prv);j++)res[c++]='0';
			for(j=prv+1;j<i;j++)res[c++]=p[j];
		}
		if(O==-1){printf("%s\n",res);continue;}
		for(i=0;i<O;i++)printf("%c",res[i]);
		for(i=0;i<8-C;i++){
			if(i!=7-C)printf("0000:");
			else printf("0000");
		}
		if(O!=c)printf(":");
		for(i=O;i<c;i++)printf("%c",res[i]);
		printf("\n");
	}
}