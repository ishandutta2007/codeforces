#define HELL_DESCRIPTION_CHANGE
#include<cstdio>
#include<vector>
using namespace std;
vector<int> vec[100100];
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	int ans=2*N-K-1;
	for(int i=0;i<K;i++)
	{
		int t;
		scanf("%d",&t);
		bool cntok=false;
		for(int j=0;j<t;j++)
		{
			int q;
			scanf("%d",&q);
			if(cntok && q==j+1)
				ans-=2;
			else
				cntok=false;
			if(q==1) cntok=true;
			
		}
	}
	printf("%d",ans);
}