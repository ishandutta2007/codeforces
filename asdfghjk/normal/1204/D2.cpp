#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
int n,i,w0,w1,f0,f1,w[N];
char s[N],t[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=n,w0=w1=0;i>=1;--i)
	{
		if(s[i]=='0')
			++w0,++f0,t[i]='0';
		else
		{
			++w1;
			if(w1==f0+1)
				++f0,t[i]='0';
			else
			{
				t[i]='1';
				++f1;
				f0=max(f0,f1);
			}
		}
	}
	printf("%s",t+1);
	return 0;
}