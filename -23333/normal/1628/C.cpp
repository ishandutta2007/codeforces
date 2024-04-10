#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=n;i--)
const int N=5e5;
int a[2000][2000],b[2000][2000],ans;
void gao(int x,int y)
{
	ans^=b[x][y];
	a[x-1][y]^=1; a[x+1][y]^=1;
	a[x][y-1]^=1; a[x][y+1]^=1;
}
int main()
{
	int T;
	cin>>T;
	while (T--)
    { 
		int n;
		cin>>n;
		rep(i,1,n)
		  rep(j,1,n) 
		  {
		    cin>>b[i][j];
		    a[i][j]=0;
		  }
		ans=0;  
		rep(i,1,n)
		{
			gao(1,i);
		}
		rep(i,2,n)
		{
			rep(j,1,n) if (!a[i-1][j]) gao(i,j); 
		}
//		rep(i,1,n)
//		{
//		  rep(j,1,n)
//		  {
//		  	cout<<a[i][j]<<" ";
//		  }
//		  cout<<endl; 
//	    }
        cout<<ans<<endl;
	} 
	return 0; 
}