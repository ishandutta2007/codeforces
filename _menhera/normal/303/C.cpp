#include<cstdio>
#include<algorithm>
#include<unordered_set>
using namespace std;
int A[5050];
pair<int,int> rem[1010101][11];
pair<int,int> nrem[1010101][11];
int tp[1010101];
int ntp[1010101];
int N,K;
int main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
		scanf("%d",A+i);
	sort(A,A+N);
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
		{
			int d=A[j]-A[i];
			if(tp[d]==-1) continue;  
			rem[d][tp[d]++]=make_pair(i,j);
			if(tp[d]>(K*(K+1)/2)) tp[d]=-1;
		}
	for(int i=1;i<=1000000;i++)
	{
		if(tp[i]==-1)
		{
			ntp[i]=-1;
			continue;
		}
		for(int j=i;j<=1000000;j+=i)
		{
			if(tp[j]==-1)
			{
				ntp[i]=-1;
				break;
			}
			if(ntp[i]+tp[j]>(K*(K+1)/2))
			{
				ntp[i]=-1;
				break;
			}
			for(int k=0;k<tp[j];k++)
			{
				nrem[i][ntp[i]+k]=rem[j][k];
			}
			ntp[i]+=tp[j];
		}
		if(ntp[i]==-1) continue;
		unordered_set<int> S;
		for(int j=0;j<ntp[i];j++)
		{
			S.insert(nrem[i][j].first);
		}
		if(S.size()<=K)
		{
			printf("%d\n",i);
			return 0;	
		}
	}
	printf("1000001\n");
	return 0;
}