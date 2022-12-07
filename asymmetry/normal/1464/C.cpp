#include <bits/stdc++.h>

using namespace std;

int n, a, b;
int row[300000];
int roz[300000];
long long w;
char s[300000];

long long pot(int x)
{
	return 1ll<<x;
}

int main()
{
	scanf("%d%lld", &n, &w);
	scanf("%s", s+1);
	w-=pot(s[n]-'a');
	w+=pot(s[n-1]-'a');
	for(int i=1; i<=n-2; ++i)
	{
		w-=pot(s[i]-'a');
		++roz[s[i]-'a'+1];
	}
	if(w>0)
	{
		printf("No\n");
		return 0;
	}
	w=abs(w);
	a=0;
	while(w)
	{
		row[a]+=w&1;
		++a;
		w>>=1;
	}
	long long x=0;
	for(int i=0; i<100; ++i)
	{
		x+=roz[i]-row[i];
		if(x<0)
		{
			printf("No\n");
			return 0;
		}
		x>>=1;
	}
	printf("Yes\n");
	return 0;
}