#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int solve(int a)
{
	for(int i=2; i*i<=a; ++i)
	{
		if(a%i==0)
		{
			return 2;
		}
	}
	return 1;

}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=2; i<=N+1; ++i)
		ans.push_back(solve(i));			
	printf("%d\n",*max_element(ans.begin(), ans.end()));
	for(auto i: ans) printf("%d ",i);
	puts("");
	return 0;
}