#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

/*
(2s+t)(2a-b)-as=3as+2at-2sb-tb=k
(3a-2b)s+(2a-b)t=k
2s+t<=1000
a<=1000000s
b<=1000000t
a<b
*/

int k;
void print(ll n,ll sum,int f)
{
	if(n==1)printf("%d ",(int)sum);
	else
	{
		printf("%d ",(int)(sum/2)*f);
		for(int i=2;i<n;i++)printf("0 ");
		printf("%d ",(int)(sum-sum/2)*f);
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
    #endif
    scanf("%d",&k);
    ll s=667,t=666;
    ll y=s-k%s;
    ll x=(k-y*t)/s;
    while(2*y-x<0 || 3*y-2*x<0)y+=s,x-=t;
    while(x>=y)y+=s,x-=t;
    ll a=2*y-x,b=3*y-2*x;
    cout<<2000<<endl;
    print(s,a,1);print(t,b,-1);print(s,a,1);
    return 0;
}