#include<cstdio>
#include<cstring>
#include<algorithm>

const int mod1 = 1000000007;
const int mod2 = 1000000413;

char a[222222];
char b[222222];

std::pair<int,int> f(char t[],int s,int e)
{
	if((e-s)%2)
	{
		int i;
		std::pair<int,int> P;
		P.first=P.second=1;
        for(i=s;i<e;i++)
		{
            P.first=(P.first*31LL+t[i])%mod1;
            P.second=(P.second*31LL+t[i])%mod2;
		}
		return P;
	}
    std::pair<int,int> P,Q;
    P=f(t,s,(s+e)/2);
    Q=f(t,(s+e)/2,e);
    if(P>Q)std::swap(P,Q);
    P.first=((e-s+97LL)*P.first+Q.first)%mod1;
    P.second=((e-s+97LL)*P.second+Q.second)%mod2;
    return P;
}

int main()
{
	int n;
	scanf("%s%s",a,b);
	n=strlen(a);
    if(f(a,0,n)==f(b,0,n))puts("YES");
    else puts("NO");
}