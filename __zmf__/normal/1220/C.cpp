#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[500009];
int n;
char mi;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
signed main() 
{
	mi='z'+1;
	cin>>a;n=strlen(a);
	for(int i=0;i<n;i++)
	{
		if(a[i]>mi)
		{
			puts("Ann");
			continue;
		}
		else
		{
			puts("Mike");mi=a[i];
			continue;
		}
	}
    return 0;
}