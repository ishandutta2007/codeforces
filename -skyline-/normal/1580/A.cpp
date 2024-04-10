#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,m,s[405][405],a[405][405],r[405][405],c[405][405],f[405][405],ans=orz;
int S[405][405],A[405][405],R[405][405],C[405][405];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		ans=orz;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				scanf("%1d",a[i]+j);
				A[i][j]=a[i][j]^1;
				s[i][j]=s[i-1][j]+s[i][j-1]+a[i][j]-s[i-1][j-1];
				r[i][j]=r[i][j-1]+a[i][j];
				c[i][j]=c[i-1][j]+a[i][j];
				
				S[i][j]=S[i-1][j]+S[i][j-1]+A[i][j]-S[i-1][j-1];
				R[i][j]=R[i][j-1]+A[i][j];
				C[i][j]=C[i-1][j]+A[i][j];
			}
		}
		for(int i=1;i<=m;++i){
			for(int j=i+1;j<=m;++j)f[i][j]=orz;
		}
		for(int x=5;x<=n;++x){
			for(int i=1;i<=m;++i){
				for(int j=i+3;j<=m;++j){
					f[i][j]=min(f[i][j]+r[x-1][j-1]-r[x-1][i]+2-a[x-1][i]-a[x-1][j],s[x-1][j-1]-s[x-1][i]-s[x-4][j-1]+s[x-4][i]+R[x-4][j-1]-R[x-4][i]+C[x-1][i]-C[x-4][i]+C[x-1][j]-C[x-4][j]);
					ans=min(ans,f[i][j]+R[x][j-1]-R[x][i]);
				}
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}