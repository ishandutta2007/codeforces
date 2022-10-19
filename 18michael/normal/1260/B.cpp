#include<cstdio>
int a,b,c,d,Test_num;
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)scanf("%d%d",&a,&b),c=2*a-b,d=2*b-a,puts((c<0 || d<0 || c%3 || d%3)? "NO":"YES");
	return 0;
}
/*
2c+d=a
c+2d=b
c=(2a-b)/3
d=(2b-a)/3
*/