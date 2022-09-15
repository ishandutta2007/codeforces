#include<cstdio>
#include<vector>
using namespace std;
int ans[1010];
int N;
void req(vector<int> x, int bit, bool parity)
{
	printf("%d\n",x.size());
	for(int y: x) printf("%d ", y+1);
	printf("\n");
	fflush(stdout);
	for(int i=0; i<N; i++)
	{
		int t;
		scanf("%d",&t);
		if(parity == (bool)((1<<bit) & i))
			ans[i] = min(ans[i], t);
	}
}
int main()
{
	
	scanf("%d",&N);
	for(int i=0; i<N; i++) ans[i] = 1e9;
	int i=0;
	while((1<<i)<N)
	{
		vector<int> arr1;
		vector<int> arr2;
		for(int j=0; j<N; j++)
		{
			if(j & (1<<i)) arr1.push_back(j);
			else arr2.push_back(j);
		}
		req(arr1, i, false);
		req(arr2, i, true); 
		i++;
	}
	printf("-1\n");
	for(int i=0; i<N; i++) printf("%d ",ans[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}