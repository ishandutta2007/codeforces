#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int M=1000000007;
typedef long double lb;
int n,m,i,j,t,k,tot;
int p[N];
string q[N];
void op(int n,string s,int len)
{
	if(k==0)
		return;
	if(n==0)
		return;
	if(k>=n*len)
	{
		p[++tot]=n;
		q[tot]=s;
		k-=n*len;
	}
	else
	{
		if(k/len!=0)
		{
			p[++tot]=k/len;
			q[tot]=s;
		}
		k%=len;
		if(k)
		{
			p[++tot]=1;
			for(int i=0;i<k;++i)
				q[tot]+=s[i];
			k=0;
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d",&n,&m,&k);
	if(k>4*n*m-2*n-2*m)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(i=1;i<m;++i)
	{
		string s="DRL";
		op(n-1,s,3);
		s="U";
		op(n-1,s,1);
		s="R";
		op(1,s,1);
	}
	string s="D";
	op(n-1,s,1);
	s="U";
	op(n-1,s,1);
	s="L";
	op(m-1,s,1);
	cout<<tot<<endl;
	for(i=1;i<=tot;++i)
		cout<<p[i]<<' '<<q[i]<<endl;
}