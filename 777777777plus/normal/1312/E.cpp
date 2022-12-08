#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2+5;

int n;
int a[N],f[N][N],l[N][N],r[N][N];

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		f[i][i]=1;
		l[i][i]=r[i][i]=a[i];
	}
	for(int len=2;len<=n;++len)
	for(int i=1;i+len-1<=n;++i){
		int j=i+len-1;
		f[i][j]=1e9;
		for(int k=i;k<j;++k){
			if(r[i][k]==l[k+1][j]){
				if(f[i][k]+f[k+1][j]-1<f[i][j]){
					f[i][j]=f[i][k]+f[k+1][j]-1;
					l[i][j]=l[i][k]+(f[i][k]==1);
					r[i][j]=r[k+1][j]+(f[k+1][j]==1);
				}
			}
			else{
				if(f[i][k]+f[k+1][j]<f[i][j]){
					f[i][j]=f[i][k]+f[k+1][j];
					l[i][j]=l[i][k];
					r[i][j]=r[k+1][j];
				}
			}
		}
	}
	cout<<f[1][n]<<endl;
}