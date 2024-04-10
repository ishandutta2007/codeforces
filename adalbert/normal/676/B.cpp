#include <bits/stdc++.h>

#define fin freopen("dijkstra.in","r",stdin)
#define fout freopen("dijkstra.out","w",stdout)
using namespace std;
int ans,k,l,n,s,f,b[2000000],t,mn,imn,p1,pn,mx,liv;
double a[100][100];
string st;
void rec(int i, int j, double k)
{
	if (i>n) return;
	a[i][j]=a[i][j]+k;
	k=a[i][j]-1;
	if (k>0)
	{
		rec(i+1,j,k/2);
		rec(i+1,j+1,k/2);
		a[i][j]=1;
	}

}
int main()
{
	cin>>n>>l;
  for (int i=1;i<=l;i++) rec(1,1,1);
  for (int i=1;i<=10;i++)
  for (int j=1;j<=i;j++)
  if (a[i][j]==1) ans++;
  cout<<ans;

}