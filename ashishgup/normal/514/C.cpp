#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N=3e5+5;

int n, m, sz;
int store=1;
string str;
int trie[1200005][3];
int cnt[1200005], endnode[1200005];

void insert(string &s)
{
	int v=0;
	int sz=s.size();
	for(int i=0;i<sz;i++)
	{
		int cur=s[i]-'a';
		if(trie[v][cur]==-1)
			trie[v][cur]=store++;
		v=trie[v][cur];
		cnt[v]++;
	}
	endnode[v]=1;
}

bool search(string &s)
{
	int v=0;
	int sz=s.size();
	for(int i=0;i<sz;i++)
	{
		int cur=s[i]-'a';
		if(trie[v][cur]==-1)
			return 0;
		v=trie[v][cur];
	}
	return endnode[v];
}

int check(int i, int v, int cnt)
{
	if(cnt>1)
		return 0;
	if(i==sz)
	{
		if(cnt==1 && endnode[v])
			return 1;
		return 0;
	}
	int curcheck=0;
	int cur=str[i]-'a';
	for(int j=0;j<=2;j++)
	{
		if(trie[v][j]==-1)
			continue;
		if(j!=cur)
		{
			curcheck|=check(i+1, trie[v][j], cnt+1);
		}
		else
		{
			curcheck|=check(i+1, trie[v][j], cnt);
		}
	}
	return curcheck;
}

int32_t main()
{
	IOS;
	memset(trie, -1, sizeof(trie));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		insert(s);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>str;
		sz=str.size();
		if(check(0, 0, 0))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}