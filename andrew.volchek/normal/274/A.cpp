#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;
int s[100005];
set < int > ans;

int main()
{
	int n, k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int b;
		scanf("%d",&s[i]);
	}
	sort(s,s+n);
	for(int i=0;i<n;i++)
	{
		if(!((s[i])%k) && ans.count((s[i])/k))
		{
			continue;
		}
		else
		{
			ans.insert(s[i]);
		}
	}
	printf("%d",ans.size());
	return 0;
}