#include<stdio.h>
#include<string.h>
char p[200001];
int st[200001],n,i,top,a,R=-1,p1,p2,c[200001],st2[200001];
int main()
{
	scanf("%s",p);
	n=strlen(p);
	for(i=0;i<n;i++){
		c[i+1]=c[i];
		if(p[i]==']')c[i+1]++;}
	i=n-1;
	while(i>=0){
		a=i;
		for(i=i;i>=0;i--){
			if(p[i]==']')st[++top]=1,st2[top]=i;
			if(p[i]==')')st[++top]=2,st2[top]=i;
			if(p[i]=='['){
				if(top==0||st[top]!=1)break;
				top--;
			}
			if(p[i]=='('){
				if(top==0||st[top]!=2)break;
				top--;
			}
			if(top==0){
				if(R<c[a+1]-c[i]){
					R=c[a+1]-c[i],p1=i,p2=a;
				}
				continue;
			}
			if(R<c[st2[top]]-c[i]&&st2[top]!=i){
				R=c[st2[top]]-c[i],p1=i,p2=st2[top]-1;
			}
		}
		i--;
		top=0;
	}
	if(R==-1){printf("0\n");return 0;}
	printf("%d\n",R);
	for(i=p1;i<=p2;i++)printf("%c",p[i]);
}