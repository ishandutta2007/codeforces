#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n;
char s[N];

int main()
{
	scanf("%d%s",&n,s+1);
	int s1=0,s2=0,w1=0,w2=0;
	for (int i=1;i<=n/2;i++)
		if (s[i]=='?') s1++;
		else w1+=s[i]-'0';
	for (int i=n/2+1;i<=n;i++)
		if (s[i]=='?') s2++;
		else w2+=s[i]-'0';
	if (s1<s2) std::swap(s1,s2),std::swap(w1,w2);
	if (w1-w2==9*(s2-s1)/2) puts("Bicarp");
	else puts("Monocarp");
	return 0;
}