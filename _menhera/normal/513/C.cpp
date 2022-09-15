#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	int L[5],R[5];
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d%d",L+i,R+i);
	double sbid[10002][5];
	double nsbid[10002][5];
	double sumsbid[10002][5];
	for(int i=1;i<=10000;i++)
	{
		for(int j=0;j<N;j++)
		{
			sbid[i][j]=1;
			for(int k=0;k<N;k++)
			{
				if(j==k) continue;
				sbid[i][j]*=max(min(R[k],i)-L[k]+1,0);
			}
			nsbid[i][j]=i*(sbid[i][j]-sbid[i-1][j]);
			sumsbid[i][j]=sumsbid[i-1][j]+nsbid[i][j];
			//printf("%d, %d, %I64d\n",i,j,sbid[i][j]);
		}
	}
	double total=0;
	for(int j=0;j<N;j++)
	{
		for(int i=L[j];i<=R[j];i++)
			total+=sumsbid[i-1][j];
	}
	for(int mbid=1;mbid<=10000;mbid++)
	{
		double prodX=1;
		double prodY=1;
		double mbidval=0;
		for(int i=0;i<N;i++)
		{
			prodX*=max(min(R[i],mbid)-L[i]+1,0);
			prodY*=max(min(R[i],mbid-1)-L[i]+1,0);
			if(L[i]<= mbid && mbid<=R[i]) mbidval+=sbid[mbid-1][i];
		}
		total+=(prodX-prodY-mbidval)*mbid;
		//printf("%lf %lf %I64d\n",prodX,prodY,mbidval);
	}
	for(int i=0;i<N;i++)
		total/=R[i]-L[i]+1;
	printf("%.12lf",total);
	return 0;
}