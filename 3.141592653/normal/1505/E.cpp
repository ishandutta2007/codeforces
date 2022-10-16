#include<bits/stdc++.h>

char tmp[1111][1111];
int h,w;

void calc()
{
	int x=1,y=1;
	int S=tmp[1][1]=='*';
	while(x!=h||y!=w)
	{
		if(x==h)y++;
		else if(y==w)x++;
		else
		{
			if(tmp[x+1][y]==tmp[x][y+1])y++;
			else if(tmp[x+1][y]=='*')x++;
			else y++;
		}
		S+=(tmp[x][y]=='*');
	}printf("%d\n",S);
}

int main()
{
	scanf("%d%d",&h,&w);
	for(register int i=1;i<=h;i++)
		scanf("%s",tmp[i]+1);
	calc();
}
/*
Happy April Fool's Day !!!11 
*/