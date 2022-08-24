#include<stdio.h>
char p[10];
int a,b,c;
int main(){
	scanf("%s",p);
	a=(p[0]-'0')*600+(p[1]-'0')*60+(p[3]-'0')*10+(p[4]-'0');
	while(1){
		a++;
		if(a==1440) a=0;
		b=a/60,c=a%60;
		if(b%10==c/10&&b/10==c%10) break;}
	printf("%d%d:%d%d\n",b/10,b%10,c/10,c%10);
}