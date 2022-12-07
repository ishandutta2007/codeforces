#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
const int N=500005;
const int MAX=2e9;
map<int,int> mp;
int n,k;
int a[N];
int b[N];
int ans=0;
int c[N],nn=0;
int A[N],an;
int d[N];	
void solve (int l,int r)
{
//	printf("%d %d %d %d\n",l,r,a[l],a[r]);
	if (a[r]<a[l]) {printf("-1\n");exit(0);}
	nn=0;
	for (int u=l;u<=r;u++)
	{
		if (a[u]<a[l]||a[u]>a[r]) {ans++;}
		else c[++nn]=a[u];
	}
//	for (int u=1;u<=nn;u++) printf("%d ",c[u]);printf("\n");
	d[1]=c[1];
    int len=1;
    for(int i=2;i<=nn;i++)
    {
        if(c[i]>=d[len])
            d[++len]=c[i];
        else
        {
            int j=std::upper_bound(d+1,d+len+1,c[i])-d;
            d[j]=c[i]; 
        }
    }
    //printf("%d\n",len);
    ans=ans+nn-len;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	a[0]=-MAX;a[++n]=MAX;
	for (int u=0;u<=n;u++) a[u]=a[u]-u;
	for (int u=1;u<=k;u++) scanf("%d",&b[u]);
	b[++k]=0;b[++k]=n;
	sort(b+1,b+1+k);
	for (int u=1;u<k;u++) solve(b[u],b[u+1]);
	printf("%d\n",ans);
	return 0;
}