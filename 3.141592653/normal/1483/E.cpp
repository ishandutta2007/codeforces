#include<bits/stdc++.h>

typedef long long ll;

long double ALPHA[1000];

ll Current;

void init()
{
	long double z=0.5;
	for(register int i=0;i<=800;i++)
	{
		ALPHA[i]=pow(2,z)/2;
		z=z*0.8;
		//printf("%.10Lf\n",ALPHA[i]);
	}
	
}

int ask(ll Least,ll x)
{
	char s[111];
	while(Current<x)
	{
		printf("? %lld\n",Least),Current+=Least;
		fflush(stdout);
		scanf("%s",s);
	}
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",s);
	bool Status=(*s=='L');
	if(Status)Current+=x;
	else Current-=x;
	return Status;
}

void solve(ll L,ll R)
{
	if(L==R){printf("! %lld\n",L);return;}
	ll M=ll(L*ALPHA[0]+R*(1-ALPHA[0]));
	for(register int i=1;i<=110;i++)
	{
		ll Q=ll(L*ALPHA[i]+R*(1-ALPHA[i]));
		if(Current/Q>=i)M=Q;
	}if(M==L)M++;
	if(ask(L,M))return solve(M,R);
	return solve(L,M-1);
}

void exec()
{
	Current=1;
	register ll i;
	for(i=1;i<=70368744177664ll;i<<=1)
		if(ask(0,i)==0)return solve(i>>1,i-1);
	solve(i>>1,100000000000000ll);
}

int main()
{
	init();
	int T;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Please don't let me down.
*/