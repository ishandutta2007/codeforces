/* Test submission for Contest #631. */
#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
char str[1111111];
int T;
typedef long long ll;
ll m1=1453931441,b1[11111111],m2=1343135131,b2[1111111];
void pre()
{
	register int i;
	b1[0]=b2[0]=1,b1[1]=131313131,b2[1]=313131313;
	for(i=2;i<=1000000;i++)
		b1[i]=b1[i-1]*b1[1]%m1,b2[i]=b2[i-1]*b2[1]%m2;
}
inline ll gethash(int l,int r,ll*h,ll m,ll*b)
{return((h[r]-h[l-1]*b[r-l+1])%m+m)%m;}
char stt[1111111],tts[1111111];
ll h1[5][1111111],h2[5][1111111];
inline void genhash(ll*wrln,ll bas,ll mdd,char*s,int l)
{
	register int i;
	for(i=1;i<=l;i++)
		wrln[i]=(wrln[i-1]*bas+s[i])%mdd;
}
bool islegal(int l,int r,int ln)
{return(gethash(l,r,h1[1],m1,b1)==gethash(ln-r+1,ln-l+1,h1[2],m1,b1))&&(gethash(l,r,h2[1],m2,b2)==gethash(ln-r+1,ln-l+1,h2[2],m2,b2));}
void print(int l,int r)
{for(register int i=l;i<=r;i++)putchar(stt[i]);}
void solve(int len)
{
	register int i;
	for(i=1;i<=len;i++)tts[i]=stt[len-i+1];
	genhash(h1[1],b1[1],m1,stt,len),genhash(h2[1],b2[1],m2,stt,len);
	genhash(h1[2],b1[1],m1,tts,len),genhash(h2[2],b2[1],m2,tts,len);
	int eval=0,ft=0;
	for(i=1;i<=len;i++)
		if(islegal(1,i,len))eval=i,ft=1;
	for(i=eval+1;i<=len;i++)
		if(islegal(len-i+1,len,len))eval=i,ft=2;
	if(!ft)return;
	if(ft==1)print(1,eval);
	else print(len-eval+1,len);
}
void exec()
{
	int l;
	scanf("%s",str+1),l=strlen(str+1);
	int p=1,q=l;
	while(p<q)
	{
		if(str[p]^str[q])break;
		p++,q--;
	}register int i,ii;
	for(i=1;i<p;i++)putchar(str[i]);
	for(i=p,ii=0;i<=q;i++)stt[++ii]=str[i];
	solve(ii);
	for(i=q+1;i<=l;i++)putchar(str[i]);puts("");
}
int main()
{
	pre(),scanf("%d",&T);
	while(T--)exec();
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/