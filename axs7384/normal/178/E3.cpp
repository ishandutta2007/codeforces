#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	char c=getchar();
	x=0;
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
const int N=2005;
const double pi=acos(-1.0);
int a[N][N],f[N][N];
int n,m,sum;
int ans1,ans2;
int shang,xia,zuo,you;
inline void dfs(int x,int y)
{
	a[x][y]=0;	
	//f[x][y]=1;
	++sum;
    if (x>xia||(x==xia&&y>you))
    {
    	xia=x;
    	you=y;
    }
    if (x<shang||(x==shang&&y<zuo))
    {
    	shang=x;
    	zuo=y;
    }
	/*shang=min(x,shang);
	xia=max(x,xia);
	zuo=min(y,zuo);
	you=max(y,you);*/
	if (x<n&&a[x+1][y])
		dfs(x+1,y);
	if (x>=2&&a[x-1][y])
		dfs(x-1,y);
	if (y<n&&a[x][y+1])
		dfs(x,y+1);
	if (x>=2&&a[x][y-1])
		dfs(x,y-1);
}
inline long long sqr(int x)
{
	return (long long)x*x;
}
/*inline bool check()
{
	int midx=(shang+xia)/2,midy=(zuo+you)/2,r=(midx-shang+midy-zuo)/2,sum1=0,sum2=0;;
	for (int i=shang;i<=xia;++i)
		for (int j=zuo;j<=you;++j)
			if (sqr(i-shang)+sqr(j-zuo)>sqr(r))
			{
				++sum1;
				sum2+=f[i][j];
			}
	if ((double)sum2/sum1>0.25)
		return false;
	return true;		
}*/
int main()
{	
	read(n);
    for (int i=1;i<=n;++i)
    	for (int j=1;j<=n;++j)
    		read(a[i][j]);
   	for (int i=1;i<=n;++i)
   		for (int j=1;j<=n;++j)
   			if (a[i][j])
   			{
   				sum=0;
   				shang=N;
   				xia=0;
   				zuo=N;
   				you=0;
   				dfs(i,j);
   				double p=((double)(xia-shang)*(xia-shang)+(you-zuo)*(you-zuo))/2.0;
				if (sum<150)
					continue;
				//if ((fabs(sum-p)<p*0.05)&&check()) 
				if ((double)sum>p*1.1)
					++ans1;
				else 
					++ans2;
   			}
   	cout<<ans1<<' '<<ans2<<'\n';
   	return 0;
   	
}