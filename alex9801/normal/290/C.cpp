/*#include <stdio.h>
#include <string.h>

char arr[1000001];

int main()
{
	int hsum=0,result=1,flag=0,H=0,Q=0,sum=0,len,i;
	scanf("%s",arr);
	len=strlen(arr);
	for(i=0;i<len;i++)
	{
		if(arr[i]=='H')
		{
			H++;
			hsum++;
	//		flag=0;
		}
		else
		{
			if(flag==1)
			{
				result=0;
				break;
			}
			Q++;
//			flag=1;
			if(hsum%2==1)
			{
				result=0;
				break;
			}
		}
	}
	if(result==1)
		printf("Yes");
	else
		printf("No");
	return 0;
}*/

#include <stdio.h>
#include <string.h>

int main()
{
	int TUX,FOO=0,BAR=0,BAZ=0,QUZ=1;
	double result;
	scanf("%d",&TUX);
	while(TUX--)
	{
		int PUR;
		scanf("%d",&PUR);
		FOO+=PUR;
		BAR+=1;
		if(FOO*QUZ>=BAR*BAZ)
		{
			BAZ=FOO;
			QUZ=BAR;
		}
	}
	result=1.*BAZ/QUZ;
	printf("%lf",result);
	return 0;
}