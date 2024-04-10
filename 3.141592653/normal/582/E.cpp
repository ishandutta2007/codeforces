#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int F[555][1<<16|15];
const int N=1<<16,n=16;
const int mod=1e9+7;
void FWA(int*x,int op)
{
	register int i,ii,iii;
	for(i=1;i<N;i<<=1)
		for(ii=0;ii<N;ii+=(i<<1))
			for(iii=0;iii<i;iii++)
				(x[ii+iii]+=op*x[i+ii+iii])<mod?0:x[ii+iii]-=mod,
				x[ii+iii]<0?x[ii+iii]+=mod:0;
}
void FWO(int*x,int op)
{
	register int i,ii,iii;
	for(i=1;i<N;i<<=1)
		for(ii=0;ii<N;ii+=(i<<1))
			for(iii=0;iii<i;iii++)
				(x[i+ii+iii]+=op*x[ii+iii])<mod?0:x[i+ii+iii]-=mod,
				x[i+ii+iii]<0?x[i+ii+iii]+=mod:0;
}
int G[111111];
bool init(int a,int b,int c,int d,int e)
{
	if(G[a<<3|b<<2|c<<1|d])if(G[a<<3|b<<2|c<<1|d]!=e+1)retrun 0;
	return G[a<<3|b<<2|c<<1|d]=e+1,1;
}
bool valid(int S)
{
	register int i;
	for(i=0;i<n;i++)if(G[i])if(((S>>i)&1)!=G[i]-1)return 0;
	return 1;
}
void mul(int*x,int*y,int*z,int op)
{
	 register int i;
	 if(op&1)FWO(x,1),FWO(y,1);
	 else FWA(x,1),FWA(y,1);
	 for(i=0;i<N;i++)z[i]=x[i]*1ll*y[i]%mod;
	 if(op&1)FWO(z,-1),FWO(x,-1),FWO(y,-1);
	 else FWA(z,-1),FWA(x,-1),FWA(y,-1);
}
const int FA=N-(1<<8),Fa=(1<<8)-1,FB=FA^(FA>>4),Fb=N-1-FB,
FC=FB^(FB>>2),Fc=N-1-FC,FD=FC^(FC>>1),Fd=N-1-FD;
void img(int*x,int*y)
{for(register int i=0;i<N;i++)(x[i]+=y[i])<mod?0:x[i]-=mod; }
int A[111111],B[111111],C[111111],D[111111],E[111111],tp[111111],t,cr;
char s[111111];
int ope(char c){return c=='|'?1:c=='&'?2:3;}
int R[111111];
void opall(int OP,int ls,int rs,int P)
{
	if(OP&1)mul(F[ls],F[rs],tp,1),img(F[P],tp);
	if(OP&2)mul(F[ls],F[rs],tp,2),img(F[P],tp);
}
int solve(int L=0)
{
	register int i;
	int P=++cr;
	int LOP=0,LS=0;
	for(i=L+1;;i++)
	{
		if(s[i]==')'||!s[i])break;
		if(s[i]=='(')
		{
			int S=solve(i);
			if(!LOP)LS=S;
			else opall(LOP,LS,S,P);
			i=R[S];
		}else if(s[i]=='A')F[P][FA]++;
		else if(s[i]=='B')F[P][FB]++;
		else if(s[i]=='C')F[P][FC]++;
		else if(s[i]=='D')F[P][FD]++;
		else if(s[i]=='a')F[P][Fa]++;
		else if(s[i]=='b')F[P][Fb]++;
		else if(s[i]=='c')F[P][Fc]++;
		else if(s[i]=='d')F[P][Fd]++;
		else LOP=ope(s[i]);
	}if(L==i-2)if(LOP==3)F[P][FA]++,F[P][FB]++,F[P][Fa]++,F[P][Fc]++,
						F[P][FC]++,F[P][Fb]++,F[P][Fd]++,F[P][FD]++;
	R[P]=i;return P;
}
int main()
{
	scanf("%s%d",s+1,&t),s[0]='(';
	register int i,v=1;
	for(i=1;i<=t;i++)
		scanf("%d%d%d%d%d",A+i,B+i,C+i,D+i,E+i),v&=init(A[i],B[i],C[i],D[i],E[i]);
	if(!v)return puts("0"),0;
	solve();
	long long ans=0;
	for(i=0;i<N;i++)if(valid(i))ans+=F[1][i];
	printf("%lld\n",ans%mod);
}
/*
Please don't let me down.
*/