#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=2.1e6;
const int M=2.1e6;
struct sat{
	vector<int> ve[M],ve2[M];
	bool vis[M];
	stack<int> ss;
	int dfn[M],low[M],col[M],kk[M],op[M],In[M],tim,cnt;
	void init()
	{
	}
	void add(int x,int y)
	{
		ve[x].push_back(y);
	//	cerr<<x<<" "<<y<<endl; 
	}
	void add2(int x,int y)
	{
		ve2[x].push_back(y);
	}
	void tarjan(int x)
	{
		vis[x]=1; dfn[x]=low[x]=++tim;
		ss.push(x);
		for (auto v:ve[x])
		{
			if (!dfn[v]) tarjan(v),low[x]=min(low[x],low[v]);
			else if (vis[v]) low[x]=min(low[x],low[v]);
		}
		if (dfn[x]==low[x])
		{
			int y; col[x]=++cnt;
			do{
				y=ss.top(); ss.pop();
				vis[y]=0;
				col[y]=cnt;
			}while (x!=y);
		}
	}
	void Top_sort()
	{
		queue<int> q;
		rep(i,1,cnt) if (!In[i]) q.push(i);
		while (!q.empty())
		{
			int x=q.front(); q.pop();
			if (!kk[x]) kk[x]=1,kk[op[x]]=-1;
		    for (auto v:ve2[x])
		      if ((--In[v])==0) q.push(v);
		}
	}
	bool solve(int n)
	{
		rep(i,1,2*n) if (!dfn[i]) tarjan(i);
		rep(i,1,n)
		{
			if (col[i]==col[i+n]) return 0;
			op[col[i]]=col[i+n];
			op[col[i+n]]=col[i];
		}
		rep(i,1,2*n)
		  for (auto v:ve[i])
		    if (col[v]!=col[i])
		    {
		    	add2(col[v],col[i]);
		    	In[col[i]]++;
		    }
		Top_sort();
		return 1;
	}
}S;
vector<int> ve[N];
int bz[20][N],dep[N];
char s[N];
void dfs(int x,int y)
{
	bz[0][x]=y; dep[x]=dep[y]+1;
	for (auto v:ve[x])
	  if (v!=y)
	  {
	  	 dfs(v,x);
	  }
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	dep(i,19,0)
	  if (dep[bz[i][x]]>=dep[y]) x=bz[i][x];
	if (x==y) return x;
	dep(i,19,0)
	  if (bz[i][x]!=bz[i][y]) x=bz[i][x],y=bz[i][y];
	return bz[0][x];
}
char gg[N][2];
bool tt[N];
int main()
{
	ios::sync_with_stdio(false);
	
	int n,m; 
	cin>>n>>m;
	rep(i,1,n-1)
	{
		int x,y;
		cin>>x>>y;
		ve[x].push_back(y); ve[y].push_back(x);
	}
	dfs(1,0);
	rep(i,1,19)
	  rep(j,1,n) bz[i][j]=bz[i-1][bz[i-1][j]];
	int ans=1;
	rep(i,1,m)
	{
		int xx,yy;
		cin>>xx>>yy>>s;
		int nn=strlen(s);
		int k=lca(xx,yy);
		int t=1;
		for (auto x:{xx,yy})
		{
			t^=1;
		    int cnt=0;
			while (1)
			{
				char c1=s[cnt],c2=s[nn-cnt-1];
				if (t) swap(c1,c2);
				if (!tt[x])
				{
					gg[x][0]=c1; tt[x]=1;
					if (c1!=c2) gg[x][1]=c2; else gg[x][1]='X';
				}
				if (c1==c2)
				{
					#define P(x) (x+n+m)
					if (c1==gg[x][0])
					{
						S.add(i+n,x);  // or,
						S.add(P(x),P(i+n));
						S.add(P(i+n),x);
						S.add(P(x),i+n);
					} else
					if (c1==gg[x][1])
					{
						S.add(i+n,P(x));// or 
						S.add(x,P(i+n));
						S.add(P(i+n),P(x));
						S.add(x,i+n);
			    	} else ans=0; 
				} else
				{
					if (c1==gg[x][0])
					{
						S.add(i+n,x);// 
						S.add(P(x),P(i+n)); 
					} else
					if (c1==gg[x][1])
					{
						S.add(i+n,P(x));//  
						S.add(x,P(i+n));
				    } else
					{
						S.add(i+n,P(i+n));//   
				    }
				    if (c2==gg[x][0])
					{
						S.add(P(i+n),x);// 
						S.add(P(x),i+n); 
				    } else if (c2==gg[x][1])
					{
						S.add(P(i+n),P(x));//
						S.add(x,i+n); 
				    } else
					{
						S.add(P(i+n),i+n);//  
				    }
				}
				if (x==k) break;
				x=bz[0][x]; cnt++;
			}
		}
	}
	int ans2=S.solve(n+m);
	if (ans+ans2!=2)
	{
		cout<<"NO"<<endl;
	} else
	{
		cout<<"YES"<<endl;
		rep(i,1,n)
		  if (!tt[i]) cout<<'a';
		  else
		  if (S.kk[S.col[i]]==1)
		  {
		  	 cout<<gg[i][0];
		  } else cout<<gg[i][1];
	}
	return 0;
}