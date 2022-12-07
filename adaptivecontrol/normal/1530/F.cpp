#include<bits/stdc++.h>
using namespace std;
const int mod=31607,inv=3973;
int n,a[23][23],all,ans=1,b[23][23];
vector<int>V;
void dfs(int nw,vector<int>v,int res){
	if(nw==n){
		for(int i=0;i<n;i++)
			res=(res*(1-v[i])%mod+mod)%mod;
		ans=(ans+res+mod)%mod;return;
	}
	int NW=-res;
	for(int i=0;i<n;i++)
		NW=(NW*b[nw][i]%mod+mod)%mod;
	dfs(nw+1,v,NW);
	for(int i=0;i<n;i++)
		v[i]=v[i]*b[nw][i]%mod;
	dfs(nw+1,v,res);
}
int main(){
	scanf("%d",&n);all=(1<<n)-1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			a[i][j]=a[i][j]*inv%mod;
		}
	for(int i=0;i<n;i++)
		V.push_back(1);
	for(int MSK=0;MSK<4;MSK++){
		int nw=-1;
		if(MSK==1||MSK==2)nw=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				b[i][j]=a[i][j];
				if((MSK%2&&i==j)||(MSK/2&&i+j==n-1))
					nw=(nw*a[i][j]%mod+mod)%mod,
					b[i][j]=1;
			}
		dfs(0,V,nw);
	}
	cout<<ans;
}