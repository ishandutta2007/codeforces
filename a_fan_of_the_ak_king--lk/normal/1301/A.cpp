#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int M=1000000007;
typedef long double lb;
int t,i;
char a[N],b[N],c[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		scanf("%s",b);
		scanf("%s",c);
		bool flag=true;
		for(i=0;a[i];++i)
			if(!(a[i]==c[i]||b[i]==c[i]))
				flag=false;
		puts(flag?"YES":"NO");
	}
}