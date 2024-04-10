#include <bits/stdc++.h>

using namespace std;

struct aho
{
	#define alf 4
	struct node
	{
		int go[alf];
		int leaf=0;
		int p=-1;
		char pch;
		int link=-1;
		node(int p=-1, char ch='$') : p(p), pch(ch)
		{
			fill(begin(go), end(go), -1);
		}
	};
	vector <node> v;
	aho()
	{
		v.resize(1);
	}
	void add_string(string s)
	{
		int x=0;
		for(char i:s)
		{
			int c=i-'a';
			if(v[x].go[c]==-1)
			{
				v[x].go[c]=v.size();
				v.emplace_back(x, i);
			}
			x=v[x].go[c];
		}
		v[x].leaf=s.size();
	}
	void construct()
	{
		queue <int> que;
		que.push(0);
		while(!que.empty())
		{
			int x=que.front();
			que.pop();
			if(!x || !v[x].p) v[x].link=0;
			else v[x].link=v[v[v[x].p].link].go[v[x].pch-'a'];
			for(int i=0; i<alf; ++i)
			{
				if(v[x].go[i]==-1)
				{
					if(!x) v[x].go[i]=0;
					else v[x].go[i]=v[v[x].link].go[i];
				}
				else que.push(v[x].go[i]);
			}
		}
	}
};

#define N 1001
#define M 11

int n, m, ml, si, mod=1e9+9;
int dp[N][M*M][M];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	aho ah;
	cin>>n>>m;
	vector <string> vs;
	for(int i=1; i<=m; ++i)
	{
		string s;
		cin>>s;
		for(int j=0; j<(int)s.size(); ++j)
		{
			if(s[j]=='A') s[j]='a';
			else if(s[j]=='C') s[j]='b';
			else if(s[j]=='G') s[j]='c';
			else s[j]='d';
		}
		vs.push_back(s);
		ah.add_string(s);
		ml=max(ml, (int)s.size());
	}
	si=ah.v.size();
	for(auto i:vs)
	{
		for(int j=0; j<si; ++j)
		{
			int x=j;
			bool ok=true;
			for(auto k:i)
			{
				if(ah.v[x].go[k-'a']==-1)
				{
					ok=false;
					break;
				}
				x=ah.v[x].go[k-'a'];
			}
			if(ok) ah.v[x].leaf=max(ah.v[x].leaf, (int)i.size());
		}
	}
	ah.construct();
	//~ for(int i=0; i<si; ++i)
	//~ {
		//~ printf("(%d) %d: ", ah.v[i].leaf, i);
		//~ for(int j=0; j<4; ++j) printf("%d ", ah.v[i].go[j]);
		//~ printf("\n");
	//~ }
	//~ printf("\n");
	dp[0][0][0]=1;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<si; ++j)
		{
			for(int k=0; k<4; ++k)
			{
				int x=ah.v[j].go[k];
				int y=ah.v[x].leaf;
				for(int g=0; g<y; ++g)
				{
					//~ if(dp[i][j][g]) printf("dp[%d][%d][%d]+=%d\n", i+1, x, 0, dp[i][j][g]);
					dp[i+1][x][0]+=dp[i][j][g];
					if(dp[i+1][x][0]>=mod) dp[i+1][x][0]-=mod;
				}
				for(int g=y; g<ml-1; ++g)
				{
					//~ if(dp[i][j][g]) printf("dp[%d][%d][%d]+=%d\n", i+1, x, g+1, dp[i][j][g]);
					dp[i+1][x][g+1]+=dp[i][j][g];
					if(dp[i+1][x][g+1]>=mod) dp[i+1][x][g+1]-=mod;
				}
			}
		}
	}
	int odp=0;
	for(int i=0; i<si; ++i)
	{
		odp+=dp[n][i][0];
		if(odp>=mod) odp-=mod;
	}
	printf("%d\n", odp);
	return 0;
}