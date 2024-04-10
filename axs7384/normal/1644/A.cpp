#include<bits/stdc++.h>
using namespace std;
char s[1005];
int t;
map<char,int> mp;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",s);
		mp.clear();
		for (int i=0;i<=5;++i)
			mp[s[i]]=i;
		bool b=1;
		if (mp['R']<mp['r'])
			b=0;
		if (mp['G']<mp['g'])
			b=0;
		if (mp['B']<mp['b'])
			b=0;
		puts(b?"YES":"NO");
	}
}