#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
typedef double db;
void exec()
{
	int R,r,k;
	scanf("%d%d%d",&R,&r,&k);
	register int i;
	db Alt=-1.0/R,Pnt=1.0/r,Ctr=1.0/(R-r),tmp;
	Pnt=Alt+Pnt+Ctr,tmp=Pnt-Ctr;
	for(i=2;i<=k;i++)Alt=Ctr,Ctr=Pnt,Pnt=2*(tmp+Pnt)-Alt;
	printf("%.15lf\n",1/Pnt);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Just go for it.
*/