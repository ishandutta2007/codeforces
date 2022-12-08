#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define N 2001
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,x,a,ans,r[N],t[N][N];
bool f[N][N];
int main()
{
	cin>>n;
	for(int _=1;_<=n;_++)
	  while(scanf("%d:",&x))
	    {
	    r[_]++;
	    for(int i=1;i<x;i++)
	      scanf("%d,",&a),t[_][a]=x;
	    scanf("%d",&a),t[_][a]=x;
	    if(getchar()!='-')break;
		}
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
	    if(t[i][j]+t[j][i]==n)
	      f[i][j]=f[j][i]=true,ans++;
	if(ans!=(n-1))return printf("-1\n"),0;
	for(int i=1;i<=n;i++)
	  {
	  a=0;
	  for(int j=1;j<=n;j++)
	    if(f[i][j])a++;
	  if(a!=r[i])return printf("-1\n"),0;
	  }
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
	    if(f[i][j])
	      cout<<i<<" "<<j<<endl;
}