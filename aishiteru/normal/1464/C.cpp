#include<bits/stdc++.h>
using namespace std; 
const int N=100005,M=533;
const long double PI=3.1415926535897932384626;
int n,m,i,p[26];
long long t,s;
char c[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %lld",&n,&t);
	scanf("%s",c+1);
	t+=1<<c[n-1]-'a';
	t-=1<<c[n]-'a';
	for(i=1;i<=n-2;++i)
		s+=1<<c[i]-'a';
	s-=t;
	for(i=1;i<=n-2;++i)
		++p[c[i]-'a'];
	for(i=25;i>=0;--i)
		while(s>=(1<<i+1)&&p[i])
		{
			--p[i];
			s-=(1<<i+1);
		}
	puts(s==0?"Yes":"No");
}