#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
const int MAXN=505;

int n;

bool ask(int x1,int y1,int x2,int y2)
{
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	char s[5];
	scanf("%s",s);
	return s[0]=='Y';
}

void reply(char *s)
{
	printf("! %s\n",s+1);
	fflush(stdout);
	exit(0);
}

char ans[MAXN<<2|1];
int tot=0;

int main()
{
    cin>>n;
    int tx,ty,x=1,y=1;
    for(int i=1;i<=n;i++)
    	if(ask(1,1,i,n-i+1) && ask(i,n-i+1,n,n))
    		{tx=i;ty=n-i+1;break;}
    while(x<tx || y<ty)
    	if(y<ty && ask(x,y+1,n,n))
    	{
    		ans[++tot]='R';
    		y++;
    	}
    	else
    	{
    		ans[++tot]='D';
    		x++;
    	}
    x=y=n;
    tot=2*n-2;
    while(x>tx || y>ty)
    	if(x>tx && ask(1,1,x-1,y))
    	{
    		ans[tot--]='D';
    		x--;
    	}
    	else
    	{
    		ans[tot--]='R';
    		y--;
    	}
    reply(ans);
    return 0;
}