#include<bits/stdc++.h>
using namespace std;
int f[55][1029],inv[55],px[55][1029],py[55][1029],to[199],fi[13][55],se[13][55];
char s[13][109];
void get(int ax,int ay,int step){
	if(step>1)get(px[ax][ay],py[ax][ay],step-1);
	cout<<char(inv[ax]);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k,m=0,l,x,y,z,o,fl,ans,ax,ay;
	for(i='A';i<='Z';++i)to[i]=++m,inv[m]=i;
	for(i='a';i<='z';++i)to[i]=++m,inv[m]=i;
	for(cin>>T;T--;){
		cin>>n,ans=0;
		memset(f,-9,sizeof f);
		memset(fi,0,sizeof fi);
		memset(se,0,sizeof se);
		for(i=1;i<=n;++i){
			cin>>s[i]+1,k=strlen(s[i]+1);
			for(j=1;j<=k;++j){
				if(fi[i][to[s[i][j]]])se[i][to[s[i][j]]]=j;
				else fi[i][to[s[i][j]]]=j;
			}
		}
		for(i=1;i<=m;++i){
			for(j=1;j<=n;++j)if(fi[j][i]==0)goto gg;
			f[i][0]=1;
			ans=1,ax=i,ay=0;
			gg:;
		}
		o=1<<n;
		for(i=1,k=strlen(s[1]+1);i<=k;++i){
			l=to[s[1][i]];
			if(fi[1][l]==i)fl=0;else fl=1;
			for(j=0;j<o;++j)if((j&1)==fl&&f[l][j]>=0){
				for(x=1;x<=m;++x){
					z=0;
					for(y=1;y<=n;++y){
						if((j>>(y-1))&1){
							if(fi[y][x]>se[y][l]){}
							else if(se[y][x]>se[y][l])z|=1<<(y-1);
							else goto g2;
						}else{
							if(fi[y][x]>fi[y][l]){}
							else if(se[y][x]>fi[y][l])z|=1<<(y-1);
							else goto g2;
						}
					}
					if(f[x][z]<f[l][j]+1){
						f[x][z]=f[l][j]+1;
						if(f[x][z]>ans)ans=f[x][z],ax=x,ay=z;
						px[x][z]=l,py[x][z]=j;
					}
					g2:;
				}
			}
		}
		if(ans==0){
			cout<<ans<<'\n';
			cout<<'\n';
			continue;
		}
		cout<<ans<<'\n';
		get(ax,ay,ans);cout<<'\n';
	}
	return 0;
}
/*
2^10*52
52*10
5
*/