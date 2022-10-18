#include <stdio.h>

bool num[100001];

int main()
{
	int n,a,i,top;
	scanf("%d",&n),top=n;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a),num[a]=1;
		if(a<top) printf(" \n");
		else
		{
			printf("%d",top--);
			while(num[top]==1) printf(" %d",top--);
			printf("\n");
		}
	}
}