#include<cstdio>
#include<vector>
using namespace std;
#define MAXN 262144
int N;
int arr[MAXN];
vector<int> QQ[MAXN];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",arr+i);
	int ans=0;
	for(int k=1;k<N;k++)
		if(arr[k-1]>arr[k]) ans++;
	printf("%d ",ans);
	for(int i=1;i<N;i++)
	{
		int p=(i-1)/1;
		int q=(i-1)%1;
		QQ[2+q/p].push_back(i);
	}
	for(int k=2;k<N;k++)
	{
		for(int j=0;j<QQ[k].size();j++)
		{
			int i=QQ[k][j];
			int p=(i-1)/(k-1);
			if(arr[p]>arr[i]) ans--;
			int np=(i-1)/k;
			int nq=(i-1)%k;
			if(arr[np]>arr[i]) ans++;
			if(np!=0 && k+1+nq/np < N+3 )
				QQ[k+1+nq/np].push_back(i);
		}
		{
			vector<int> nv;
			QQ[k].swap(nv);
		}
		printf("%d ",ans);
	}
	return 0;
	//(x-1)/k = p ... q
	// 5 / 3 = 1 ... 2
	// 5 / 4 = 1 ... 1
	//pk+q = x -1 
	//(x-1)/(k+1) = p ... r
	// pk + p + r = x-1
	// K + q / p turn  ?
}