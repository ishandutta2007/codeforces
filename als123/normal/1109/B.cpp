#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=5005;
char ss[N];
char a[N];
int n;
bool check ()
{
	for (int u=1;u<=n;u++)
		if (a[u]!=a[n-u+1]) return false;
	return true;
}
bool same ()
{
	for (int u=1;u<=n;u++)
		if (a[u]!=ss[u]) return false;
	return true;
}
bool check1 ()
{
	for (int u=1;u<=n;u++)
	{
		int cnt=0;
		for (int i=u+1;i<=n;i++) a[++cnt]=ss[i];
		for (int i=1;i<=u;i++) a[++cnt]=ss[i];
		if (!same()&&check()) return true;
	}
	return false;
}
int t[30];
int main()
{
	scanf("%s",ss+1);n=strlen(ss+1);
	for (int u=1;u<=n;u++) t[ss[u]-'a']++;
	int mx=0;
	for (int u=0;u<=26;u++) mx=max(mx,t[u]);
	if (mx>=n-1) printf("Impossible\n");
	else if (check1()) printf("1\n");
	else printf("2\n");
	return 0;
}