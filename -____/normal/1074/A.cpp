//CF1074A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
int n,m,s;
int a[N],b[N];
int main()
{
	int i,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	a[++n]=1e9;
	sort(a+1,a+n+1);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		if(x==1){
			z=upper_bound(a+1,a+n+1,y)-a-1;
			b[z]++;
		}
	}
	for(i=n;i;i=i-1)
		b[i]+=b[i+1];
	x=N;
	for(i=1;i<=n;i=i+1)
		x=min(x,i+b[i]);
	cout<<x-1;
	return 0;
}