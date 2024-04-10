#include<cstdio>
#include<cstring>
const int N=15;
char ss[N][N];
void lalal ()
{
	for (int u=1;u<=9;u++)
	{
		for (int i=1;i<=9;i++)
		{
			if (ss[u][i]=='.')printf("%c",33);
			else printf("%c",ss[u][i]);
			if (i%3==0) printf(" ");
		}
		printf("\n");
		if (u%3==0) printf("\n");
	}
}
void print ()
{
	for (int u=1;u<=9;u++)
	{
		for (int i=1;i<=9;i++)
		{
			printf("%c",ss[u][i]);
			if (i%3==0) printf(" ");
		}
		 printf("\n");
		 if (u%3==0) printf("\n");
	}
}
void solve (int x)
{
	if (x==1)
	{
		bool tf=false;
		for (int u=1;u<=3;u++)
			for (int i=1;i<=3;i++)
				if (ss[u][i]=='.')
				{
					ss[u][i]=33;
					tf=true;
				}
		if (tf==false)	lalal();
		else print();
	}
	if (x==2)
	{
		bool tf=false;
		for (int u=1;u<=3;u++)
			for (int i=4;i<=6;i++)
				if (ss[u][i]=='.')
				{
					ss[u][i]='!';
					tf=true;
				}
		if (tf==false)	lalal();
		else print();
	}
	if (x==3)
	{
		bool tf=false;
		for (int u=1;u<=3;u++)
			for (int i=7;i<=9;i++)
				if (ss[u][i]=='.')
				{
					ss[u][i]='!';
					tf=true;
				}
		if (tf==false)	lalal();
		else print();
	}
	if (x==4)
	{
		bool tf=false;
		for (int u=4;u<=6;u++)
			for (int i=1;i<=3;i++)
				if (ss[u][i]=='.')
				{
					ss[u][i]='!';
					tf=true;
				}
		if (tf==false)	lalal();
		else print();
	}
	if (x==5)
	{
		bool tf=false;
		for (int u=4;u<=6;u++)
			for (int i=4;i<=6;i++)
				if (ss[u][i]=='.')
				{
					ss[u][i]='!';
					tf=true;
				}
		if (tf==false)	lalal();
		else print();
	}
	if (x==6)
	{
		bool tf=false;
		for (int u=4;u<=6;u++)
			for (int i=7;i<=9;i++)
				if (ss[u][i]=='.')
				{
					ss[u][i]='!';
					tf=true;
				}
		if (tf==false)	lalal();
		else print();
	}
	if (x==7)
	{
		bool tf=false;
		for (int u=7;u<=9;u++)
			for (int i=1;i<=3;i++)
				if (ss[u][i]=='.')
				{
					ss[u][i]='!';
					tf=true;
				}
		if (tf==false)	lalal();
		else print();
	}
	if (x==8)
	{
		bool tf=false;
		for (int u=7;u<=9;u++)
			for (int i=4;i<=6;i++)
				if (ss[u][i]=='.')
				{
					ss[u][i]='!';
					tf=true;
				}
		if (tf==false)	lalal();
		else print();
	}
	if (x==9)
	{
		bool tf=false;
		for (int u=7;u<=9;u++)
			for (int i=7;i<=9;i++)
				if (ss[u][i]=='.')
				{
					ss[u][i]='!';
					tf=true;
				}
		if (tf==false)	lalal();
		else print();
	}
}
int main()
{
	for (int u=1;u<=9;u++)
	{
		for (int i=1;i<=9;i++)
		{
			char ch=getchar();
		while (ch!='.'&&ch!='x'&&ch!='o') ch=getchar();
			ss[u][i]=ch;
		}
	}
	int x,y;
	scanf("%d%d",&x,&y);
	if (x==1||x==4||x==7)
	{
		if (y==1||y==4||y==7)
			solve(1);
		if (y==2||y==5||y==8)
			solve(2);
		if (y==3||y==6||y==9)
			solve(3);
	}
	if (x==2||x==5||x==8)
	{
		if (y==1||y==4||y==7)
			solve(4);
		if (y==2||y==5||y==8)
			solve(5);
		if (y==3||y==6||y==9)
			solve(6);
	}
	if (x==3||x==6||x==9)
	{
		if (y==1||y==4||y==7)
			solve(7);
		if (y==2||y==5||y==8)
			solve(8);
		if (y==3||y==6||y==9)
			solve(9);
	}
	return 0;
}