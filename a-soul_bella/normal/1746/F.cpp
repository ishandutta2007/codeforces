#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
mt19937 rnd(22632424);
const int B=30;
signed w[600005][B],a[600005];
struct bit
{
	int tree[300005];
	int lowbit(int x)
	{
		return x&-x;
	}
	void add(int x,int y)
	{
		if(x>300000) return ;
		tree[x]+=y,add(x+lowbit(x),y);
	}
	int ask(int x)
	{
		if(!x) return 0;
		return tree[x]+ask(x^lowbit(x));
	}
}T[B];
map<int,int> mp;
int cnt=0;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=600000;i++)
	{
		for(int j=0;j<B;j++)
			w[i][j]=rnd();
	}
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(!mp[a[i]]) mp[a[i]]=++cnt;
		a[i]=mp[a[i]];
		for(int j=0;j<B;j++)
			T[j].add(i,w[a[i]][j]);
	}
	while(q--)
	{
		int op;
		cin >> op;
		if(op==1)
		{
			int x,y;
			cin >> x >> y;
			for(int j=0;j<B;j++)
				T[j].add(x,-w[a[x]][j]);
			a[x]=y;
			if(!mp[a[x]]) mp[a[x]]=++cnt;
			a[x]=mp[a[x]];
			for(int j=0;j<B;j++)
				T[j].add(x,w[a[x]][j]);
		}
		else
		{
			int l,r,k,flag=1;
			cin >> l >> r >> k;
			for(int j=0;j<B;j++)
			{
				int A=T[j].ask(r)-T[j].ask(l-1);
				if(A%k!=0) flag=0;
			}
			if(flag) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}