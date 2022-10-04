#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
const int MAXN=300005;

int n;
struct Data
{
	int id,x,y;
	Data(){}
	Data(int id,int x,int y):id(id),x(x),y(y){}
	inline bool operator <(Data b){return x<b.x;}
}a[MAXN],b[MAXN];
int solve(int n,Data *a)
{
	sort(a+1,a+n+1);
	printf("%d\n",n);
	for(int i=n;i>0;i--)
		printf("%d ",a[i].id);
	printf("\n");
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int u,v,na=0,nb=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d%d",&u,&v);
    	if(u<v)a[++na]=Data(i,u,v);
    	else b[++nb]=Data(i,-u,-v);
    }
    if(na>nb)solve(na,a);
    else solve(nb,b);
    return 0;
}