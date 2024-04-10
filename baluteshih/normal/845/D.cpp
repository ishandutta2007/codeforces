#include <iostream>
using namespace std;

int count,stack[200050];

int main()
{
	int n,a,b,v,ans=0,top=-1;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				scanf("%d",&v);
				while(top>-1 && stack[top]<v) top--,ans++;//,puts("plus");
				break;
			case 2:
				ans+=count;
				//if(count) printf("plus %d\n",count);
				count=0;
				break;
			case 3:
				scanf("%d",&b);
				if(b<v) ans++;//,puts("plus");
				else stack[++top]=b;
				break;
			case 4:
				count=0;
				break;
			case 5:
				top=-1;
				break;
			case 6:
				count++;
		}
	}
	printf("%d\n",ans);
}