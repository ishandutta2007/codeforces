#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n,tree[100005];
string s,t;
vector<int> p[26];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void add(int x,int y)
{
	if(x>n) return ;
	tree[x]+=y,add(x+lowbit(x),y);
}
inline int ask(int x)
{
	if(!x) return x;
	return tree[x]+ask(x^lowbit(x));
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> s >> t;
		s=' '+s,t=' '+t;
		for(int i=1;i<=n;i++) tree[i]=0;
		for(int i=0;i<=25;i++) p[i].clear();
		for(int i=n;i>=1;i--) p[s[i]-'a'].push_back(i);
		long long ans=1e18,now=0;
		for(int i=1;i<=n;i++)
		{
			long long mn=1e18;
			for(int j=0;j<t[i]-'a';j++)
				if(!p[j].empty()) mn=min(mn,(long long)p[j].back());
			if(mn!=1e18) ans=min(ans,now+mn-i+ask(n)-ask(mn));
			if(p[t[i]-'a'].empty()) break;
			now+=p[t[i]-'a'].back()-i+ask(n)-ask(p[t[i] -'a'].back());
			add(p[t[i]-'a'].back(),1);
			p[t[i]-'a'].pop_back();
		}
		if(ans>1e17) ans=-1;
		cout << ans << "\n";
	}
	return 0;
}