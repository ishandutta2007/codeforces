#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int N=1000006;

int n,m,k;
char a[N],b[N],ans[N];
int aa[30],bb[30],c[30];
int main()
{
	int i,j;
	scanf("%s%s",a,b);
	n=strlen(a);
	m=strlen(b);
	for(i=0;i<m;++i)
	{
		++bb[b[i]-'a'];
	}
	for(i=0;i<n;++i)
	{
		if(a[i]=='?')
		{
			continue;
		}
		++aa[a[i]-'a'];
	}
	for(i=0;i<26;++i)
	{
		if(bb[i]==0)
		{
			aa[i]=0;
			continue;
		}
		c[i]=aa[i]/bb[i];
		aa[i]%=bb[i];
		aa[i]=bb[i]-aa[i];
	}
	j=0;
	for(i=0;i<n;++i)
	{
		if(a[i]!='?')
		{
			ans[i]=a[i];
			continue;
		}
		while(1)
		{
			if(c[j]>0)
			{
				--c[j];
				++j;
				j%=26;
				continue;
			}
			if(aa[j]>0)
			{
				--aa[j];
				ans[i]=(j+'a');
				break;
			}
			else
			{
				aa[j]=bb[j];
				++j;
				j%=26;
			}
		}
	}
	printf("%s\n",ans);
	return 0;
}