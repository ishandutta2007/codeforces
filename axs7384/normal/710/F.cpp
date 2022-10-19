#include<bits/stdc++.h>
using namespace std;
const int N=600005;
struct AC_automaton
{
	int top,cnt;
	int c[N][26],fail[N],size[N],s[N],sum[N],q[N],root[N];
	inline int merge(int x,int y)
	{
		if (!x|!y)
			return x|y;
		s[x]+=s[y];
		for (int i=0;i<26;++i)
			c[x][i]=merge(c[x][i],c[y][i]);
		return x;
	}
	inline void get_fail(int x)
	{
		int l=0,r=0;
		for (int i=0;i<26;i++)
			if (c[x][i])
			{
				fail[c[x][i]]=x;
				q[++r]=c[x][i];
				sum[c[x][i]]=s[c[x][i]];
			}
		while (l!=r)
		{
			int now=q[++l];
			for (int i=0;i<26;i++)
				if (c[now][i])
				{
					int to=c[now][i],k=fail[now];
					while (k!=x&&!c[k][i])
						k=fail[k];
					if (c[k][i])
						fail[to]=c[k][i];
					else
						fail[to]=x;
					q[++r]=to; 
					sum[to]=sum[fail[to]]+s[to];
				}
		}
	}
	inline void insert(char S[])
	{
		root[++top]=++cnt;
		size[top]=1;
		int len=strlen(S),x=root[top];
		for (int i=0;i<len;++i)
		{
			c[x][S[i]-'a']=++cnt;
			x=c[x][S[i]-'a'];
		}
		s[x]=1;
		while (top!=1&&size[top]==size[top-1])
		{
			root[top-1]=merge(root[top-1],root[top]);
			--top;
			size[top]*=2;
		}
		get_fail(root[top]);
	}
	inline int ask(char S[])
	{
		int ans=0,len=strlen(S);
		for (int i=1;i<=top;++i)
		{
			int x=root[i];
			for (int j=0;j<len;++j)
			{
				while (!c[x][S[j]-'a']&&x!=root[i])
					x=fail[x];
				if (c[x][S[j]-'a'])
				{
					x=c[x][S[j]-'a'];
					ans+=sum[x];
				}
			}
		}
		return ans;
	}
}a,b;
char s[N];
int n,opt;
int main()
{
	// freopen("710f.in","r",stdin);
	// freopen("710f.out","w",stdout);
	a.top=b.top=a.cnt=b.cnt=0;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d%s",&opt,s);
		if (opt==1)
			a.insert(s);
		if (opt==2)
			b.insert(s);
		if (opt==3)
		{
			cout<<a.ask(s)-b.ask(s)<<endl;
		}
	}
	return 0;
}