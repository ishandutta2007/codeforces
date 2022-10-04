#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,a[35];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void print(int len,int c){while(len--)putchar(c+'a'-1);}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int odd_cnt=0,d=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d=gcd(d,a[i]);
		if(a[i]&1)++odd_cnt;
	}
	if(odd_cnt>=2)
	{
		printf("0\n");
		for(int i=1;i<=n;i++)
			print(a[i],i);
		return 0;
	}
	printf("%d\n",d);
	if(odd_cnt==1)
	{
		for(int t=1;t<=d;t++)
		{
			for(int i=1;i<=n;i++)
				if(!(a[i]&1))print(a[i]/(2*d),i);
			for(int i=1;i<=n;i++)
				if(a[i]&1)print(a[i]/d,i);
			for(int i=n;i;i--)
				if(!(a[i]&1))print(a[i]/(2*d),i);
		}
		return 0;
	}
	for(int t=1;t<=d/2;t++)
	{
		for(int i=1;i<=n;i++)
			print(a[i]/d,i);
		for(int i=n;i;i--)
			print(a[i]/d,i);
	}
    return 0;
}