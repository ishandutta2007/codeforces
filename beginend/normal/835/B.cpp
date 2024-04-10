#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char s[100005];
int t[30];

int main()
{
	int k;
	scanf("%d",&k);
	scanf("%s",s+1);
	int len=strlen(s+1),tot=0;
	for (int i=1;i<=len;i++) t[s[i]-'0']++,tot+=s[i]-'0';
	int now=0,ans=0;
	while (tot<k)
	{
		if (!t[now]) now++;
		else ans++,tot+=9-now,t[now]--;
	}
	cout<<ans;
	return 0;
}