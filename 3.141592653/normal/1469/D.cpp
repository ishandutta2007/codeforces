#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int ct=0,a[1111111],b[1111111]; 
void ask(int x,int y)
{
	a[++ct]=x,b[ct]=y;
}
void exec()
{
	int n;
	ct=0;
	scanf("%d",&n);
	if(n==3)
	{
		puts("2\n3 2\n3 2");
		return;
	}
	register int i;
	for(i=2;i<n;i++)
	{
		if(i==2||i==4||i==16||i==256||i==65536)
		{
			continue;
		}else ask(i,n);
	}if(n>65536)
	{
		ask(n,65536),ask(n,65536);
		ask(65536,256),ask(65536,256);
		ask(256,16),ask(256,16);
		ask(16,4),ask(16,4);
		ask(4,2),ask(4,2);
	}else if(n>256)
	{
		ask(n,256),ask(n,256);
		ask(256,16),ask(256,16);
		ask(16,4),ask(16,4);
		ask(4,2),ask(4,2);
	}else if(n>16)
	{
		ask(n,16),ask(n,16);
		ask(16,4),ask(16,4);
		ask(4,2),ask(4,2);
	}else if(n>4)
	{
		ask(n,4),ask(n,4);
		ask(4,2),ask(4,2);
	}else if(n==4)ask(4,2),ask(4,2);
	printf("%d\n",ct);
	for(register int i=1;i<=ct;i++)
		printf("%d %d\n",a[i],b[i]);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Please don't let me down.
*/