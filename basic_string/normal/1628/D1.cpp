#include<bits/stdc++.h>
using namespace std;
const int N=2009,P=1e9+7,iv=P+1>>1;
int f[N][N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j;
	for(i=1;i<N;++i){
		for(j=1;j<i;++j){
			f[i][j]=(f[i-1][j-1]+f[i-1][j])*1ll*iv%P;
		}
		f[i][i]=(f[i-1][i-1]+1)%P;
	}
	cin>>T;
	while(T--){
		cin>>n>>m>>i;
		cout<<f[n][m]*1ll*i%P<<'\n';
	}
	return 0;
}