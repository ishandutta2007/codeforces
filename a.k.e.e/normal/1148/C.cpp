#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=300005;

int n,a[MAXN],w[MAXN];
int u[MAXN*5],v[MAXN*5],cnt;
void work(int x,int y)
{
	++cnt;
	u[cnt]=x;v[cnt]=y;
	swap(a[x],a[y]);
	w[a[x]]=x;w[a[y]]=y;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		w[a[i]]=i;
	}
	n>>=1;
	for(int i=n;i>=2;i--)
	{
		if(w[i]>n)work(w[i],1);
		work(w[i],n<<1);
		work(w[i],i);
		
		if(w[2*n-i+1]<=n)work(w[2*n-i+1],n<<1);
		work(w[2*n-i+1],1);
		work(w[2*n-i+1],2*n-i+1);
	}
	if(a[1]==(n<<1))work(1,n<<1);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d %d\n",u[i],v[i]);
    return 0;
}