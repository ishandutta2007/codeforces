//CF1071B
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
int n,m,a[N][N];
string s[N];
char c;
void cmax(int&x,int y){
	if(x<y)	
		x=y;
}
int main()
{
	int i,j,k,f;
	cin>>n>>m;
	for(i=0;i<n;i=i+1)
		cin>>s[i];
	for(i=0;i<n;i=i+1)
		for(j=0;j<n;j=j+1)
			a[i][j]=-1;
	a[0][0]=m;
	for(k=0;k<=n+n-2;k=k+1){
		c='z'+1;
		for(i=0;i<n;i=i+1){
			j=k-i;
			if(j<0||j>=n||a[i][j]<0)
				continue;
			//cout<<i<<j<<a[i][j]<<s[i][j]<<endl;
			if(a[i][j]&&s[i][j]>'a')
				c='a';
			else
				c=min(c,s[i][j]);
		}
		//cout<<endl;
		cout<<c;
		for(i=0;i<n;i=i+1){
			j=k-i;
			if(j<0||j>=n||a[i][j]<0)
				continue;
			if(a[i][j]&&s[i][j]>'a')
				cmax(a[i+1][j],a[i][j]-1),cmax(a[i][j+1],a[i][j]-1);
			else{
				if(s[i][j]==c)
					cmax(a[i+1][j],a[i][j]),cmax(a[i][j+1],a[i][j]);
			}
		}
	}
	return 0;
}