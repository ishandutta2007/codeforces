#include <iostream>
#include <string>
#include <vector>

#define M 300100
#define A 26

using namespace std;

int n,m,nb,p[M],link[M][A],ans=0;
string t;
vector<int> g[M];
vector<char> s[M];

void read(void){
	cin>>n;
	nb=n;
	for (int i=2,x; i<=n; ++i){
		cin>>x>>t;
		int len=t.length(),x1=x;
		for (int j=0; j+1<len; ++j){
			g[x1].push_back(++nb);
			s[x1].push_back(t[j]);
			x1=nb;
		}
		g[x1].push_back(i);
		s[x1].push_back(t[len-1]);
	}
}

void cmp(void){
	cin>>t;
	m=t.length();
	for (int i=1; i<m; ++i){
		int j=p[i-1];
		while (j>0 && t[j]!=t[i])
		j=p[j-1];
		if (t[j]==t[i])
		++j;
		p[i]=j;
	}
	
	for (int i=0; i<=m; ++i)
	for (int j=0; j<A; ++j){
		char ch=j+'a';
		int k=i;
		if (k<m && t[k]==ch)
		link[i][j]=i+1;
		else{
			if (i>0)
			link[i][j]=link[p[i-1]][j];
			else
			link[i][j]=0;
		}
	}
}

void dfs(int v, int st){
	if (st==m)
	ans++;
	for (int i=0; i<(int)g[v].size(); ++i){
		int to=g[v][i],st1=link[st][s[v][i]-'a'];
		dfs(to,st1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	cmp();
	dfs(1,0);
	cout<<ans<<"\n";
	return 0;
}