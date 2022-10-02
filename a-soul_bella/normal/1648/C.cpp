#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int s[200005],t[200005],tree[200005],inv[200005],cnt[200005];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void add(int x,int y)
{
	if(x>200000) return ;
	tree[x]+=y,add(x+lowbit(x),y);
}
inline int ask(int x)
{
	if(!x) return 0;
	return tree[x]+ask(x^lowbit(x));
}
inline int cal(int x)
{
	if(!x) return 0;
	return x;
}
signed main()
{
	int n,m;
	cin >> n >> m;
	int p=1;
	inv[1]=1;
	for(int i=2;i<=n;i++)
		p=p*i%mod;
	for(int i=2;i<=200000;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i];
		add(s[i],-cal(cnt[s[i]]));
		++cnt[s[i]];
		p=p*(inv[cnt[s[i]]])%mod;
		add(s[i],cal(cnt[s[i]]));
	}
	for(int i=1;i<=m;i++)
		cin >> t[i];
	int ans=0,flag=0;
	for(int i=1;i<=min(n,m);i++)
	{
		p=p*inv[n-i+1]%mod;
		ans=(ans+p*ask(t[i]-1))%mod;
		if(!cnt[t[i]])
		{
			flag=1;
			break;
		}
		add(t[i],-cal(cnt[t[i]]));
		p=p*cnt[t[i]]%mod;
		--cnt[t[i]];
		add(t[i],cal(cnt[t[i]]));
	}
	if(!flag&&n<m) ++ans;
	cout << (ans%mod+mod)%mod;
	return 0;
}