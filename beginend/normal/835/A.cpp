#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int s,v1,v2,t1,t2;
	scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
	int x=t1*2+s*v1,y=t2*2+s*v2;
	if (x>y) puts("Second");
	else if (x<y) puts("First");
	else puts("Friendship");
	return 0;
}