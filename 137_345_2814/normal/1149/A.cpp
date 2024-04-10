#include<cstdio>
using namespace std;
int n,a,b,c;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a),a==1?b++:c++;
	if(b==0)while(c--)printf("2 ");
	else if(c==0)while(b--)printf("1 ");
	else
	{
		printf("2 1 ");b--,c--;
		while(c--)printf("2 ");
		while(b--)printf("1 ");
	}
}//