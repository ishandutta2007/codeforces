#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,ans;
/*int a[6][6]={
0,0,0,0,0,0,
0,0,,,,,
0,,,,,,
0,,,,,,
0,,,,,,
0,,,,,,};*/
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
int main()
{
	read(n),read(m);
	if(n==1 || m==1)return 0&printf("%lld",(max(n,m)/6)*6+max(0,(max(n,m)%6)-3)*2);
	if(n==2 && m==2)return 0&printf("0");
	if((!(n&1) && m>=3) || (!(m&1) && n>=3))return 0&printf("%lld",((n*m)/2-((n==2 && m==3) || (m==2 && n==3) || (n==2 && m==7) || (m==2 && n==7)))*2);
	//if((!(n&1) && n!=2) || (!(m&1) && m!=2))return 0&printf("%lld",((n*m)/2)*2);
	//if((!(n&1) && n==2) || (!(m&1) && m==2))return 0&printf("%lld",((n*m)/2)*2);
	if((n%6)==3 || (m%6)==3)return 0&printf("%lld",((n*m)/2)*2);
	if((n%6)==5 || (m%6)==5)return 0&printf("%lld",((n*m)/2)*2);
	return 0&printf("%lld",((n*m)/2)*2);
	//if((!(n&1) && m<=2) || (!(m&1) && n<=2))return 0&printf("0");
	//if((!(n&1) && m==3) || (!(m&1) && n==3))return 0&printf("0");
	//ans=(n/6)*m*3+(m/6)*(n%6),n%=6,m%=6;
	return 0;
}