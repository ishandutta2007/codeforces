#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=200005;
const LL MOD=1e9+7;
char s1[N],s2[N];
LL JC[N],inv[N];
LL pow (LL x,LL y)
{
	if (y==1) return x;
	LL lalal=pow(x,y>>1);
	lalal=lalal*lalal%MOD;
	if (y&1) lalal=lalal*x%MOD;
	return lalal;
}
LL C (LL x,LL y)
{
	if (x<0||y<0) return 0;
	if (x<y)  return 0;
	//printf("%lld %lld %lld\n",JC[x],inv[y],inv[x-y]);
	//printf("%lld %lld\n",x,y);
	return JC[x]*inv[y]%MOD*inv[x-y]%MOD;
}
LL calc (LL x,LL y)//xy 
{
	if (x==0) return 1;
	return C(x+y-1,y-1);
}
LL solve (LL a,LL b,LL c,LL d)//00    01   10   11   0 
{
	if (a<0||b<0||c<0||d<0) return 0;
	if (b==c)//10101
		return calc(d,c+1)*calc(a,b)%MOD;
	else if (c==b+1)//1010
		return calc(d,c)*calc(a,b+1)%MOD;
	else return 0;
}
LL solve1 (LL a,LL b,LL c,LL d)//00    01   10   11   1
{
	if (a<0||b<0||c<0||d<0) return 0;
	if (b==c)//010
		return calc(d,c)*calc(a,b+1)%MOD;
	else if (b==c+1)//0101
		return calc(a,b)*calc(d,c+1)%MOD;
	else return 0;
}
LL len,len1,len2;
int main()
{

	JC[0]=1;for (LL u=1;u<=200000;u++) JC[u]=JC[u-1]*u%MOD;
	inv[200000]=pow(JC[200000],MOD-2);
	for (LL u=200000-1;u>=0;u--) inv[u]=inv[u+1]*(u+1)%MOD;	//printf("%lld\n",calc(2,1));
	LL a,b,c,d;//00 01 10 11
	scanf("%s%s",s1+1,s2+1);//
	LL A,B,C,D;
	scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
	LL len=A+B+C+D+1;
	len1=strlen(s1+1);len2=strlen(s2+1);
	LL ans1=0,ans2=0;
	a=A;b=B;c=C;d=D;
	if (len2>len)// 
	{
		ans1=solve(a,b,c,d);
		//printf("YES %lld\n",ans1);
	}
	if (len2==len)// 
	{
		 LL lst=s2[1]-'0';
		 for (LL u=2;u<=len2;u++)
		 {
		 	if (s2[u]=='1')// 
		 	{
		 		//printf("%lld %lld %lld %lld %lld\n",a,b,c,d,solve1(a,b,c,d));
		 		if (lst==0) 
				 {
				 	//printf("%lld %lld %lld %lld %lld\n",a-1,b,c,d,solve1(a-1,b,c,d));
				 	ans1=ans1+solve1(a-1,b,c,d);
				}
		 		else 
				 {
				 	//printf("%lld %lld %lld %lld %lld\n",a,b,c-1,d,solve1(a,b,c-1,d));
				 	ans1=ans1+solve1(a,b,c-1,d);
				}
		 	}
		 	if (lst==0&&s2[u]=='1') b--;
		 	if (lst==0&&s2[u]=='0') a--;
		 	if (lst==1&&s2[u]=='1') d--;
		 	if (lst==1&&s2[u]=='0') c--;
		 	lst=s2[u]-'0';
		}
		if (a==0&&b==0&&c==0&&d==0) ans1++;
		ans1=ans1%MOD;
	}
	//printf("YES:%lld\n",ans1);
	a=A;b=B;c=C;d=D;
	if (len1>len)// 
		ans2=solve(a,b,c,d);
	if (len1==len)
	{
		 LL lst=s1[1]-'0';
		 for (LL u=2;u<=len1;u++)
		 {
		 	if (s1[u]=='1')//
		 	{
		 		if (lst==0) ans2=ans2+solve1(a-1,b,c,d);
		 		else ans2=ans2+solve1(a,b,c-1,d);
		 	}
		 	if (lst==0&&s1[u]=='1') b--;
		 	if (lst==0&&s1[u]=='0') a--;
		 	if (lst==1&&s1[u]=='1') d--;
		 	if (lst==1&&s1[u]=='0') c--;
		 	lst=s1[u]-'0';
		}
		ans2=ans2%MOD;
	}
	ans1=(ans1-ans2+MOD)%MOD;
	printf("%lld\n",ans1);
	return 0;
}