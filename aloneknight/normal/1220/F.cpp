#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],tl[N],tr[N],dep[N],stk[N];
inline int add(int v)
{
	int d=1;while(m>0&&stk[m-1]>v){m--;d=max(d,dep[m]+1);}
	d=max(d,m+1);dep[m]=d;stk[m++]=v;return d;
}
int main()
{
	scanf("%d",&n);int p1=-1,mn=n+1,ps=-1;
	for(int i=0;i<n;i++){scanf("%d",&a[i]);if(a[i]==1)p1=i;}
	rotate(a,a+p1,a+n);
	m=0;for(int i=1;i<n;i++)tr[i]=max(tr[i-1],add(a[i]));
	m=0;for(int i=n-1;i>=0;i--)tl[n-i]=max(tl[n-i-1],add(a[i]));
	for(int i=0;i<n;i++)if(max(tl[i],tr[n-1-i])<mn){mn=max(tl[i],tr[n-1-i]);ps=i;}
	printf("%d %d\n",mn+1,(p1-ps+n)%n);return 0;
}