#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

const int N=300005;

int n,a,b,ca,cb,cc;
char s[N];
std::vector<int> vec;

void add(int x)
{
	if (x>=b*2) cc++;
	else if (x>=a) ca++;
	else if (x>=b) cb++;
}

void sub(int x)
{
	if (x>=b*2) cc--;
	else if (x>=a) ca--;
	else if (x>=b) cb--;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&a,&b);
		scanf("%s",s+1);
		n=strlen(s+1);
		cc=ca=cb=0;
		int l=0,flag=0;
		s[++n]='X';
		vec.clear();
		for (int i=1;i<=n;i++)
			if (s[i]=='.') l++;
			else add(l),vec.pb(l),l=0;
		for (int i:vec)
		{
			sub(i);
			for (int j=0;j+a<=i;j++)
			{
				add(j);add(i-a-j);
				if (!cc&&!cb&&ca%2==0) flag=1;
				sub(j);sub(i-a-j);
			}
			add(i);
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}