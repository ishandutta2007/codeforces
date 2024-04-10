#include<cstdio>
#include<cstring>

int n,m,i,j;
bool bo=true;
char ch,max;

int main()
{
	max='a'-1;
	for(ch=getchar();ch<'a'||ch>'z';ch=getchar());
	if(ch>max)
	{
		++max;
		if(ch>max)bo=false;
	}
	for(ch=getchar();bo&&(ch>='a'&&ch<='z');ch=getchar())
	{
		if(ch>max)
		{
			++max;
			if(ch>max)bo=false;
		}
	}
	if(bo)printf("YES");
	else printf("NO");
	return 0;
}