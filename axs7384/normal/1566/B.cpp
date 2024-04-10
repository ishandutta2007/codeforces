#include<bits/stdc++.h>
using namespace std;
int t;
char s[100005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",s);
		int n=strlen(s);
		int sum=0;
		if (s[0]=='0')
			++sum;
		for (int i=1;i<n;++i)
			if (s[i]=='0'&&s[i-1]=='1')
				++sum;
		sum=min(sum,2);
		printf("%d\n",sum);
	}
	return 0;
}