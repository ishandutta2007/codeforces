#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
 
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
 
const int N=1e6+5;

int n;
int a[N], b[N], c[N];
multiset<int> contains;

typedef struct data
{
	data* bit[2];
	int cnt=0;
}trie;

trie* head;

void insert(int x)
{
	trie* node=head;
	for(int i=60;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			if((node)->bit[1]==NULL)
			{
				(node)->bit[1]=new trie();
			}
			node=(node)->bit[1];
		}
		else
		{
			if((node)->bit[0]==NULL)
			{
				(node)->bit[0]=new trie();
			}
			node=(node)->bit[0];
		}
		(node)->cnt++;
	}
}

void remove(int x)
{
	trie* node=head;
	for(int i=60;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			node=(node)->bit[1];
		}
		else
		{
			node=(node)->bit[0];
		}
		(node)->cnt--;
	}
}

int dfs(trie** node, int x, int check, int i)
{
	if(i==-1)
	{
		if(check)
		{
			return 0;
		}
		return 2e18;
	}
	int ans=2e18;
	if((x&(1LL<<i))==0)
	{
		if((*node)->bit[1]!=NULL && (*node)->bit[1]->cnt!=0 && !check)
		{
			ans=min(ans, (1LL<<i) + dfs(&((*node)->bit[1]), x, 1, i-1));
		}
		if((*node)->bit[0]!=NULL && (*node)->bit[0]->cnt!=0)
		{
			ans=min(ans, dfs(&((*node)->bit[0]), x, check, i-1));
		}
		else if((*node)->bit[1]!=NULL && (*node)->bit[1]->cnt!=0)
		{
			ans=min(ans, (1LL<<i) + dfs(&((*node)->bit[1]), x, 1, i-1));
		}
	}
	else
	{
		if((*node)->bit[1]!=NULL && (*node)->bit[1]->cnt!=0 && check)
		{
			ans=min(ans, dfs(&((*node)->bit[1]), x, 1, i-1));
		}
		else if((*node)->bit[0]!=NULL && (*node)->bit[0]->cnt!=0)
		{
			ans=min(ans, (1LL<<i) + dfs(&((*node)->bit[0]), x, check, i-1));
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	head=new trie();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		insert(b[i]);
		contains.insert(b[i]);
	}
	int curxor=0;
	for(int i=1;i<=n;i++)
	{
		int cur=dfs(&head, curxor, 0, 60);
		a[i]=cur^curxor;
		curxor^=a[i];
		if(contains.find(a[i])==contains.end())
		{
			cout<<"No";
			return 0;
		}
		remove(a[i]);
		contains.erase(contains.find(a[i]));
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=c[i-1]^a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(c[i]<=c[i-1])
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}