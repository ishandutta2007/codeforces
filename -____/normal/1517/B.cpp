#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 111;
const int inf = 1e9;
int n,m,a[N][N],b[N][N];
int main(){
	int T,i,j,k,x;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				cin>>a[i][j];
		for(k=m;k>=1;k--){
			for(i=1;i<=n;i++)
				sort(a[i]+1,a[i]+m+1);
			x=1;
			for(i=1;i<=n;i++)
				if(a[i][1]<a[x][1])
					x=i;
			b[x][k]=a[x][1];
			a[x][1]=inf;
			for(i=1;i<=n;i++)
				if(i!=x)
					b[i][k]=a[i][k],a[i][k]=inf;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)
				cout<<b[i][j]<<' ';
			cout<<endl;
		}
	}
	return 0;
}