#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int N,K;
double solve(vector<int> X,int K)
{
	if(K==0)
	{
		int ret=0;
		for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++)
				if(X[i]>X[j])
					ret++;
		return ret;
	}
	double ans=0;
	for(int i=0;i<N;i++)
	{
		for(int j=i;j<N;j++)
		{
			reverse(X.begin()+i,X.begin()+j+1);
			ans+=solve(X,K-1);
			reverse(X.begin()+i,X.begin()+j+1);
		}
	}
	return ans*2/N/(N+1);
}
int main()
{
	scanf("%d%d",&N,&K);
	vector<int> P(N);
	for(int i=0;i<N;i++) scanf("%d",&P[i]);
	printf("%.12lf",solve(P,K));
}