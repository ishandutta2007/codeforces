#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=25;

int n,b[N];
pair<int,int> a[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].first),a[i].second=i;
	sort(a+1,a+n+1);
	int tmp=a[1].first;
	for (int i=1;i<n;i++) a[i].first=a[i+1].first;
	a[n].first=tmp;
	for (int i=1;i<=n;i++) b[a[i].second]=a[i].first;
	for (int i=1;i<=n;i++) printf("%d ",b[i]);
	return 0;
}