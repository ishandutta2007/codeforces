#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define eps 1e-8
#define PB push_back
#define MP make_pair
using namespace std;
double pi=asin(1.0)*2;

string a,b;
int f[1100][1100];
int fr[1100][1100];
int n,m;
vector<int> ans;

void relax(int i,int j,int k,int d){
	if (f[i][j]==-1||f[i][j]>k){
		f[i][j]=k;
		fr[i][j]=d;
	}
}

int main(){
	cin>>a>>b;
	n=a.size();m=b.size();
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for (int i=0;i<=n;i++)
	for (int j=0;j<=m;j++)
	if (f[i][j]!=-1){
		if (i!=n&&j!=m){
			if (a[i]==b[j]) relax(i+1,j+1,f[i][j],-1);
			else relax(i+1,j+1,f[i][j]+1,0);
		}
		if (i!=n) relax(i+1,j,f[i][j]+1,1);
		if (j!=m) relax(i,j+1,f[i][j]+1,2);
	}
	printf("%d\n",f[n][m]);
	ans.clear();
	for (int i=n,j=m;;){
		if (i==0&&j==0) break;
		ans.PB(fr[i][j]);
		if (fr[i][j]==-1) i--,j--;
		else if (fr[i][j]==0) i--,j--;
		else if (fr[i][j]==1) i--;
		else j--;
	}
	for (int i=0,j=0,k=(int)ans.size()-1;k>=0;k--){
		//printf("%d %d %d\n",ans[k],i,j);
		if (ans[k]==-1) i++,j++;
		else if (ans[k]==0) printf("REPLACE %d %c\n",j+1,b[j]),i++,j++;
		else if (ans[k]==1) printf("DELETE %d\n",j+1),i++;
		else if (ans[k]==2) printf("INSERT %d %c\n",j+1,b[j]),j++;
	}
	return 0;
}