#include<cstdio>
#include<algorithm>

using namespace std;

int s[101];

bool cmp(int x, int y)
{
	return(x > y);
}
int main()
{
	int n;
	scanf("%d", &n);
	int k;
	scanf("%d", &k);
	for(int i = 1; i < n; i++) scanf("%d", &s[i]);
	sort(s+1, s+n, cmp);
	if(k > s[1])
	{
		printf("0");
		return 0;
	}
	int ans = 0;
	for(int i = 1; ; i++)
	{
		sort(s+1, s+n, cmp);
		if(k > s[1])
		{
			printf("%d\n", ans);
			return 0;
		}
		ans++;
		s[1]--;
		k++;
	}
	return 0;
}