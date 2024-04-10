#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,c[100],i,j,k;
char s[5005],t[5005];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<n;++i)
	{
		for(j=i+1;j<=n;++j)
			t[j-i]=s[j];
		for(j=1;j<=i;++j)
			t[n-i+j]=s[j];
		for(j=1,k=n;j<k;++j,--k)
			if(t[j]!=t[k])
				break;
		if(j<k)
			continue;
		for(j=1;j<=n;++j)
			if(s[j]!=t[j])
				break;
		if(j<=n)
		{
			printf("1");
			return 0;
		}
	}
	for(i=1;i<=n;++i)
		c[s[i]-'a']++;
	for(i=k=0;i<26;++i)
		k=max(k,c[i]);
	if(k==n||k==n-1)
	{
		printf("Impossible");
		return 0;
	}
	printf("2");
	return 0;
}