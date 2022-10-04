#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define x first
#define y second
const int MAXN=300005;

int n;
pii a[MAXN];
int b[MAXN];
int cnt,u[MAXN*5],v[MAXN*5],d[MAXN*5];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i].x);a[i].y=i;}
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)a[i].x-=b[i];
    int pos=0;
    for(int i=1;i<=n;i++)
    	while(a[i].x<0)
    	{
	    	while(pos<=n && (a[pos].x<=0 || pos<=i))++pos;
	    	if(pos>n)return 0*printf("NO\n");
	    	u[++cnt]=a[i].y;v[cnt]=a[pos].y;
	    	d[cnt]=min(-a[i].x,a[pos].x);
	    	a[i].x+=d[cnt];a[pos].x-=d[cnt];
	    }
	for(int i=1;i<=n;i++)
		if(a[i].x)return 0*printf("NO\n");
	printf("YES\n");
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d %d %d\n",u[i],v[i],d[i]);
    return 0;
}