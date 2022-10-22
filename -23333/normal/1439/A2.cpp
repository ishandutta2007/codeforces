#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
	return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T>void read(T &x)
{
	int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
	while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
}
const int N=200;
char cc[N];
int a[N][N],n,m;
struct re{
	int a,b;
}c[N*N],d[10],e[10];
int main()
{
	ios::sync_with_stdio(false);
	int T,n;
	cin>>T;
	int ans=0;
	while(T--)
	{
		cin>>n>>m; int cnt=0;
		rep(i,1,n)
		{ 
		  cin>>cc;
		  rep(j,1,m) a[i][j]=cc[j-1]-'0';
	    }
		for (int i=1;i<=n;i+=2)
		{
			if (i==n) i--;
			for (int j=1;j<=m;j+=2)
			{
				if (j==m) j--;
				int ans=a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];
				int cnt2=0,cnt3=0;
				if (a[i][j]) d[++cnt2]=(re){i,j}; else e[++cnt3]=(re){i,j};
				if (a[i][j+1]) d[++cnt2]=(re){i,j+1}; else e[++cnt3]=(re){i,j+1};
				if (a[i+1][j]) d[++cnt2]=(re){i+1,j}; else e[++cnt3]=(re){i+1,j};
				if (a[i+1][j+1]) d[++cnt2]=(re){i+1,j+1}; else e[++cnt3]=(re){i+1,j+1};
				if (j==m-2)
				{
					if (a[i][j]&&a[i+1][j])
					{
						c[++cnt]=(re){i,j}; c[++cnt]=(re){i+1,j}; c[++cnt]=(re){i,j+1};
						a[i][j]^=1; a[i+1][j]^=1; a[i][j+1]^=1;
					} 
					else if (a[i][j])
					{ 
					c[++cnt]=(re){i,j}; c[++cnt]=(re){i,j+1}; c[++cnt]=(re){i+1,j+1};
					  a[i][j]^=1; a[i+1][j+1]^=1; a[i][j+1]^=1;
				    } else
					if (a[i+1][j])
					{ 
					c[++cnt]=(re){i+1,j}; c[++cnt]=(re){i,j+1}; c[++cnt]=(re){i+1,j+1};
					  a[i+1][j]^=1; a[i+1][j+1]^=1; a[i][j+1]^=1;
				    }
					continue;
			    }
			    if (i==n-2)
			    {
			    	if (a[i][j]&&a[i][j+1])
					{
						c[++cnt]=(re){i,j}; c[++cnt]=(re){i,j+1}; c[++cnt]=(re){i+1,j};
						a[i][j]^=1; a[i+1][j]^=1; a[i][j+1]^=1;
					} 
					else if (a[i][j])
					{ 
					c[++cnt]=(re){i,j}; c[++cnt]=(re){i+1,j}; c[++cnt]=(re){i+1,j+1};
					  a[i][j]^=1; a[i+1][j+1]^=1; a[i+1][j]^=1;
				    } else
					if (a[i][j+1])
					{ 
					c[++cnt]=(re){i,j+1}; c[++cnt]=(re){i+1,j}; c[++cnt]=(re){i+1,j+1};
					  a[i+1][j]^=1; a[i+1][j+1]^=1; a[i][j+1]^=1;
				    }
					continue;
			    }
				if (ans==3)
				{
					c[++cnt]=d[1]; c[++cnt]=d[2]; c[++cnt]=d[3];
				}
				if (ans==2)
				{
					c[++cnt]=e[1]; c[++cnt]=e[2]; c[++cnt]=d[1];
					c[++cnt]=e[1]; c[++cnt]=e[2]; c[++cnt]=d[2];
				}
				if (ans==1)
				{
					c[++cnt]=e[1]; c[++cnt]=e[2]; c[++cnt]=d[1];
					c[++cnt]=e[1]; c[++cnt]=e[3]; c[++cnt]=d[1];
					c[++cnt]=e[2]; c[++cnt]=e[3]; c[++cnt]=d[1];
				}
				if (ans==4)
				{
					c[++cnt]=d[1]; c[++cnt]=d[2]; c[++cnt]=d[3];
					c[++cnt]=d[1]; c[++cnt]=d[2]; c[++cnt]=d[4];
					c[++cnt]=d[3]; c[++cnt]=d[4]; c[++cnt]=d[1];
					c[++cnt]=d[3]; c[++cnt]=d[4]; c[++cnt]=d[2];
				}
				a[i][j]=a[i+1][j]=a[i][j+1]=a[i+1][j+1]=0;
			}
	    }
	    cout<<cnt/3<<endl;
	
	    rep(i,1,cnt)
	    {
	    	cout<<c[i].a<<" "<<c[i].b<<" ";
	    	if (i%3==0) cout<<endl;
	    } 
    }
	return 0; 
}