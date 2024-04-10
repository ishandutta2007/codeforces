#include<bits/stdc++.h>
#define pb push_back

typedef long long LL;

const int N=100005;

int n,m,mu[N],prime[N],tot,stack[N],b[N],s[N];
std::vector<int> vec[N];
bool a[N],not_prime[N];

int gcd(int x,int y)
{
	return !y?x:gcd(y,x%y);
}

void get_prime(int n)
{
	mu[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i,mu[i]=-1;
		for (int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=1;
			if (i%prime[j]==0) break;
			mu[i*prime[j]]=-mu[i];
		}
	}
}

void ins(int x,int y)
{
	for (auto t:vec[x]) s[t]+=y;
}

int query(int x)
{
	int ans=0;
	for (auto t:vec[x]) ans+=s[t]*mu[t];
	return ans;
}

LL solve(int n)
{
	int top=0;stack[++top]=b[n];
	ins(b[n],1);
	LL ans=b[n];
	for (int i=n-1;i>=1;i--)
	{
		int w=query(b[i]);
		if (w) while (top&&gcd(stack[top],b[i])>1) ins(stack[top--],-1);
		while (w>1)
		{
			w--;ins(stack[top--],-1);
			while (top&&gcd(stack[top],b[i])>1) ins(stack[top--],-1);
		}
		if (w) ans=std::max(ans,(LL)stack[top]*b[i]);
		stack[++top]=b[i];
		ins(b[i],1);
	}
	while (top) ins(stack[top--],-1);
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++) scanf("%d",&x),a[x]=1,m=std::max(m,x);
	get_prime(m);
	for (int i=1;i<=m;i++)
		if (mu[i])
			for (int j=i;j<=m;j+=i) vec[j].pb(i);
	LL ans=m;
	for (int i=1;i<=m;i++)
	{
		int tot=0;
		for (int j=i;j<=m;j+=i) if (a[j]) b[++tot]=j/i;
		ans=std::max(ans,(LL)i*solve(tot));
	}
	printf("%lld\n",ans);
	return 0;
}