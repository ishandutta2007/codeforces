#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN=200005;
int n;
char s[MAXN];
int main()
{
	scanf("%d%s",&n,s+1);
	int ans=n;
	for(int i=1;i<n;i++)
		if(s[i]>s[i+1])
		{
			ans=i;
			break;
		}
	for(int i=1;i<=n;i++)
		if(i!=ans)putchar(s[i]);
	return 0;
}