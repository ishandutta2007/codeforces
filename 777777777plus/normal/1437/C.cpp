#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e2+5;

int T;
int n,t[N];
int f[N][N*2];

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>t[i];
		sort(t+1,t+n+1);
		for(int i=0;i<=n;++i)
		for(int j=0;j<=2*n;++j)
		f[i][j]=1e9;
		f[0][0]=0;
		for(int i=0;i<n;++i)
		for(int j=i;j<=2*n;++j)
		if(f[i][j]<1e9){
			for(int k=j+1;k<=2*n;++k)
			f[i+1][k]=min(f[i+1][k],f[i][j]+abs(k-t[i+1]));
		}
		cout<<*min_element(f[n]+1,f[n]+2*n+1)<<endl;
	}
}