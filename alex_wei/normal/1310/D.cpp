#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

const int N=80+5;
const int inf=1e9+7;

int n,k,e[N][N],f[N],tp[N],ans=inf;

int main(){
	cin>>n>>k,srand(time(0));
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>e[i][j];
	for(int T=1;T<=5000;T++,f[1]=0){
		for(int j=2;j<=n;j++)tp[j]=rand()&1,f[j]=inf;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)if((i&1)==tp[j]){
				f[j]=inf;
				for(int k=1;k<=n;k++)if((i&1)!=tp[k])
					f[j]=min(f[j],f[k]+e[k][j]);
			} ans=min(ans,f[1]);
	} cout<<ans<<endl;
	return 0;
}