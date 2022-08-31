//CF1063B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 2222;
int n,m,r,c,x,y,a[N][N];
string s[N];
int he,ta,qx[N*N*2],qy[N*N*2];
int main()
{
	int i,j,o,xx,yy;
	cin>>n>>m>>r>>c>>x>>y;
	r--,c--;
	for(i=0;i<n;i=i+1)
		cin>>s[i];
	for(i=0;i<n;i=i+1)
		for(j=0;j<m;j=j+1)
			a[i][j]=-1;
	he=N*N,ta=he+1;
	qx[he]=r,qy[he]=c;
	a[r][c]=0;
	while(he<ta){
		i=qx[he],j=qy[he],he++;
		if(i&&s[i-1][j]=='.'&&a[i-1][j]<0){
			a[i-1][j]=a[i][j];
			he--,qx[he]=i-1,qy[he]=j;
		}
		if(i+1<n&&s[i+1][j]=='.'&&a[i+1][j]<0){
			a[i+1][j]=a[i][j];
			he--,qx[he]=i+1,qy[he]=j;
		}
		if(j&&s[i][j-1]=='.'&&a[i][j-1]<0){
			a[i][j-1]=a[i][j]+1;
			qx[ta]=i,qy[ta]=j-1,ta++;
		}
		if(j+1<m&&s[i][j+1]=='.'&&a[i][j+1]<0){
			a[i][j+1]=a[i][j]+1;
			qx[ta]=i,qy[ta]=j+1,ta++;
		}
	}
	o=0;
	for(i=0;i<n;i=i+1){
		for(j=0;j<m;j=j+1){
			if(s[i][j]!='.'||a[i][j]==-1)
				continue;
			xx=(a[i][j]+c-j)/2;
			yy=(a[i][j]+j-c)/2;
			if(xx<=x&&yy<=y)
				o++;
		}
	}
	cout<<o;
	return 0;
}