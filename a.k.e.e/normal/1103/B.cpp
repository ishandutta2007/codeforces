#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=300005;

int ask(int x,int y)
{
	char op[3];
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",op);
	return op[0]-'x';
}
void reply(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}
int a[35];
bool work()
{
	char str[15];
	scanf("%s",str);
	if(str[0]!='s')return 0;
	if(!ask(0,1)){reply(1);return 1;}
	int l=0,r=1000000000,mid;
	for(int i=1;i<=30;i++)
		if(!ask(1<<(i-1),1<<i))
			{l=(1<<(i-1)),r=(1<<i);break;}
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(!ask(l,mid))r=mid;
		else l=mid;
	}
	reply(r);
	return 1;
};

int main()
{
    while(work());
    return 0;
}