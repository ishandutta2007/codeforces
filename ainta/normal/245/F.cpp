#include<stdio.h>
int n,m,i,x,c,t;
struct A{
	int M,D,h,m,s;
}w[1000001],PP;
char p[5000010];
void colon(){printf(":");}
void bar(){printf("-");}
void Do(int P){if(P<10)printf("0");printf("%d",P);}
int main()
{
	scanf("%d%d",&n,&m);
	while(1){
		x=-1;
		scanf("%d-%d-%d %d:%d:%d:",&x,&w[c].M,&w[c].D,&w[c].h,&w[c].m,&w[c].s);
		PP=w[c];
		if(x==-1)break;
		gets(p);
		if(m==1)break;
		if(c==0){c++;continue;}
		while(t<c){
			if(w[c].M>=w[t].M+2){
				t++;continue;}
			if(w[c].M==w[t].M+1){
				if(w[c].M==3)w[c].D+=29;
				else if(w[c].M<9){
					if(w[c].M&1)w[c].D+=30;
					else w[c].D+=31;
				}
				else{
					if(w[c].M&1)w[c].D+=31;
					else w[c].D+=30;
				}
			}
			w[c].h+=24*(w[c].D-w[t].D);
			x=(w[c].h-w[t].h)*3600+(w[c].m-w[t].m)*60+w[c].s-w[t].s;
			if(x<n)break;
			t++;
			w[c]=PP;
		}
		if(c-t>=m-1)break;
		w[c]=PP;
		c++;
	}
	if(x==-1){printf("-1\n");return 0;}
	printf("2012-");
	Do(PP.M);bar();Do(PP.D);printf(" ");
	Do(PP.h);colon();Do(PP.m);colon();Do(PP.s);
	return 0;
}