#include <iostream>
#include <string>
using namespace std;

int main()
{
	int k,a,b,n=0,c,d;
	scanf("%d%d%d",&k,&a,&b);
	printf("%d\n",(a<k && b%k!=0) || (b<k && a%k!=0) ? -1 : a/k+b/k);
}