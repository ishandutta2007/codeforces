#include<stdio.h>
#include<stdlib.h>

int main()
{
	int c[4],n,m,i,*a,*b,ans,tc=0,bc=0,each=0;

	for(i=0;i<4;i++)
		scanf("%d",&c[i]);
	scanf("%d %d",&n,&m);

	a=(int*)malloc(sizeof(int)*n);
	b=(int*)malloc(sizeof(int)*m);

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		each=0;
		each=a[i]*c[0];
		if(c[1]<each)
			each=c[1];
		bc+=each;
	}



	for(i=0;i<m;i++)
	{	scanf("%d",&b[i]);
		each=0;
		each=b[i]*c[0];
		if(c[1]<each)
			each=c[1];
		tc+=each;
	}

	if(c[2]<tc)
		tc=c[2];
	if(c[2]<bc)
		bc=c[2];

	if(c[3]<tc+bc)
		ans=c[3];
	else
		ans=tc+bc;

	printf("%d\n",ans);
	free(a);
	free(b);
	return 0;
}