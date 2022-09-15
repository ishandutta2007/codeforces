#include<cstdio>
int N;
char a[100100];
char b[100100];
int main()
{
	scanf("%d%s%s",&N,a,b);
	int fd;
	for(fd=0;fd<N;fd++)
	{
		if(a[fd]!=b[fd])
			break;
	}
	int nx,i;
	//
	for(i=fd+1;i<N;i++)
	{
		if(a[i]!=b[i]) break;
	}
	if(i==N)
	{
		puts("2");
		return 0;	
	}
	int cnt=0;
	//a
	for(nx=fd;nx<N-1;nx++)
	{
		if(a[nx+1]!=b[nx])
			break;
	}
	for(i=nx+1;i<N;i++)
	{
		if(a[i]!=b[i]) break;
	}
	if(i==N)
		cnt++;
	//b
	for(nx=fd;nx<N-1;nx++)
	{
		if(b[nx+1]!=a[nx])
			break;
	}
	for(i=nx+1;i<N;i++)
	{
		if(a[i]!=b[i]) break;
	}
	if(i==N)
		cnt++;
	printf("%d\n",cnt);
	return 0;
}