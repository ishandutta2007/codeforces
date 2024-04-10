#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	//freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	if(x>y+z)
		printf("+");
	else if(y>x+z)
		printf("-");
	else if(x==y&&z==0)
		printf("0");
	else
		printf("?");
	return 0;
}