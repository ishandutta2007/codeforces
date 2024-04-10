#include <iostream>
#include <cstring>
using namespace std;
const int N=2*100005;

int n,m;
char s[N];
char ans[N];
int a[30];
int main()
{
	int i,j,k,l,r;
	scanf("%s",&s);
	n=strlen(s);
	for(i=0;i<n;++i)
		a[s[i]-'a']++;
	i=0;
	j=25;
	while(i<j)
	{
		if(a[i]%2==0)
		{
			++i;
			continue;
		}
		if(a[j]%2==0)
		{
			--j;
			continue;
		}
		a[j]--;
		a[i]++;
	}
	l=0;
	r=n-1;
	for(i=0;i<26;++i)
	{
		for(j=0;j<a[i]/2;++j)
		{
			ans[l]=i+'a';
			++l;
			ans[r]=i+'a';
			--r;
		}
	}
	for(i=0;i<26;++i)
	{
		if(a[i]%2)
		{
			for(j=l;j<=r;++j)
				ans[j]=i+'a';
		}
	}
	printf("%s\n",ans);
	return 0;
}