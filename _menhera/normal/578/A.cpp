#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<b)
	{
		puts("-1");
		return 0;
	}
	if(a==b)
	{
		printf("%.12lf",(double)a);
		return 0;
	}
	//type1
	
	int k1=(a-b)/2/b;
	double x1 = 1. * (a-b) / 2 / k1;
	
	int k2=(a+b)/2/b;
	double x2 = 1. * (a+b) / 2 / k2;
	
	printf("%.12lf\n",min(x1,x2));
	return 0;
}