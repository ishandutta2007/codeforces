#include <stdio.h>
#include <cstring>

int n;
char str[2010];
char res[2010];

int main()
{
	scanf("%d",&n);
	scanf("%s",str);
	int le, ri, di;
	if(n&1)
		le=n/2-1, ri=n/2, di=1;
	else 
		le=n/2-1, ri=n/2, di=-1;

	for(int i=0;i<n;i++) {
		if(di==1) 
			res[ri++]=str[i];
		else
			res[le--]=str[i];
		di=di*-1;
	}

	printf("%s\n",res);

	return 0;
}