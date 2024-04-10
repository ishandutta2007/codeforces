#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int a1,a2,a3,a4;
	scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
	if(a1==a2+a3+a4||a2==a1+a3+a4||a3==a1+a2+a4||a4==a1+a2+a3||a1+a2==a3+a4||a1+a3==a2+a4||a1+a4==a2+a3)
		printf("YES");
	else
		printf("NO");
	return 0;
}