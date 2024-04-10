#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=4e5;
vector<int> p[N];
int f[N][6],g[N];
int n,m;
bool check(int x,int x1,int y,int y1)
{
	rep(i,1,m) g[i]=p[1][i];
	g[x]=x1; g[y]=y1;
	rep(i,2,n)
	{
	  int cnt=0;
	  rep(j,1,m)
	    if (p[i][j]!=g[j]) cnt++;
	  if (cnt>2) return 0;
    }
	cout<<"Yes"<<endl;
	p[1][x]=x1; p[1][y]=y1;
    rep(i,1,m) cout<<p[1][i]<<" ";
    return 1;
}
bool check3(int x,int x1,int y,int y1)
{
	rep(i,2,n)
	{
		int c=f[i][0];
		rep(j,1,f[i][0])
		{
		  if (f[i][j]==x&&p[i][x]==x1) c--;
		  if (f[i][j]==y&&p[i][y]==y1) c--;
	    }
	    if (p[i][x]==p[1][x]) c++;
	    if (p[i][y]==p[1][y]) c++;
	    if (c>2) return 0;
	}
	p[1][x]=x1; p[1][y]=y1;
	
			cout<<"Yes"<<endl;
	rep(i,1,m) cout<<p[1][i]<<" ";
	return 1;
}
bool check2(int x,int x1)
{
	rep(i,2,n)
	{
	   int c=f[i][0];
	   rep(j,1,f[i][0]) if (f[i][j]==x&&p[i][x]==x1) c--;
	   if (p[i][x]==p[1][x]) c++;
	   if (c>3) return 0;
	   if (c==3)
	   {
	   	   rep(j,1,f[i][0])
	   	   if (f[i][j]!=x)
	   	   {
	   	     bool tt=check3(x,x1,f[i][j],p[i][f[i][j]]);
	   	     if (tt) return 1;
	   	   }
	   	   return 0;
	   }
	}
	p[1][x]=x1;
	
			cout<<"Yes"<<endl;
	rep(i,1,m) cout<<p[1][i]<<" ";
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;

		cin>>n>>m;
		rep(i,1,n)
		{
	      p[i].push_back(0);
		  rep(j,1,m)
		  {
		  	int x;
		  	cin>>x;
		    p[i].push_back(x);
		  }
		}
		rep(i,2,n)
		{
			rep(j,1,m)
			  if (p[i][j]!=p[1][j])
			  {
			  	f[i][++f[i][0]]=j;
			  	if (f[i][0]==5)
				{
					cout<<"No"<<endl; return 0;
				}
			  } 
		}
	    int ans=0;
		rep(i,2,n) ans=max(ans,f[i][0]);
		if (ans<=2)
		{
			cout<<"Yes"<<endl;
			rep(i,1,m) cout<<p[1][i]<<" ";
			return 0;
		} else
		if (ans==4)
		{
			int k=0;
			rep(i,2,n) if (f[i][0]==4) { k=i; break;}
			rep(i,1,4)
			  rep(j,i+1,4)
			  {
			    int tt=check(f[k][i],p[k][f[k][i]],f[k][j],p[k][f[k][j]]);
			    if (tt) return 0;
			  }
		} else
		{
			int k=0;
			rep(i,2,n) if (f[i][0]==3) {k=i; break;}
			rep(i,1,3)
			{
				int tt=check2(f[k][i],p[k][f[k][i]]);
				if (tt) return 0;
			}
		}
		cout<<"No"<<endl;
	return 0;
}