#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=1005;

int n,a[MAXN],b[MAXN];
int resn,resx[MAXN][2],resy[MAXN][2];
inline void insert(int x1,int y1,int x2,int y2)
{
	++resn;
	resx[resn][0]=x1;resy[resn][0]=y1;
	resx[resn][1]=x2;resy[resn][1]=y2;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=n;i>0;i--)
    {
    	if(a[i]==i && b[i]==i)continue;
    	insert(a[i],i,i,b[i]);
    	for(int j=1;j<=i;j++)
    		if(a[j]==i){a[j]=a[i];break;}
    	for(int j=1;j<=i;j++)
    		if(b[j]==i){b[j]=b[i];break;}
    }
    printf("%d\n",resn);
    for(int i=1;i<=resn;i++)
		printf("%d %d %d %d\n",resx[i][0],resy[i][0],resx[i][1],resy[i][1]);
    return 0;
}