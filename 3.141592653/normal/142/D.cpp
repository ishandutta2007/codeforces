#include<cstdio>
int n,m,k;
char s[1111];
int check()
{
	register int i;
	int ls=0,tp=0,sz=1,sp=0;
	for(i=1;i<=m;i++)
	{
		if(s[i]=='G'){tp|=1;if(ls)ls=i-ls-1;else ls=i;}
		if(s[i]=='R'){tp|=2;if(ls)ls=i-ls-1;else ls=i;}
		if(s[i]=='-')sp=1;
	}return(tp&&sp)?(tp&1)?(tp&2)?ls:-1:-2:-3;
}
int cnt[1111];
bool zero(){for(register int i=0;i<=20;i++)if(cnt[i]%(k+1))return 0;return 1;}
void ins(int x){for(register int i=0;x;i++,x>>=1)cnt[i]+=x&1;}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	register int i,ii;
	int S=0,t;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1),t=check();
		if(t==-3)continue;
		if(t<0){S|=-t;continue;}
		ins(t);
	}if(S==3)puts("Draw");
	else if(S==2||(zero()&&!S))puts("Second");
	else puts("First");
}
/*
Please don't let me down.
*/