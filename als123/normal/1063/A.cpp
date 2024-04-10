#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005;
int t[30];
char ss[N];
int n;
int main()
{
	scanf("%d",&n);
	scanf("%s",ss);
	for (int u=0;u<n;u++)	t[ss[u]-'a']++;
	for (int u=0;u<26;u++)
	{
		//printf("%d %d\n",u,t[u]);
		for (int i=1;i<=t[u];i++)
			printf("%c",u+'a');
	}
	return 0;
}