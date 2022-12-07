#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=55;
int a[N];
int n; 
bool same ()
{
	int lst=-1;
	for (int u=1;u<=n;u++) if (a[u])
	{
		if (lst==-1) lst=a[u];
		else if (a[u]!=lst) return false;
	}
	return true;
}
bool solve ()
{
	int cnt=0;
	for (int u=1;u<=n;u++) cnt=cnt+(a[u]!=0);
	if (cnt<n/2) return false;
	for (int u=1;u<=n;u++) printf("%d ",a[u]);printf("\n");
	int mn=1e9;
	for (int u=1;u<=n;u++) if (a[u]) mn=min(mn,a[u]);
	int tot=0;
	for (int u=1;u<=n;u++) 
	{
		if (a[u]) 
		{
			a[u]=a[u]-mn;
			tot++;
		}
		if (tot>=n/2) break;
	}
	return !solve();
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	/*if (same()) {printf("Bob\n");return 0;}
	if (solve()) printf("Alice\n");
	else printf("Bob\n");*/
	int mn=a[1];for (int u=1;u<=n;u++) mn=min(mn,a[u]);
	for (int u=1;u<=n;u++) a[u]=a[u]-mn;
	int cnt=0;
	for (int u=1;u<=n;u++) cnt=cnt+(a[u]!=0);
	if (cnt>=n/2) printf("Alice\n");
	else printf("Bob\n");
	return 0;
}