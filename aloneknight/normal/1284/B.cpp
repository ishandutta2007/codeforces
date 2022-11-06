#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int n,m,l[N],t[N],b[N*10];
pair<int,int>a[N];ll res;
int main()
{
	scanf("%d",&n);m=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&l[i]);
		for(int j=1;j<=l[i];j++)scanf("%d",&t[j]);
		int ff=0;
		for(int j=1;j<l[i];j++)if(t[j]<t[j+1])ff=1;
		if(!ff)a[++m]=make_pair(t[l[i]],t[1]);
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)b[a[i].second]++;
	for(int i=1;i<=1000000;i++)b[i]+=b[i-1];
	for(int i=1;i<=m;i++)res+=b[a[i].first];
	printf("%lld\n",1ll*n*n-res);
	return 0; 
}