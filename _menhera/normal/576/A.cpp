#include<cstdio>
#include<vector>
using namespace std;
bool isPrime(int a)
{
	if(a==1) return false;
	for(int i=2;i*i<=a;i++)
		if(a%i==0) return false;
	return true;
}
int main()
{
	int N;
	scanf("%d",&N);
	vector<int> ans;
	for(int i=2;i<=N;i++)
	{
		if(isPrime(i))
		{
			int a=i;
			while(a<=N)
			{
				ans.push_back(a);
				a*=i;
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
	
}