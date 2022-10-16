#include<cstdio>
#include<cstring>
int n;
int a[1111111];
void print()
{
	puts("YES");
	register int i;
	for(i=1;i<=n;i++)
		printf("%d%c",a[i],(i^n)?' ':'\n');
}
bool valid()
{
	register int i;
	for(i=1;i<n;i++)
		if(a[i]!=a[i+1]+1)
			if(a[i]!=a[i+1]-1)
				return 0;
	return 1; 
}
int main()
{
	int x,y,z,w;
	scanf("%d%d%d%d",&x,&y,&z,&w);
	int ev=x+z,od=y+w;n=ev+od;
	register int i;
	if(ev==od+1)
	{
		for(i=1;i<=x;i++)
			a[i*2-1]=0;
		for(i=1;i<=z;i++)
			a[x*2+i*2-1]=2;
		for(i=1;i<=y;i++)
			a[i*2]=1;
		for(i=1;i<=w;i++)
			a[y*2+i*2]=3;
		if(valid())print();
		else puts("NO");
	}
	else if(ev==od-1)
	{
		for(i=1;i<=y;i++)
			a[i*2-1]=1;
		for(i=1;i<=w;i++)
			a[y*2+i*2-1]=3;
		for(i=1;i<=x;i++)
			a[i*2]=0;
		for(i=1;i<=z;i++)
			a[x*2+i*2]=2;
		if(valid())print();
		else puts("NO");
	}
	else if(ev==od)
	{
		for(i=1;i<=y;i++)
			a[i*2-1]=1;
		for(i=1;i<=w;i++)
			a[y*2+i*2-1]=3;
		for(i=1;i<=x;i++)
			a[i*2]=0;
		for(i=1;i<=z;i++)
			a[x*2+i*2]=2;
		if(valid())print();
		else
		{
			for(i=1;i<=x;i++)
			a[i*2-1]=0;
			for(i=1;i<=z;i++)
				a[x*2+i*2-1]=2;
			for(i=1;i<=y;i++)
				a[i*2]=1;
			for(i=1;i<=w;i++)
				a[y*2+i*2]=3;
			if(valid())print();
			else puts("NO");
		}
	}
	else puts("NO");
}
/*
All things passing through, leaving me behind.
Where is your fighting heart, std?
*/