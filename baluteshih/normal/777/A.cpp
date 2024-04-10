#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n,t,x,ans[6][3]={{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1}};
	scanf("%d%d",&n,&x);
	printf("%d\n",ans[n%6][x]);
}