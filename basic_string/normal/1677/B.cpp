#include<bits/stdc++.h>
using namespace std;
bool vis[1000009];
int h[1000009];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k,l,lie=0,las=-1e9;
	string s;
	cin>>T;
	while(T--){
		cin>>n>>m;lie=0;
		cin>>s;las=-1e9;
		for(i=0;i<=m;++i)vis[i]=0,h[i]=0;
		for(i=0;i<n*m;++i){
			if(s[i]=='1'){
				if(!vis[i%m])vis[i%m]=1,++lie;
				las=i;
			}
			if(i-las+1<=m)++h[i%m];
			cout<<lie+h[i%m]<<' ';
		}
		cout<<'\n';
	}
}