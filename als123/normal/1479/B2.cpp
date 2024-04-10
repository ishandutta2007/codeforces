#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;
const int N=100005;
int a[N];
int n;
bool in[N];
int sta[N],top;
int cnt[N];
void solve (int x)
{
	int ans=1;
	int lst=-1;
	for (int u=1;u<=n;u++)
	{
		if (a[u]==x) continue;
		if (a[u]==lst) continue;
		ans++;lst=a[u];
	}
	printf("%d\n",ans);
}
set<int> s;
int main()
{
	memset(in,false,sizeof(in));
	scanf("%d",&n);
	for (int u=1;u<=n;u++) 	scanf("%d",&a[u]);
	int ans=1,lst=a[1];
	for (int u=2;u<=n;u++)
	{
		if (a[u]==a[u-1]) continue;
		if (a[u]==lst) {s.clear();s.insert(a[u-1]);continue;}
		if (s.find(a[u])==s.end())	{ans++;s.insert(a[u]);}
		else	{lst=a[u];s.clear();s.insert(a[u-1]);}
	}
	printf("%d\n",ans);
	return 0;
}