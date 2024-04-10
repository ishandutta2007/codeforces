#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int main()
{
	int x,y,z,a,b,c;
	scanf("%d%d%d",&x,&y,&z);
	scanf("%d%d%d",&a,&b,&c);
	if (x>a) {puts("NO");return 0;}
	a-=x;
	b+=a;
	if (y>b) {puts("NO");return 0;}
	b-=y;
	c+=b;
	if (z>c) {puts("NO");return 0;}
	puts("YES");
	return 0;
}