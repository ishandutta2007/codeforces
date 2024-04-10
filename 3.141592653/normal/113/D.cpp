#include<cstdio>
#include<vector>
typedef double db;
struct Mat
{
	db a[253][253];
}A[53];
int Sta[25][25],d[25],n,m,a,b,tot;
db p[25],tp[253][253];
std::vector<int>v[25];
void sq(int x,int y)
{
	register int i,ii,iii;
	for(i=0;i<tot;i++)
		for(ii=0;ii<tot;ii++)
			for(iii=0;iii<tot;iii++)
				tp[i][iii]+=A[y].a[i][ii]*A[y].a[ii][iii];
	for(i=0;i<tot;i++)
		for(ii=0;ii<tot;ii++)A[x].a[i][ii]=tp[i][ii],tp[i][ii]=0;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	register int i,ii;
	for(i=1;i<=n;i++)
		for(ii=i;ii<=n;ii++)
			Sta[i][ii]=Sta[ii][i]=tot++;
	for(i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y),d[x]++,d[y]++;
		v[x].push_back(y),v[y].push_back(x);
	}
	for(i=1;i<=n;i++)scanf("%lf",p+i),A[0].a[Sta[i][i]][Sta[i][i]]=1;
	for(i=1;i<=n;i++)
		for(ii=i+1;ii<=n;ii++)
		{
			int Id1=Sta[i][ii],Id2=Id1;
			db P=p[i],Q=p[ii]*P;A[0].a[Id1][Id2]+=Q;
			for(int u:v[ii])
			{
				Q=(1-p[ii])/d[ii]*P,Id2=Sta[i][u],A[0].a[Id1][Id2]+=Q;
			}
			for(int t:v[i])
			{
				P=(1-p[i])/d[i],Q=p[ii]*P,Id2=Sta[t][ii],A[0].a[Id1][Id2]+=Q;
				for(int u:v[ii])
				{
					Q=(1-p[ii])/d[ii]*P,Id2=Sta[t][u],A[0].a[Id1][Id2]+=Q;
				}
			}
		}
	for(i=1;i<=30;i++)sq(i,i-1);
	for(i=1;i<=n;i++)printf("%.12lf ",A[30].a[Sta[a][b]][Sta[i][i]]);puts("");
}
/*
Please don't let me down.
*/