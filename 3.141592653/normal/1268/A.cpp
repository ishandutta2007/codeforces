#include<cstdio>
#include<cstring>
typedef long long ll;
typedef double db;
#define lowbit(x) (x&(-x))
int n,k;
char str[422222];
char stt[422222];
void cpy(int l1,int r1,int l2,int r2)
{
	register int i;
	for(;l1<=r1&&l1<=n;l1++,l2++)stt[l1]=str[l2];
}
bool cmp(char*s1,char*s2)
{
	register int i;
	for(;*s1;s1++,s2++)
	{
		if(*s1<*s2)return 0;
		if(*s1>*s2)return 1;
	}return 0;
}
void inc()
{
	register int i=k;
	while(1)
	{
		if(str[i]=='9')
		{
			str[i]='0';i--;
			goto RR;
		}
		str[i]++;break;
		RR:;
	}
}
void exec()
{
	scanf("%d%d%s",&n,&k,str+1);
	register int i;
	for(i=1;i<=n;i+=k)
		cpy(i,i+k-1,1,k);
	printf("%d\n",n);
	if(!cmp(str+1,stt+1))return(void)puts(stt+1);
	else inc();
	for(i=1;i<=n;i+=k)
		cpy(i,i+k-1,1,k);
	puts(stt+1);
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}
/*
All things passing through, leaving me behind.
Where is your fighting heart, std?
*/