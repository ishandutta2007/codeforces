#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	long long int N;
	int K;
	scanf("%lld%d",&N,&K);
	vector<long long int> div;
	for(long long int i=1; i*i<=N; i++)
	{
		if(i*i==N)
		{
			div.push_back(i);
			break;
		}
		if(N%i==0)
		{
			div.push_back(i);
			div.push_back(N/i);
		}

	}
	sort(div.begin(), div.end());
	if(div.size()<K) printf("-1");
	else printf("%lld",div[K-1]);
	return 0;

}