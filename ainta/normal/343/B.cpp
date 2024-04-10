#include<stdio.h>
char p[100010],st[100010];
int i,top;
int main()
{
	scanf("%s",p);
	for(i=0;p[i];i++){
		if(!top){
			st[++top]=p[i];
			continue;
		}
		if(p[i]==st[top])top--;
		else st[++top]=p[i];
	}
	if(top)printf("No\n");
	else printf("Yes\n");
}