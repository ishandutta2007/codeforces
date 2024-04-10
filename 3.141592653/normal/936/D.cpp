#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
#include<map>
std::map<int,int>m;
int T[4444444],V[4444444],R[4444444],top;
int n,m0,m1,t;
int F[4444444][2];
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x<y)?y:x;}
bool REV[4444444],FLS[4444444];
int AVG[4444444],pp;
void print()
{
	register int i;
	int CR=0,CS=0;
	for(i=0;i<=top;i++)
		if(REV[i])CR++;
	printf("%d\n",CR);
	for(i=0;i<=top;i++)if(REV[i])printf("%d ",T[i]);puts("");
	int Ec=n-1;
	for(i=top;i;i--)
		if(FLS[i])
		{
			if(Ec>T[i]-1)Ec=T[i]-1;
			AVG[++CS]=Ec,Ec-=t;
		}
	printf("%d\n",CS);
	int P=0;
	for(i=0;i<top;i++)
	{
		if(REV[i])P=!P;
		for(;CS&&AVG[CS]<T[i+1];CS--)
			printf("%d %d\n",AVG[CS],P+1);
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m0,&m1,&t);
	register int i;
	int x;
	for(i=1;i<=m0;i++)
		scanf("%d",&x),m[x]|=5,m[x+1]|=4,m[x-1]|=4;
	for(i=1;i<=m1;i++)
		scanf("%d",&x),m[x]|=6,m[x+1]|=4,m[x-1]|=4;
	for(auto ii:m)T[++top]=ii.first,V[top]=ii.second;
	R[0]=2;
	for(i=1;i<=top;i++)
	{
		int delT=T[i]-T[i-1];
		F[i][0]=F[i-1][0]+delT;
		F[i][1]=F[i-1][1]+delT;
		if(V[i]&1){F[i][0]-=t;if(F[i][0]<=0)F[i][0]=-2e9;}
		if(V[i]&2){F[i][1]-=t;if(F[i][1]<=0)F[i][1]=-2e9;}
		if((V[i]&1)==0)
		{
			int Rf=min(t,F[i][1]);
			if(Rf>F[i][0])F[i][0]=Rf,R[i]=1;
		}
		if((V[i]&2)==0)
		{
			int Rf=min(t,F[i][0]);
			if(Rf>F[i][1])F[i][1]=Rf,R[i]=2;
		}
	}if(F[top][0]<0&&F[top][1]<0)return puts("No"),0;
	puts("Yes");
	int X=top,Y=0;
	if(F[X][Y]<0)Y=1;
	for(;~X;X--)
	{
		if(R[X]==Y+1)REV[X]=1,Y=!Y;
		if(V[X]&(1<<Y))FLS[X]=1;
	}print();
}
/*
Just go for it.
*/