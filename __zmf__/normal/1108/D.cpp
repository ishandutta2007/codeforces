//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n,ans;
char a[200009];
signed main()
{
	n=read();cin>>a;
	for(int i=1;i<n;i++)
		if(a[i]==a[i-1])
		{
			ans++;
			if(a[i-1]!='R'&&a[i+1]!='R')a[i]='R';
			else if(a[i-1]!='G'&&a[i+1]!='G')a[i]='G';
			else a[i]='B';
		}
	cout<<ans<<endl;
	cout<<a<<endl;
	return 0;
}