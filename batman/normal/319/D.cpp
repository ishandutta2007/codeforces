#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)51*1000)

ll n;
char s[N],s2[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	char ch;
	while(cin>>ch)s[n++]=ch;
	for(int t=1;t<=n/2;t++)
	{
		ll m=t,now=0;
		for(int i=t;i<n;i++)
		{
			if(s[i]==s[i-t])now++;
			else now=0;
			s2[m++]=s[i];
			if(now==t)now=0,m-=t;
		}
		for(int i=t;i<m;i++)s[i]=s2[i];
		n=m;
	}
	for(int i=0;i<n;i++)cout<<s[i];
	return 0;
}